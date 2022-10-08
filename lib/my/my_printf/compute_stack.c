/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Print the stack
*/

#include "../my.h"
#include <stdlib.h>
#include "mylist.h"

int is_a_flag(char c);
int my_strlen(char const *str);
int my_put_chars(int nb, char c);
void my_putchar(char c);
int check_if_nb_neg(stack_t *stack);
int my_strlen(char const *str);
int my_putstr(char const *str);
void compute_blank_sign(stack_t *stack, int *array_fw, int is_number);
void compute_neg_sign(stack_t *stack, int *array_fw, int is_number);
void compute_positive_sign(stack_t *st, int *array_fw, int is_number);
void compute_zero_sign(stack_t *stack, int *array_fw, int is_number);

void increment_stack(stack_t **stack)
{
    while (is_a_flag((*stack)->flag.id[0])) {
        if (my_strlen((*stack)->flag.id) != 1)
            break;
        else
            (*stack) = (*stack)->next;
    }
}

int find_char(stack_t *st, char c)
{
    while (st != NULL) {
        if (st->flag.id[0] == c && my_strlen(st->flag.id) == 1)
            return 1;
        st = st->next;
    }
    return 0;
}

int find_zero_sign(stack_t *st)
{
    while (st != NULL) {
        if (st->flag.id[0] == '0' && st->next != NULL)
            return 1;
        st = st->next;
    }
    return 0;
}

int compute_sub_flags(stack_t *stack, int *array_fw, int is_number)
{
    if (find_char(stack, '+')) {
        compute_positive_sign(stack, array_fw, is_number);
        return 1;
    }
    if (find_char(stack, ' ')) {
        compute_blank_sign(stack, array_fw, is_number);
        return 1;
    }
    if (find_zero_sign(stack)) {
        compute_zero_sign(stack, array_fw, is_number);
        return 1;
    }
    if (find_char(stack, '-')) {
        compute_neg_sign(stack, array_fw, is_number);
        return 1;
    }
    return 0;
}

void print_stack(stack_t *stack, int is_number, int *array_fw, int is_special)
{
    if (compute_sub_flags(stack, array_fw, is_number))
        return;
    if (array_fw[0] != 0)
        my_put_chars(array_fw[0], ' ');
    if (array_fw[1] > 0 && is_number)
        my_put_chars(array_fw[1], '0');
    my_putstr(stack->flag.id);
    return;
}
