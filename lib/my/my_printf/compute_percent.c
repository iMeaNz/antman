/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Compute the percent in printf
*/

#include "../my.h"
#include "mylist.h"
#include <stdlib.h>
#include <stdarg.h>

format_t *create_array_struct(void);
int is_an_id(char c);
void my_put_in_list(stack_t **list, format_t data);
int is_a_flag(char c);
void remove_duplicates(stack_t **list);
char *find_field_width(stack_t **list);
int remove_lower_field_width(stack_t **begin);
int find_hash(stack_t *stack);
int remove_lower_before_number(stack_t **begin);
void my_sort_list(stack_t **st);
int replace_identifier(stack_t **st, va_list ap, int is_hash, int *is_special);
void print_stack(stack_t *stack, int is_number, int *array_fw, int is_special);
void my_putchar(char c);
char *my_strncpy(char *dest, char const *src, int n);
int is_a_num(char c);
int my_strlen(char const *str);
void initialize_str(char *str, int size);
int *split_fw(char *fw_str, int *array);
int find_l_flags(stack_t **st);
int find_id_number(stack_t *st);

format_t find_sign(char c, format_t *array)
{
    for (int i = 0; i < 16; ++i) {
        if (array[i].id[0] == c) {
            return array[i];
        }
    }
    return array[16];
}

format_t find_nb(char *str)
{
    int i = 0;

    while (is_a_num(str[i]) || str[i] == '.')
        i++;
    char *number = malloc(sizeof(char) * i + 1);
    initialize_str(number, i + 1);
    my_strncpy(number, str, i);
    format_t output = {number, -1, -1, -1};
    return output;
}

stack_t *fill_stack(char *sr, int *index)
{
    stack_t *st = NULL;
    format_t *array_struct = create_array_struct();
    int i = 0;
    for (; (!is_an_id(sr[i]) && is_a_flag(sr[i])) || is_a_num(sr[i]); ++i) {
        if (sr[i] != '0' && is_a_num(sr[i])) {
            my_put_in_list(&st, find_nb(&sr[i]));
            i += my_strlen(st->flag.id) - 1;
        } else {
            my_put_in_list(&st, find_sign(sr[i], array_struct));
        }
    }
    *index = i;
    return st;
}

void modify_stack(stack_t *st, va_list ap)
{
    int is_special = 0;
    remove_duplicates(&st);
    char *fw = find_field_width(&st);
    remove_lower_field_width(&st);
    int is_hash = find_hash(st);
    int is_before = remove_lower_before_number(&st);
    int array_fw[2];
    int *begin_array = split_fw(fw, array_fw);
    my_sort_list(&st);
    int is_number = find_id_number(st);
    int size_replaced = replace_identifier(&st, ap, is_hash, &is_special);
    begin_array[1] -= size_replaced + is_before;
    begin_array[1] = (begin_array[1] < 0) ? 0 : begin_array[1];
    begin_array[0] -= size_replaced + is_before + begin_array[1];
    print_stack(st, is_number, begin_array, is_special);
}

int compute_percent(char *str, va_list ap)
{
    int i = 0;
    int is_special = 0;
    format_t *array_struct = create_array_struct();
    format_t struct_l_flag = {"l", 1, -1, -1};
    stack_t *st = fill_stack(str, &i);
    while (str[i] == 'l') {
        my_put_in_list(&st, struct_l_flag);
        i++;
    }
    if (is_an_id(str[i]))
        my_put_in_list(&st, find_sign(str[i], array_struct));
    else if (!is_a_flag(str[i]) && str[i] != '%') {
        my_putchar('%');
        return 0;
    } else
        return i;
    modify_stack(st, ap);
    return i + 1;
}
