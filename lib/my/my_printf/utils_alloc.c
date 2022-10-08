/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Utilitary function for memory allocation
*/

void initialize_str(char *str, int size)
{
    for (int i = 0; i < size; ++i)
        str[i] = 0;
}
