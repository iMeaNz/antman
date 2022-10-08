/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-guillaume.hein
** File description:
** text_fike.c
*/

#include "open_file.h"
#include "my.h"
#include "antman_lyr.h"
#include <unistd.h>
#include <stdlib.h>

void add_in_dict(lyr_t *lyr, char *str, int *pos, char *tmp);
void empty_dict(char **dict, lyr_t *lyr);
void write_char_lyr(lyr_t *lyr, uint16_t value);
int init_lyr(lyr_t *lyr, file_t *file, char **dict);
void copy_and_cat(char *tmp, char *concat, char *str);
void copy_and_free(char *tmp, char *str);

int check_in_dict(lyr_t *lyr, char *concat)
{
    for (int i = 1; i < 256; i++) {
        if (lyr->dict[i] == 0)
            return 0;
        if (my_strcmp(lyr->dict[i], concat) == 0)
            return 1;
    }
    return -1;
}

void handle_emptying_dict(lyr_t *lyr, int *pos_dico, char *tmp)
{
    *pos_dico = 1;
    add_in_dict(lyr, 0, 0, tmp);
    empty_dict(lyr->dict, lyr);
    free(tmp);
}

int manipulate_dict(lyr_t *lyr, int *pos_dico, char *tmp, char *concat)
{
    if (check_in_dict(lyr, concat)) {
        free(tmp);
        return 0;
    } else {
        add_in_dict(lyr, concat, pos_dico, tmp);
        free(tmp);
        free(concat);
        return 1;
    }
}

void fill_dict(file_t *file, lyr_t *lyr)
{
    char *tmp = init_str(1);
    int pos_dico = 1;
    for (int i = 0; i < (int)file->size; i++) {
        if (pos_dico == 255) {
            handle_emptying_dict(lyr, &pos_dico, tmp);
            tmp = init_str(1);
        }
        char *str = init_str(2);
        str[0] = file->content[i];
        char *concat = init_str(my_strlen(tmp) + my_strlen(str));
        copy_and_cat(tmp, concat, str);
        if (manipulate_dict(lyr, &pos_dico, tmp, concat)) {
            tmp = init_str(my_strlen(str));
            copy_and_free(tmp, str);
        } else {
            tmp = init_str(my_strlen(concat));
            copy_and_free(tmp, concat);
        }
    }
    add_in_dict(lyr, 0, 0, tmp);
}

int parse_text_file(file_t *file)
{
    char **dict = init_str_array(256);
    lyr_t *lyr = malloc(sizeof(lyr_t));
    if (lyr == NULL || dict == NULL)
        return 84;
    if (!init_lyr(lyr, file, dict))
        return 84;
    fill_dict(file, lyr);
    write(1, lyr->buffer, lyr->buffer_pos);
    write(1, &lyr->char_buffer.str[0], 1);
    return 0;
}
