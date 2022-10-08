/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** ppm
*/

#include "antman_ppm.h"
#include "open_file.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char *my_strtok(char *string, char *delimiters);

void write_char(ppm_t *ppm, uint16_t value)
{
    value = 0 | value;
    if (ppm->buffer_pos + 2 > ppm->buffer_size) {
        write(1, ppm->buffer, ppm->buffer_pos);
        ppm->buffer_pos = 0;
    }
    if (ppm->shift_char > 7) {
        ppm->buffer[ppm->buffer_pos++] = ppm->char_buffer.str[0];
        ppm->shift_char = 0;
        ppm->char_buffer.nb = 0;
    }
    ppm->char_buffer.str[1] = ppm->char_buffer.str[0];
    ppm->char_buffer.str[0] = 0;
    value <<= 7;
    ppm->char_buffer.nb |= value >> ppm->shift_char++;
    ppm->buffer[ppm->buffer_pos++] = ppm->char_buffer.str[1];
}

int init_ppm(ppm_t *ppm, file_t *file)
{
    size_t new_buffer_size = MAX(MIN(file->size, 10000), 100);
    ppm->buffer = malloc(sizeof(char) * new_buffer_size);
    if (ppm->buffer == NULL)
        return 0;
    ppm->buffer[0] = 0;
    ppm->buffer_size = new_buffer_size;
    ppm->buffer_pos = 0;
    ppm->char_buffer.nb = 0;
    ppm->shift_char = 0;
    return 1;
}

void parse_line(ppm_t *ppm, char *line)
{
    if (my_strlen(line) <= 3 && my_str_isnum(line)) {
        int nb = my_getnbr(line);
        if (nb <= 255) {
            write_char(ppm, nb + 256);
            return;
        }
    }
    for (size_t i = 0 ; line[i] != '\0' ; ++i)
        write_char(ppm, line[i]);
    write_char(ppm, '\n');

}

int parse_ppm(file_t *file)
{
    ppm_t *ppm = malloc(sizeof(ppm_t));
    if (ppm == NULL)
        return 84;
    if (!init_ppm(ppm, file))
        return 84;
    char *token = my_strtok(file->content, "\n");
    for (int i = 0 ; token != NULL ; ++i) {
        parse_line(ppm, token);
        token = my_strtok(NULL, "\n");
    }
    write(1, ppm->buffer, ppm->buffer_pos);
    write(1, &ppm->char_buffer.str[0], 1);
    return 0;
}
