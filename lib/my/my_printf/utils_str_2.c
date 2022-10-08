/*
** EPITECH PROJECT, 2021
** B-PSU-100-STG-1-1-myprintf-mehdy.morvan
** File description:
** Utilitary function for strings
*/

int check_if_float(char *float_str)
{
    for (int i = 0; float_str[i] != '\0'; ++i) {
        if (float_str[i] == '.')
            return 1;
    }
    return 0;
}
