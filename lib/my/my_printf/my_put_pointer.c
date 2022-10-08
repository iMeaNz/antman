/*
** EPITECH PROJECT, 2021
** MY_PUT_POINTER
** File description:
** Returns a pointer as a string
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int size_nbr(int nbr, int len_base);
char *my_put_u_nbr_base_str(unsigned long nbr, char const *base, char *str);

char *my_print_pointer(unsigned long long x)
{
    int size = size_nbr(x, 16);
    char *output = malloc(sizeof(char) * (size + 3));
    output[0] = '0';
    output[1] = 'x';
    my_put_u_nbr_base_str(x, "0123456789abcdef", output);
    return output;
}
