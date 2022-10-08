/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-guillaume.hein
** File description:
** utils_text_file_ant.c
*/

#include "my.h"
#include "antman_lyr.h"
#include <stdlib.h>

uint16_t *init_buffer(int size)
{
    uint16_t *buffer = malloc(sizeof(uint16_t) * (size + 1));
    if (buffer == NULL)
        return 0;
    for (int i = 0; i < size + 1; i++)
        buffer[i] = 0;
    return buffer;
}

int init_lyr_compressed(lyr_t *lyr, file_t *file, char **dict)
{
    size_t new_buffer_size = MAX(MIN(file->size, 10000), 100);
    lyr->buffer = malloc(sizeof(char) * new_buffer_size);
    if (lyr->buffer == NULL)
        return 0;
    lyr->buffer[0] = 0;
    lyr->buffer_size = new_buffer_size;
    lyr->buffer_pos = 0;
    lyr->char_buffer.nb = 0;
    lyr->shift_char = 0;
    lyr->dict = dict;
    lyr->file = file;
    return 1;
}

uint16_t read_char_lyr(lyr_t *lyr, char *content)
{
    if (lyr->shift_char > 7) {
        lyr->shift_char = 0;
        lyr->char_buffer.nb = 0;
        return 0;
    }
    lyr->char_buffer.str[1] = content[0];
    lyr->char_buffer.str[0] = content[1];
    lyr->char_buffer.nb >>= (7 - lyr->shift_char);
    lyr->char_buffer.nb &= (uint16_t)0b111111111;
    ++lyr->shift_char;
    return lyr->char_buffer.nb;
}

void empty_dict_compressed(char **dict)
{
    for (int i = 0; i < 256; ++i) {
        dict[i] = 0;
    }
}

void add_in_dict_compressed(lyr_t *lyr, char *str, int *pos)
{
    int len = my_strlen(str);
    if (len > 1) {
        lyr->dict[*pos] = init_str(len + 1);
        my_strcpy(lyr->dict[*pos], str);
        *pos = (*pos) + 1;
    }
}
