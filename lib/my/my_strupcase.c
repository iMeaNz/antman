/*
** EPITECH PROJECT, 2021
** MY_STRUPCASE
** File description:
** Put every letter of every word in uppercase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return str;
}
