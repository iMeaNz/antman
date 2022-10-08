/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-guillaume.hein
** File description:
** utils_str.c
*/

#include "my.h"
#include <stdlib.h>

void copy_and_cat(char *tmp, char *concat, char *str)
{
    my_strcpy(concat, tmp);
    my_strcat(concat, str);
}

void copy_and_free(char *tmp, char *str)
{
    my_strcpy(tmp, str);
    free(str);
}
