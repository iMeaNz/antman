/*
** EPITECH PROJECT, 2021
** MYLIST
** File description:
** Struct for the day11
*/

#include "format.h"

#ifndef MYLIST_H
    #define MYLIST_H

typedef struct stack {
    format_t flag;
    struct stack *next;
} stack_t;
#endif
