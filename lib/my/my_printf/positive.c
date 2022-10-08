/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Compute positive sign
*/

#include "mylist.h"

int check_if_nb_neg(stack_t *stack);
int my_put_chars(int nb, char c);
void my_putchar(char c);
void increment_stack(stack_t **stack);
int my_putstr(char const *str);
int find_char(stack_t *st, char c);
int find_zero_sign(stack_t *st);

void helper_positive_zero(stack_t *st, int *array_fw, int is_number)
{
    int index = 0;
    int fw = array_fw[0];
    int fw_2 = array_fw[1];
    (check_if_nb_neg(st)) ? my_putchar('-') : my_putchar('+');
    fw += (check_if_nb_neg(st)) ? 1 : 0;
    index += (check_if_nb_neg(st)) ? 1 : 0;
    my_put_chars(fw, '0');
    increment_stack(&st);
    if (fw_2 > 0 && is_number)
        my_put_chars(fw_2, '0');
    my_putstr(&st->flag.id[index]);
}

void helper_positive_neg(stack_t *st, int *array_fw, int is_number)
{
    int fw = array_fw[0];
    int fw_2 = array_fw[1];
    fw += (check_if_nb_neg(st)) ? 1 : 0;
    my_put_chars(fw, ' ');
    (check_if_nb_neg(st)) ? 0 : my_putchar('+');
    increment_stack(&st);
    if (fw_2 > 0 && is_number)
        my_put_chars(fw_2, '0');
    my_putstr(st->flag.id);
}

void helper_positive_else(stack_t *st, int *array_fw, int is_number)
{
    int fw = array_fw[0];
    int fw_2 = array_fw[1];
    fw += (check_if_nb_neg(st)) ? 1 : 0;
    (check_if_nb_neg(st)) ? 0 : my_putchar('+');
    increment_stack(&st);
    if (fw_2 > 0 && is_number)
        my_put_chars(fw_2, '0');
    my_putstr(st->flag.id);
    my_put_chars(fw, ' ');
}

void compute_positive_sign(stack_t *st, int *array_fw, int is_number)
{
    int zero_sign = find_zero_sign(st);
    int neg_sign = find_char(st, '-');

    if (zero_sign) {
        helper_positive_zero(st, array_fw, is_number);
        return;
    } else if (!neg_sign) {
        helper_positive_neg(st, array_fw, is_number);
        return;
    } else {
        helper_positive_else(st, array_fw, is_number);
        return;
    }
}
