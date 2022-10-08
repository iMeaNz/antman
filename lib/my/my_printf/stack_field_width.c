/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Function used to compute field width
*/

#include "../my.h"
#include "mylist.h"
#include <stdlib.h>

int is_a_num(char c);
int my_getnbr(char const *str);
void suppr_node(stack_t **list);

char *find_field_width(stack_t **list)
{
    stack_t *ptr = *list;

    while (ptr->next != NULL) {
        if (ptr->next->flag.id[0] != '0' && is_a_num(ptr->next->flag.id[0])) {
            int len = my_strlen(ptr->next->flag.id);
            char *fw = malloc(sizeof(char) * len + 1);
            my_strcpy(fw, ptr->next->flag.id);
            suppr_node(&ptr);
            return fw;
        }
        if (ptr->next != NULL)
            ptr = ptr->next;
    }
    char *fw = malloc(sizeof(char) * 2);
    fw[0] = '0';
    return fw;
}

int remove_lower_field_width(stack_t **begin)
{
    stack_t *ptr = *begin;
    int highest_prio = -1;

    while (ptr != NULL) {
        if (ptr->flag.priority_field_width > highest_prio)
            highest_prio = ptr->flag.priority_field_width;
        ptr = ptr->next;
    }
    if (highest_prio == -1)
        return 0;
    ptr = *begin;
    while (ptr->next != NULL) {
        int prio_ptr = ptr->next->flag.priority_field_width;
        if (prio_ptr != -1 && prio_ptr < highest_prio)
            suppr_node(&ptr);
        if (ptr->next != NULL)
            ptr = ptr->next;
    }
    return highest_prio;
}
