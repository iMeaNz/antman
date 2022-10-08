/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR
** File description:
** Function that prints an int
*/
#include "my.h"
#include <unistd.h>

int my_put_nbr(int nb)
{
    int modulo = 0;

    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    modulo = nb % 10 + '0';
    nb /= 10;
    if (nb > 0)
        my_put_nbr(nb);
    my_putchar(modulo);
}
