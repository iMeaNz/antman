/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Compute neg sign
*/

#include "mylist.h"

int check_if_nb_neg(stack_t *stack);
int my_put_chars(int nb, char c);
void my_putchar(char c);
void increment_stack(stack_t **stack);
int my_putstr(char const *str);
int find_char(stack_t *st, char c);
int find_zero_sign(stack_t *st);

void compute_neg_sign(stack_t *stack, int *array_fw, int is_number)
{
    int fw = array_fw[0];
    int fw_2 = array_fw[1];
    if (fw_2 > 0 && is_number)
        my_put_chars(fw_2, '0');
    my_putstr(stack->flag.id);
    my_put_chars(fw, ' ');
}
