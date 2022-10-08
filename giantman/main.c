/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-guillaume.hein
** File description:
** main.c giantman
*/

#include "my.h"
#include <unistd.h>
#include "antman_lyr.h"
#include "open_file.h"

file_t *create_buffer(char *fn);
int parse_ppm_compressed(file_t *file);
int parse_text_compressed(file_t *file);

void write_to_buffer_text(lyr_t *lyr, char *str)
{
    if (lyr->buffer_pos + my_strlen(str) >= lyr->buffer_size) {
        write(1, lyr->buffer, lyr->buffer_pos);
        lyr->buffer_pos = 0;
    }
    for (int i = 0 ; str[i] != '\0' ; i++) {
        lyr->buffer[lyr->buffer_pos++] = str[i];
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        write(2, "Wrong number of arguments\n", 27);
        return 84;
    }
    file_t *buffer = create_buffer(argv[1]);
    if (buffer == 0)
        return 84;
    if (buffer->size == 0)
        return 84;
    switch (my_getnbr(argv[2])) {
        case 1:
            return (parse_text_compressed(buffer));
        case 2:
            return (parse_text_compressed(buffer));
        case 3:
            return (parse_ppm_compressed(buffer));
        default:
            return 84;
    }
    return 0;
}
