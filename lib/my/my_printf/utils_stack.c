/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Utilitary functions for the stack
*/

#include "../my.h"
#include "mylist.h"
#include <stdlib.h>

int my_putstr(char const *str);
void my_putchar(char c);
void suppr_node(stack_t **list);
int my_strlen(char const *str);

void my_put_in_list(stack_t **list, format_t data)
{
    stack_t *element;
    element = (stack_t *)malloc(sizeof(*element));
    element->flag = data;
    element->next = *list;
    *list = element;
}

int my_list_size(stack_t *begin)
{
    stack_t *tmp;
    int size = 0;

    tmp = begin;
    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return size;
}

void my_show_list(stack_t *list)
{
    while (list != NULL) {
        my_putstr(list->flag.id);
        my_putchar('\n');
        list = list->next;
    }
}

int find_hash(stack_t *stack)
{
    while (stack->next != NULL) {
        if (stack->next->flag.id[0] == '#') {
            suppr_node(&stack);
            return 1;
        }
        if (stack->next != NULL)
            stack = stack->next;
    }
    return 0;
}

int check_if_nb_neg(stack_t *stack)
{
    while (stack != NULL) {
        if (stack->flag.id[0] == '-' && my_strlen(stack->flag.id) != 1)
            return 1;
        stack = stack->next;
    }

    return 0;
}
