/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** init_int_array.c
*/

#include <stdlib.h>

int *init_int_array(int size)
{
    int *output = malloc(sizeof(int) * (size + 1));
    for (int i = 0; i < size; i++)
        output[i] = 0;
    return output;
}
