/*
** EPITECH PROJECT, 2021
** FLAGS
** File description:
** Utils function for the flags
*/

#include "../my.h"
#include "format.h"
#include <stdlib.h>

format_t *create_array_struct(void)
{
    static format_t output[17] = {
        {"d", 1, -1, -1},
        {"i", 1, -1, -1},
        {"o", 1, -1, -1},
        {"x", 1, -1, -1},
        {"X", 1, -1, -1},
        {"u", 1, -1, -1},
        {"c", 1, -1, -1},
        {"s", 1, -1, -1},
        {"p", 1, -1, -1},
        {"b", 1, -1, -1},
        {"S", 1, -1, -1},
        {"-", 0, 1, -1},
        {"0", 2, 0, -1},
        {"+", 3, -1, 1},
        {" ", 3, -1, 0},
        {"#", -1, -1, -1},
        {0, 0, 0, 0}
    };
    return output;
}
