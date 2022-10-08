/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-guillaume.hein
** File description:
** text_file.c
*/

#include "open_file.h"
#include "my.h"
#include "antman_lyr.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void add_in_dict_compressed(lyr_t *lyr, char *str, int *pos);
void empty_dict_compressed(char **dict);
int init_lyr_compressed(lyr_t *lyr, file_t *file, char **dict);
uint16_t read_char_lyr(lyr_t *lyr, char *content);
uint16_t *init_buffer(int size);
void write_to_buffer_text(lyr_t *lyr, char *str);

char *get_str_from_number(lyr_t *lyr, uint16_t nb, char *tmp)
{
    char *str;

    if (nb < 256) {
        str = init_str(2);
        str[0] = nb;
        return str;
    } else if (lyr->dict[nb - 256] != 0) {
        str = init_str(my_strlen(lyr->dict[nb - 256]) + 1);
        my_strcpy(str, lyr->dict[nb - 256]);
        return str;
    } else {
        str = init_str(my_strlen(tmp) + 2);
        my_strcpy(str, tmp);
        str[my_strlen(tmp)] = tmp[0];
        return str;
    }
}

void handle_emptying_dict(lyr_t *lyr, int *pos_dico, char *tmp)
{
    empty_dict_compressed(lyr->dict);
    *pos_dico = 1;
    tmp[0] = 0;
}

void handle_get_and_print_str(char *str, lyr_t *lyr, uint16_t nb, char *tmp)
{
    free(str);
    str = get_str_from_number(lyr, nb, tmp);
    write_to_buffer_text(lyr, str);
}

void decode_lzw(lyr_t *lyr, uint16_t *buffer, int size)
{
    char *tmp = get_str_from_number(lyr, buffer[0], 0);
    char *str = get_str_from_number(lyr, buffer[0], 0);
    write_to_buffer_text(lyr, str);
    int pos_dico = 1;
    for (int i = 1; i < size; i++) {
        if (buffer[i] == 256) {
            handle_emptying_dict(lyr, &pos_dico, tmp);
            continue;
        }
        handle_get_and_print_str(str, lyr, buffer[i], tmp);
        str = get_str_from_number(lyr, buffer[i], tmp);
        char *to_add = init_str(my_strlen(tmp) + 2);
        my_strcpy(to_add, tmp);
        to_add[my_strlen(tmp)] = str[0];
        add_in_dict_compressed(lyr, to_add, &pos_dico);
        free(tmp);
        tmp = init_str(my_strlen(str) + 1);
        my_strcpy(tmp, str);
        free(to_add);
    }
}

int parse_text_compressed(file_t *file)
{
    char **dict = init_str_array(256);
    lyr_t *lyr = malloc(sizeof(lyr_t));
    if (lyr == NULL)
        return 84;
    if (!init_lyr_compressed(lyr, file, dict))
        return 84;
    uint16_t *buffer = init_buffer(file->size);
    if (buffer == 0)
        return 84;
    int pos = 0;

    for (int i = 0; i < (int)file->size; ++i) {
        uint16_t nb = read_char_lyr(lyr, &file->content[i]);
        if (nb != 0)
            buffer[pos++] = nb;
    }
    decode_lzw(lyr, buffer, pos);
    write(1, lyr->buffer, lyr->buffer_pos);
    return 0;
}
