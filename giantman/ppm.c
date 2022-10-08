/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** ppm
*/

#include "giantman_ppm.h"
#include "open_file.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *my_strtok(char *string, char *delimiters);

void write_to_buffer(ppm_t *ppm, char *str)
{
    if (ppm->buffer_pos + my_strlen(str) >= ppm->buffer_size) {
        write(1, ppm->buffer, ppm->buffer_pos);
        ppm->buffer_pos = 0;
    }
    for (int i = 0 ; str[i] != '\0' ; i++) {
        ppm->buffer[ppm->buffer_pos++] = str[i];
    }
}

uint16_t read_char(ppm_t *ppm, char *content)
{
    if (ppm->shift_char > 7) {
        ppm->shift_char = 0;
        ppm->char_buffer.nb = 0;
        return 0;
    }
    ppm->char_buffer.str[1] = content[0];
    ppm->char_buffer.str[0] = content[1];
    ppm->char_buffer.nb >>= (7 - ppm->shift_char);
    ppm->char_buffer.nb &= (uint16_t)0b111111111;
    ++ppm->shift_char;
    return ppm->char_buffer.nb;
}

void init_ppm(ppm_t *ppm, file_t *file)
{
    size_t new_buffer_size = MAX(MIN(file->size, 10000), 100);
    ppm->buffer = malloc(sizeof(char) * new_buffer_size);
    ppm->buffer[0] = 0;
    ppm->buffer_size = new_buffer_size;
    ppm->buffer_pos = 0;
    ppm->char_buffer.str[1] = file->content[0];
    ppm->char_buffer.str[0] = file->content[1];
    ppm->shift_char = 0;
}

char *convert_nb_to_str(uint16_t nb, char *result)
{
    int remainder;
    int i = 0;

    if (nb == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    for (; i < 3 && nb > 0 ; ++i) {
        remainder = nb % 10;
        nb /= 10;
        result[i] = '0' + remainder;
    }
    for (; i < 3 ; ++i)
        result[i] = '\0';
    my_revstr(result);
    return result;
}

int parse_ppm_compressed(file_t *file)
{
    ppm_t *ppm = malloc(sizeof(ppm_t));
    if (ppm == NULL)
        return 84;
    init_ppm(ppm, file);
    uint16_t current_char;
    char to_nbr[] = "000";
    char tmp_str[] = "a";
    for (size_t i = 0 ; i < file->size - 1 ; ++i) {
        current_char = read_char(ppm, &file->content[i]);
        if (IS_RGB_TYPE(current_char)) {
            current_char &= ~(1 << 8);
            write_to_buffer(ppm, convert_nb_to_str(current_char, to_nbr));
            write_to_buffer(ppm, "\n");
        } else {
            tmp_str[0] = current_char;
            write_to_buffer(ppm, tmp_str);
        }
    }
    write(1, ppm->buffer, ppm->buffer_pos);
    return 0;
}
