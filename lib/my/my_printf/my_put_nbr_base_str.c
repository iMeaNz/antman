/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Put nbr base that returns a string
*/

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);

char *my_putnbr_base_str(int nbr, char const *base, char *str)
{
    int len_base = my_strlen(base);
    char convert[2];
    convert[1] = '\0';
    if (nbr == -2147483648) {
        str = "-2147483648";
        return str;
    }
    if (nbr == 0 || len_base == 0) {
        return (str);
    }
    if (nbr < 0) {
        nbr = nbr * (-1);
        my_strcat(str, "-");
    }
    int remainder = nbr % len_base;
    nbr /= len_base;
    my_putnbr_base_str(nbr, base, str);
    convert[0] = base[remainder];
    my_strcat(str, convert);
    return (str);
}

char *my_put_u_nbr_base_str(unsigned long nbr, char const *base, char *str)
{
    int len_base = my_strlen(base);
    int remainder;
    char convert[2];
    convert[1] = '\0';

    if (nbr == 0 || len_base == 0)
        return (str);
    remainder = nbr % len_base;
    nbr /= len_base;
    my_put_u_nbr_base_str(nbr, base, str);
    convert[0] = base[remainder];
    my_strcat(str, convert);
    return (str);
}

char *my_put_long_nbr_base_str(long int nbr, char const *base, char *str)
{
    int len_base = my_strlen(base);
    char convert[2];
    convert[1] = '\0';
    if (nbr == -2147483648) {
        str = "-2147483648";
        return str;
    }
    if (nbr == 0 || len_base == 0) {
        return (str);
    }
    if (nbr < 0) {
        nbr = nbr * (-1);
        my_strcat(str, "-");
    }
    int remainder = nbr % len_base;
    nbr /= len_base;
    my_put_long_nbr_base_str(nbr, base, str);
    convert[0] = base[remainder];
    my_strcat(str, convert);
    return (str);
}

char *my_put_long_long_nbr_base_str(long int nbr, char const *base, char *str)
{
    int len_base = my_strlen(base);
    char convert[2];
    convert[1] = '\0';
    if (nbr == -2147483648) {
        str = "-2147483648";
        return str;
    }
    if (nbr == 0 || len_base == 0) {
        return (str);
    }
    if (nbr < 0) {
        nbr = nbr * (-1);
        my_strcat(str, "-");
    }
    int remainder = nbr % len_base;
    nbr /= len_base;
    my_put_long_long_nbr_base_str(nbr, base, str);
    convert[0] = base[remainder];
    my_strcat(str, convert);
    return (str);
}
