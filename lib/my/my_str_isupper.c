/*
** EPITECH PROJECT, 2021
** MY_STR_ISUPPER
** File description:
** Checks if a string contains only uppercase
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_upper(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
