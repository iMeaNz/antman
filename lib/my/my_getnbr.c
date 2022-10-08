/*
** EPITECH PROJECT, 2021
** MY_GETNBR
** File description:
** Function that returns an int based on a string
*/

#include "my.h"

static int my_true_len(char const *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] != '\0') {
        if (str[i] > '9') {
            return counter;
        }
        if (str[i] >= '0') {
            counter++;
        }
        i++;
    }
    return counter;
}

static int my_str_isneg(char const *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            counter++;
        i++;
    }
    if (counter % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}

static int my_decimal_pow(int p)
{
    int pow = 1;

    for (int i = 0; i < p; i++)
        pow *= 10;
    return pow;
}

int my_getnbr(char const *str)
{
    int true_len = my_true_len(str);
    int len = my_strlen(str);
    long long int number = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] > '9' || true_len == 0 || true_len > 10) {
            break;
        } else if (str[i] <= '9' && str[i] >= '0') {
            number += (str[i] - '0') * my_decimal_pow(true_len - 1);
            true_len--;
        }
    }
    if (my_str_isneg(str))
        number *= -1;
    if (number < -2147483648 || number > 2147483647)
        return 0;

    return (int)number;
}
