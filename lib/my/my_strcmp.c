/*
** EPITECH PROJECT, 2021
** MY_STRCMP
** File description:
** Compares two strings
*/

#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return -1;

    while (s1[i] != '\0' && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}
