/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Utilitary functions for stack 2
*/

#include "mylist.h"
#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int is_an_id(char c);

int is_a_float(char *fw)
{
    for (int i = 0; fw[i] != '\0'; i++) {
        if (fw[i] == '.')
            return 1;
    }
    return 0;
}

int get_nb_before_comma(char *fw)
{
    for (int i = 0; fw[i] != '\0'; i++) {
        if (fw[i] == '.') {
            char *to_return = malloc(sizeof(char) * i);
            my_strncpy(to_return, fw, i);
            return my_getnbr(to_return);
        }
    }
    return 0;
}

int get_nb_after_comma(char *fw)
{
    int index_comma = 0;
    int len = my_strlen(fw);

    for (int i = 0; fw[i] != '\0'; i++) {
        if (fw[i] == '.')
            index_comma = i;
    }
    char *to_return = malloc(sizeof(char) * (len - index_comma));
    my_strncpy(to_return, &fw[index_comma + 1], len - index_comma - 1);
    return my_getnbr(to_return);
}

int *split_fw(char *fw_str, int *array)
{
    if (is_a_float(fw_str)) {
        array[0] = get_nb_before_comma(fw_str);
        array[1] = get_nb_after_comma(fw_str);
    } else {
        array[0] = my_getnbr(fw_str);
        array[1] = 0;
    }
    return array;
}

int find_id_number(stack_t *st)
{
    while (st != NULL) {
        if (is_an_id(st->flag.id[0]) == 1)
            return 1;
        st = st->next;
    }
    return 0;
}
