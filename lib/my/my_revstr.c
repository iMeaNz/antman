/*
** EPITECH PROJECT, 2021
** MY_REVSTR
** File description:
** Function that reverses a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length / 2; i++) {
        my_swap_char(&str[i], &str[length - i - 1]);
    }

    return str;
}
