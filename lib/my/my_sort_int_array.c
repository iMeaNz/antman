/*
** EPITECH PROJECT, 2021
** MY_SORT_INT_ARRAY
** File description:
** Function that sorts an array of int
*/

#include "my.h"

static void compare_number(int *array, int *is_sorted, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (array[i + 1] < array[i]) {
            my_swap(&array[i], &array[i + 1]);
            *is_sorted = 0;
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    int is_sorted = 0;
    while (!is_sorted) {
        is_sorted = 1;
        compare_number(array, &is_sorted, size);
    }
}
