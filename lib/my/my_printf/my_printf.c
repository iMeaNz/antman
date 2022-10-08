/*
** EPITECH PROJECT, 2021
** MY_PRINTF
** File description:
** Printf
*/

#include <stdarg.h>
#include "../my.h"
#include "mylist.h"
#include "format.h"
#include <stdlib.h>

int compute_percent(char *str, va_list ap);
void my_putchar(char c);

int my_printf(char *str, ...)
{
    va_list ap;
    int i = 0;
    va_start(ap, str);
    for (; str[i] != '\0'; ++i) {
        if (str[i] == '%' && str[i + 1] != '%')
            i += compute_percent(&str[i + 1], ap);
        else if (str[i] == '%')
            my_putchar(str[i++]);
        else
            my_putchar(str[i]);
    }
    return i;
}
