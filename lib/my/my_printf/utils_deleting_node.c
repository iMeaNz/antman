/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Utilitary function to delete nodes
*/

#include "../my.h"
#include "mylist.h"
#include <stdlib.h>

stack_t *my_find_next_node(stack_t *list, void const *data_ref, int (*cmp)())
{
    while (list->next != NULL && (*cmp)(list->next->flag.id, data_ref) == 0) {
        stack_t *to_suppr = list;
        list = list->next;
        free(to_suppr);
    }

    return list->next;
}

void suppr_node(stack_t **list)
{
    stack_t *tmp = *list;
    stack_t *next = tmp->next->next;
    free(tmp->next);
    tmp->next = next;
}

int my_delete_nodes(stack_t **begin, void const *data_ref, int (*cmp)())
{
    stack_t *ptr;

    if (*begin == NULL)
        return 0;

    if ((*cmp)((*begin)->flag.id, data_ref) == 0) {
        (*begin) = my_find_next_node(*begin, data_ref, cmp);
    }
    ptr = *begin;
    while (ptr != NULL) {
        if (ptr->next != NULL && (*cmp)(ptr->next->flag.id, data_ref) == 0) {
            ptr->next = my_find_next_node(ptr->next, data_ref, cmp);
        }
        ptr = ptr->next;
    }

    return 0;
}

void remove_duplicates(stack_t **list)
{
    int (*ptr_cmp)(char const *, char const *) = &my_strcmp;
    stack_t *ptr = *list;

    while (ptr != NULL) {
        char *ref = ptr->flag.id;
        my_delete_nodes(&ptr->next, ref, ptr_cmp);
        ptr = ptr->next;
    }
}
