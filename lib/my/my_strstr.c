/*
** EPITECH PROJECT, 2021
** MY_STRSTR
** File description:
** Function that find a substring in another
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int length = my_strlen(to_find);

    if (length == 0)
        return str;
    while (str[i] != '\0') {
        if (my_strncmp(&str[i], to_find, length) == 0) {
            return &str[i];
        }
        i++;
    }
    return 0;
}
