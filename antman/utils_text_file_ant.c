/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-guillaume.hein
** File description:
** utils_text_file_ant.c
*/

#include "my.h"
#include "antman_lyr.h"
#include <stdlib.h>
#include <stdio.h>

int init_lyr(lyr_t *lyr, file_t *file, char **dict)
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

void write_char_lyr(lyr_t *lyr, uint16_t value)
{
    value = 0 | value;
    if (lyr->buffer_pos + 2 > lyr->buffer_size) {
        write(1, lyr->buffer, lyr->buffer_pos);
        lyr->buffer_pos = 0;
    }
    if (lyr->shift_char > 7) {
        lyr->buffer[lyr->buffer_pos++] = lyr->char_buffer.str[0];
        lyr->shift_char = 0;
        lyr->char_buffer.nb = 0;
    }
    lyr->char_buffer.str[1] = lyr->char_buffer.str[0];
    lyr->char_buffer.str[0] = 0;
    value <<= 7;
    lyr->char_buffer.nb |= value >> lyr->shift_char++;
    lyr->buffer[lyr->buffer_pos++] = lyr->char_buffer.str[1];
}

int find_pos_in_dict(lyr_t *lyr, char *str)
{
    for (int i = 0; i < 256; i++) {
        if (my_strcmp(lyr->dict[i], str) == 0)
            return i;
    }
    return -1;
}

void add_in_dict(lyr_t *lyr, char *str, int *pos, char *tmp)
{
    int len = my_strlen(tmp);
    if (str != 0 && my_strlen(str) > 1) {
        lyr->dict[*pos] = init_str(my_strlen(str) + 1);
        my_strcpy(lyr->dict[*pos], str);
        (*pos) = (*pos) + 1;
    }

    if (len != 0) {
        int pos_dico = find_pos_in_dict(lyr, tmp);
        if (len > 1)
            write_char_lyr(lyr, pos_dico + 256);
        else
            write_char_lyr(lyr, (unsigned char)tmp[0]);
    }
}

void empty_dict(char **dict, lyr_t *lyr)
{
    for (int i = 0; i < 256; ++i) {
        dict[i] = 0;
    }
    write_char_lyr(lyr, 256);
}
