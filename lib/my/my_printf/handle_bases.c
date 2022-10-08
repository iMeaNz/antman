/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Function that converts nb in a base string
*/

#include <stdarg.h>
#include <stdlib.h>

int my_strlen(char const *str);
int size_nbr(int nbr, int len_base);
char *my_put_u_nbr_base_str(unsigned long nbr, char const *base, char *str);
int size_unsigned_nbr(unsigned int nbr, int len_base);
char *my_putnbr_base_str(int nbr, char const *base, char *str);

char *handle_hexa(va_list ap, char *base, int is_hash)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int len_base = my_strlen(base);
    int size_nb = size_nbr(nb, len_base);
    char *new_nb = malloc(sizeof(char) * (size_nb + is_hash * 2));

    if (nb == 0) {
        new_nb[0] = base[0];
        return new_nb;
    }
    if (is_hash) {
        new_nb[0] = '0';
        new_nb[1] = 'x';
    }
    new_nb = my_put_u_nbr_base_str(nb, base, new_nb);
    return new_nb;
}

char *handle_octal(va_list ap, char *base, int is_hash)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int len_base = my_strlen(base);
    int size_nb = size_nbr(nb, len_base);
    char *new_nb = malloc(sizeof(char) * (size_nb + is_hash * 2));

    if (nb == 0) {
        new_nb[0] = base[0];
        return new_nb;
    }
    if (is_hash)
        new_nb[0] = '0';
    new_nb = my_put_u_nbr_base_str(nb, base, new_nb);
    return new_nb;
}

char *handle_binary(va_list ap, char *base)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int len_base = my_strlen(base);
    int size_nb = size_nbr(nb, len_base);
    char *new_nb = malloc(sizeof(char) * (size_nb + 1));

    if (nb == 0) {
        new_nb[0] = base[0];
        return new_nb;
    }
    new_nb = my_put_u_nbr_base_str(nb, base, new_nb);
    return new_nb;
}

char *handle_unsigned_decimal(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);
    int size_nb = size_unsigned_nbr(nb, 10);
    char *new_nb = malloc(sizeof(char) * size_nb + 1);

    if (nb == 0) {
        new_nb[0] = '0';
        return new_nb;
    }

    new_nb = my_put_u_nbr_base_str(nb, "0123456789", new_nb);
    return new_nb;
}

char *handle_decimal(va_list ap, int *is_special)
{
    int nb = va_arg(ap, int);
    int size_nb = (nb != 0) ? size_nbr(nb, 10) : 1;
    char *new_nb = malloc(sizeof(char) * size_nb + 1);

    if (nb == 0) {
        new_nb[0] = '0';
        return new_nb;
    }

    new_nb = my_putnbr_base_str(nb, "0123456789", new_nb);
    return new_nb;
}
