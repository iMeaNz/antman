/*
** EPITECH PROJECT, 2021
** UTILS
** File description:
** Utilitary function for flags
*/

int is_a_flag(char c)
{
    if (c == '-' || c == '+')
        return 1;
    if (c == ' ' || c == '#')
        return 1;
    if (c == '0')
        return 2;
    if (c == '.')
        return 3;
    return 0;
}

int is_an_id(char c)
{
    if (c == 'd' || c == 'i' || c == 'o' || c == 'x' || c == 'X')
        return 1;
    if (c == 'b')
        return 1;
    if (c == 'c' || c == 's' || c == 'S' || c == 'p' || c == 'u')
        return 2;
    return 0;
}

int is_a_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

char *find_base(char c)
{
    if (c == 'd' || c == 'i' || c == 'u')
        return "0123456789";
    if (c == 'o')
        return "01234567";
    if (c == 'x')
        return "0123456789abcdef";
    if (c == 'X')
        return "0123456789ABCDEF";
    if (c == 'b')
        return "01";
    return 0;
}
