/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** antman_lyr
*/

#ifndef ANTMAN_LYR_H_
    #define ANTMAN_LYR_H_

    #include "open_file.h"
    #include <stdint.h>
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define MIN(a, b) ((a) < (b) ? (a) : (b))

    typedef union {
        char str[2];
        uint16_t nb;
    } char_buffer_t;

    typedef struct {
        char *buffer;
        char **dict;
        int buffer_pos;
        int buffer_size;
        int shift_char;
        char_buffer_t char_buffer;
        file_t *file;
    } lyr_t;

#endif /* !ANTMAN_LYR_H_ */
