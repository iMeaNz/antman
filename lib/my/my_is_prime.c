/*
** EPITECH PROJECT, 2021
** MY_IS_PRIME
** File description:
** Finds if a number is prime
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb <= 5)
        return nb > 1 && nb != 4;
    if (nb % 2 == 0 || nb % 3 == 0)
        return 0;
    for (int i = 6; my_compute_power_it(i - 6, 2) <= nb; i += 6) {
        if (nb % (i - 1) == 0 || nb % (i + 1) == 0) {
            return 0;
        }
    }
    return 1;
}
