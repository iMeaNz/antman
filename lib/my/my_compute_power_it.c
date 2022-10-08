/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_POWER_REC
** File description:
** Function that calcultates a power the recursive way
*/

int my_compute_power_it(int nb, int p)
{
    long int result = 1;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    for (int i = 0; i < p; i++)
        result *= nb;
    if (result > 2147483647)
        return 0;

    return (int)result;
}
