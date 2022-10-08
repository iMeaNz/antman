/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_SQUARE_ROOT
** File description:
** Function that calculates the square root of a number
*/

static int check_result(int result, int nb)
{
    if (result * result == nb)
        return result;
    else
        return 0;
}

int my_compute_square_root(int nb)
{
    int result = nb / 2;

    if (nb <= 1)
        return nb == 1;
    for (int i = 0; i < 1000; i++)
        result = (result + (nb / result)) / 2;

    return check_result(result, nb);
}
