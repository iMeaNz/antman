/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** init_str.c
*/

#include <stdlib.h>

char *init_str(int size)
{
    char *output = malloc(sizeof(char) * size + 1);
    for (int i = 0; i < size; i++)
        output[i] = 0;
    return output;
}
