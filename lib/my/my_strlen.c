/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** Function that returns the length of a string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
