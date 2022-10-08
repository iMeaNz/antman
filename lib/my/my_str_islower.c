/*
** EPITECH PROJECT, 2021
** MY_STR_ISLOWER
** File description:
** Checks if a string contains only lowercase
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_lower(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
