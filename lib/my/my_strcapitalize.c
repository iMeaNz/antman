/*
** EPITECH PROJECT, 2021
** MY_STRCAPITALIZE
** File description:
** Function that capitalize each word in a string
*/

#include "my.h"

static int is_alpha_cap(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return -1;
    return 0;
}

static int is_num_cap(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else if (is_alpha(c) == -1)
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int in_a_word = 0;

    while (str[i] != '\0') {
        if (is_alpha_cap(str[i]) == -1 && !in_a_word) {
            str[i] -= 32;
            in_a_word = 1;
        } else if (is_alpha_cap(str[i]) == 1 && in_a_word) {
            str[i] += 32;
        } else {
            in_a_word = is_num(str[i]);
        }
        i++;
    }

    return str;
}
