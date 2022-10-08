/*
** EPITECH PROJECT, 2021
** MY_STRNCPY
** File description:
** Function that copies n char from the first string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        if (src[i] == '\0') {
            dest[i] = '\0';
            return dest;
        }
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
