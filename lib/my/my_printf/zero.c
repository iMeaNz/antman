/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** compute zero
*/

#include "mylist.h"

int check_if_nb_neg(stack_t *stack);
int my_put_chars(int nb, char c);
void my_putchar(char c);
void increment_stack(stack_t **stack);
int my_putstr(char const *str);
int find_char(stack_t *st, char c);
int find_zero_sign(stack_t *st);

void compute_zero_sign(stack_t *stack, int *array_fw, int is_number)
{
    int index = 0;
    int fw = array_fw[0];
    int fw_2 = array_fw[1];

    (check_if_nb_neg(stack)) ? my_putchar('-') : 0;
    index += (check_if_nb_neg(stack)) ? 1 : 0;
    my_put_chars(fw, '0');
    increment_stack(&stack);
    if (fw_2 > 0 && is_number)
        my_put_chars(fw_2, '0');
    my_putstr(&stack->flag.id[index]);
}
