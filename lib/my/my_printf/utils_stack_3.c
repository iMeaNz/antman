/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** utils_stack_3.c
*/

#include "mylist.h"
#include <stdlib.h>

void suppr_node(stack_t **list);

int find_l_flags(stack_t **st)
{
    stack_t *ptr = *st;
    int nb_l = 0;

    while (ptr->next != NULL) {
        if (ptr->next->flag.id[0] == 'l') {
            nb_l++;
            suppr_node(&ptr);
        }
        if (ptr->next != NULL)
            ptr = ptr->next;
    }
    if (nb_l > 2)
        return -1;
    else
        return nb_l;
}
