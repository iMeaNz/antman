/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Function to sort stack
*/

#include "../my.h"
#include "mylist.h"
#include <stdlib.h>

int my_list_size(stack_t *begin);

stack_t *my_swap_node(stack_t *ptr)
{
    stack_t *tmp;
    stack_t *new_ptr;

    new_ptr = ptr->next;
    tmp = ptr->next->next;
    ptr->next->next = ptr;
    ptr->next = tmp;
    return new_ptr;
}

void check_if_swap(stack_t **ptr, int *sorted)
{
    if ((*ptr)->next->flag.prio_print < (*ptr)->next->next->flag.prio_print) {
        (*ptr)->next = my_swap_node((*ptr)->next);
        *sorted = 0;
    }
}

void my_sort_list(stack_t **st)
{
    int sorted = 0;
    stack_t *ptr;

    if (my_list_size(*st) <= 1)
        return;

    while (!sorted) {
        sorted = 1;
        if ((*st)->flag.prio_print < (*st)->next->flag.prio_print)
            *st = my_swap_node(*st);
        ptr = *st;
        while (ptr->next->next != NULL) {
            check_if_swap(&ptr, &sorted);
            ptr = ptr->next;
        }
    }
}
