/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Utilitary function for printing stuff
*/

void my_putchar(char c);
int is_an_id(char c);
int is_a_flag(char c);
int is_a_num(char c);

int my_put_chars(int nb, char c)
{
    int i = 0;
    if (nb <= 0)
        return 0;
    else
        for (; i < nb; ++i)
            my_putchar(c);
    return i;
}

void my_put_zeros(char c, char *to_add)
{
    if (c < 10) {
        to_add[1] = '0';
        to_add[2] = '0';
    } else if (c < 100)
        to_add[1] = '0';
}
