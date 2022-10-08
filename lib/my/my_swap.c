/*
** EPITECH PROJECT, 2021
** MY_SWAP
** File description:
** Function that swaps two int
*/

void my_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
