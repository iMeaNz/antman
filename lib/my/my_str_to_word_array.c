/*
** EPITECH PROJECT, 2021
** MY_STR_TO_WORD_ARRAY
** File description:
** Splits a string into words
*/

#include <stdlib.h>
#include "my.h"

static int find_number_word(char const *str)
{
    int i = 0;
    int nb_word = 0;
    int in_a_word = 0;

    while (str[i] != '\0') {
        if (is_alpha(str[i]) || is_num(str[i])) {
            in_a_word = 1;
        } else if (in_a_word) {
            nb_word++;
            in_a_word = 0;
        }
        i++;
    }

    return nb_word + 1;
}

char **my_str_to_word_array(char const *str)
{
    int number_word = find_number_word(str);
    char **word_array = malloc(sizeof(char *) * number_word + 1);
    int count = 0, word = 0, in_a_word = 0, i = -1;

    do {
        i++;
        if (is_alpha(str[i]) || is_num(str[i])) {
            in_a_word = 1;
            count++;
        } else if (in_a_word) {
            word_array[word] = malloc(sizeof(char) * count + 1);
            my_strncpy(word_array[word], &str[i - count], count);
            word++;
            in_a_word = 0;
            count = 0;
        }
    } while (str[i] != '\0');
    word_array[word] = 0;

    return word_array;
}
