/*
** EPITECH PROJECT, 2021
** lib-epitech
** File description:
** init_matrix.c
*/

#include <stdlib.h>

int **init_matrix(int nb_line, int nb_col)
{
    int **output = malloc(sizeof(int *) * (nb_line + 1));
    for (int i = 0; i < nb_line; i++) {
        output[i] = malloc(sizeof(int) * (nb_col + 1));
        for (int j = 0; j < nb_col; j++)
            output[i][j] = 0;
    }
    return output;
}
