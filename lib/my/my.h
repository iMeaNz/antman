/*
** EPITECH PROJECT, 2021
** HEADER
** File description:
** Header File
*/
#ifndef MY_H
    #define MY_H

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_it(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_putnbr_base(int nbr, char const *base);
int my_getnbr_base(char const *str, char const *base);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);
int my_swap_char(char *a, char *b);
int is_num(char c);
int is_alpha(char c);
int is_upper(char c);
int is_lower(char c);
int my_printf(char *str, ...);
int *init_int_array(int size);
int **init_matrix(int nb_line, int nb_col);
char **init_str_array(int size);
char *init_str(int size);
#endif
