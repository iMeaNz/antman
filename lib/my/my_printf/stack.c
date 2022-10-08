/*
** EPITECH PROJECT, 2021
** STACK
** File description:
** Utils function for the linked list
*/

#include <stdarg.h>
#include "../my.h"
#include "mylist.h"
#include "format.h"
#include <stdlib.h>

void suppr_node(stack_t **list);
char *handle_hexa(va_list ap, char *base, int is_hash);
char *handle_octal(va_list ap, char *base, int is_hash);
char *handle_binary(va_list ap, char *base);
char *handle_unsigned_decimal(va_list ap);
char *handle_decimal(va_list ap, int *is_special);
int my_strlen(char const *str);
char *find_base(char c);
char *my_put_printable_str(char *str);
char *my_print_pointer(unsigned long long x);
int is_an_id(char c);

int remove_lower_before_number(stack_t **begin)
{
    stack_t *ptr = *begin;;
    int highest_prio = -1;

    while (ptr != NULL) {
        if (ptr->flag.priority_before_number > highest_prio)
            highest_prio = ptr->flag.priority_before_number;
        ptr = ptr->next;
    }
    if (highest_prio == -1)
        return 0;
    ptr = *begin;
    while (ptr->next != NULL) {
        int prio_ptr = ptr->next->flag.priority_before_number;
        if (prio_ptr != -1 && prio_ptr < highest_prio)
            suppr_node(&ptr);
        if (ptr->next != NULL)
            ptr = ptr->next;
    }
    return 1;
}

char *compute_base(char *base, int is_hash, int *is_special, va_list ap)
{
    int len_base = my_strlen(base);

    if (len_base == 16) {
        char *new_nb = handle_hexa(ap, base, is_hash);
        *is_special = 1;
        return new_nb;
    } else if (len_base == 8) {
        char *new_nb = handle_octal(ap, base, is_hash);
        *is_special = 1;
        return new_nb;
    }
    if (len_base == 2) {
        char *new_nb = handle_binary(ap, base);
        *is_special = 1;
        return new_nb;
    }
    char *new_nb = handle_decimal(ap, is_special);
    return new_nb;
}

int compute_number(stack_t **ptr, va_list ap, int is_hash, int *is_special)
{
    char id = (*ptr)->flag.id[0];
    char *base = find_base(id);
    char *new_nb = compute_base(base, is_hash, is_special, ap);
    (*ptr)->flag.id = new_nb;
    return my_strlen(new_nb);
}

int compute_strings(stack_t **ptr, va_list ap, int *is_special, char id)
{
    if (id == 's') {
        (*is_special) = 1;
        (*ptr)->flag.id = va_arg(ap, char *);
    }
    if (id == 'c') {
        (*is_special) = 1;
        char to_add = va_arg(ap, int);
        (*ptr)->flag.id = malloc(sizeof(char) * 2);
        (*ptr)->flag.id[0] = to_add;
        (*ptr)->flag.id[1] = '\0';
    }
    if (id == 'S') {
        (*is_special) = 1;
        (*ptr)->flag.id = my_put_printable_str(va_arg(ap, char *));
    }
    if (id == 'p')
        (*ptr)->flag.id = my_print_pointer(va_arg(ap, unsigned long long));
    return my_strlen((*ptr)->flag.id);
}

int replace_identifier(stack_t **st, va_list ap, int is_hash, int *is_special)
{
    stack_t *ptr = *st;
    while (ptr != NULL && !is_an_id(ptr->flag.id[0])) {
        ptr = ptr->next;
    }

    char id = ptr->flag.id[0];
    if (is_an_id(id) == 1)
        return compute_number(&ptr, ap, is_hash, is_special);
    else if (id == 'u') {
        char *new_nb = handle_unsigned_decimal(ap);
        ptr->flag.id = new_nb;
        return my_strlen(new_nb);
    } else
        return compute_strings(&ptr, ap, is_special, id);
}
