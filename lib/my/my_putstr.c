/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** Prints a string
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int len = my_strlen(str);
    write(1, str, len);
}
