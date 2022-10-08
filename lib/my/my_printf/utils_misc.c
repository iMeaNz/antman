/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Misc utilitary function
*/

#include <unistd.h>

int check_if_float(char *float_str);
char *my_strncpy(char *dest, char const *src, int n);

int size_nbr(int nbr, int len_base)
{
    int size = 0;

    while (nbr != 0) {
        nbr /= len_base;
        size++;
    }

    return size;
}

int size_unsigned_nbr(unsigned int nbr, int len_base)
{
    int size = 0;

    while (nbr != 0) {
        nbr /= len_base;
        size++;
    }

    return size;
}

int size_float_without_comma(char *float_str)
{
    int i = 0;
    while (float_str[i] != '.') {
        i++;
    }

    return i;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
