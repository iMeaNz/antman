/*
** EPITECH PROJECT, 2021
** MY_FIND_PRIME_SUP
** File description:
** Find the first prime number superior
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    while (1) {
        if (my_is_prime(nb) == 1)
            return nb;
        nb++;
    }
}
