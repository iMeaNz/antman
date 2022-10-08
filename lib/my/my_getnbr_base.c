/*
** EPITECH PROJECT, 2021
** MY_GETNBR_BASE
** File description:
** Convert a number in a given into a decimal number
*/

#include "my.h"

static int search_in_base(char const *base, char to_find)
{
    int i = 0;

    while (base[i] != '\0') {
        if (base[i] == to_find) {
            return i;
        }
        i++;
    }
    return -1;
}

static int my_nb_isneg(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            count++;
        }
        i++;
    }
    if (count % 2 == 0)
        return 0;
    else
        return 1;
}

int helper(char carac, char const *base, long int *nbr, int *size_nbr)
{
    int index = search_in_base(base, carac);
    int base_type = my_strlen(base);

    if (index == -1) {
        if (carac != '-' && carac != '+')
            return 0;
        else
            (*size_nbr)--;
    } else {
        (*nbr) += (index) * my_compute_power_it(base_type, (*size_nbr) - 1);
        (*size_nbr)--;
    }
    return 1;
}

int my_getnbr_base(char const *str, char const *base)
{
    long int nbr = 0;
    int base_type = my_strlen(base), size_nbr = my_strlen(str);
    for (int i = 0; str[i] != '\0'; i++) {
        int index = search_in_base(base, str[i]);
        helper(str[i], base, &nbr, &size_nbr);
    }
    nbr *= (my_nb_isneg(str)) ? -1 : 1;
    if (nbr > 2147483647 || nbr < -2147483648)
        return 0;
    return (int)nbr;
}
