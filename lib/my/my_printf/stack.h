/*
** EPITECH PROJECT, 2021
** STACK
** File description:
** Struct for the printable str
*/

#ifndef MYLIST_H
    #define MYLIST_H

typedef struct stack_printable {
    char *str;
    struct stack_printable *next;
} stack_printable_t;
#endif
