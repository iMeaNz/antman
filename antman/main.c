/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-guillaume.hein
** File description:
** main.c antman
*/

#include "my.h"
#include <unistd.h>
#include "antman_ppm.h"
#include "open_file.h"

file_t *create_buffer(char *fn);
int parse_ppm(file_t *buffer);
int parse_text_file(file_t *file);

int main(int argc, char **argv)
{
    if (argc != 3) {
        write(2, "Wrong number of arguments\n", 27);
        return 84;
    }

    file_t *buffer = create_buffer(argv[1]);
    if (buffer == 0 || buffer->size == 0)
        return 84;
    switch (my_getnbr(argv[2])) {
        case 1:
            return parse_text_file(buffer);
        case 2:
            return parse_text_file(buffer);
        case 3:
            return (parse_ppm(buffer));
        default:
            return 84;
    }
}
