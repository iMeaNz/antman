/*
** EPITECH PROJECT, 2021
** MY_PUTCHAR
** File description:
** Print a char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
