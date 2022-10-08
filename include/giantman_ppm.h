/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** giantman_ppm
*/

#ifndef GIANTMAN_PPM_H_
    #define GIANTMAN_PPM_H_

    #include "open_file.h"
    #include <stdint.h>
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define MIN(a, b) ((a) < (b) ? (a) : (b))
    #define IS_RGB_TYPE(nb) ((nb) & (1 << 8))

    typedef union {
        char str[2];
        uint16_t nb;
    } char_buffer_t;

    typedef struct {
        char *buffer;
        int buffer_pos;
        int buffer_size;
        int shift_char;
        char_buffer_t char_buffer;
        file_t *file;
    } ppm_t;

#endif /* !GIANTMAN_PPM_H_ */
