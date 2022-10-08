/*
** EPITECH PROJECT, 2021
** MY_PUT_PRINTABLE_STR
** File description:
** Prints a string
*/

#include "stack.h"
#include <stdlib.h>

int size_nbr(int nbr, int len_base);
void my_put_zeros(char c, char *to_add);
char *my_putnbr_base_str(int nbr, char const *base, char *str);
char *my_revstr(char *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);

void my_put_in_stack(stack_printable_t **st, char *data)
{
    stack_printable_t *element;
    element = malloc(sizeof(*element));
    element->str = data;
    element->next = *st;
    *st = element;
}

stack_printable_t *fill_stack_printable(char *str)
{
    stack_printable_t *st = NULL;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] < 32 || str[i] >= 127) {
            char *to_add = malloc(sizeof(char) * (size_nbr(str[i], 16) + 4));
            to_add[0] = '\\';
            my_put_zeros(str[i], to_add);
            my_putnbr_base_str(str[i], "01234567", to_add);
            my_revstr(to_add);
            my_put_in_stack(&st, to_add);
        } else {
            char *to_add = malloc(sizeof(char) * 2);
            to_add[0] = str[i];
            to_add[1] = '\0';
            my_put_in_stack(&st, to_add);
        }
    }
    return st;
}

char *my_put_printable_str(char *str)
{
    int total_size = 0;
    stack_printable_t *st = fill_stack_printable(str);
    stack_printable_t *tmp = st;
    while (tmp != NULL) {
        total_size += my_strlen(tmp->str);
        tmp = tmp->next;
    }
    char *output = malloc(sizeof(char) * total_size + 1);
    while (st != NULL) {
        my_strcat(output, st->str);
        st = st->next;
    }
    my_revstr(output);
    return output;
}
