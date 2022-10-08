/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** is_alpha.c
*/

int is_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}
