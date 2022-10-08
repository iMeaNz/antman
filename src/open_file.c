/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-guillaume.hein
** File description:
** open_file.c
*/

#include "my.h"
#include "open_file.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int fill_buffer(file_t *f_data, struct stat st, int fd)
{
    f_data->size = st.st_size;
    f_data->content = init_str(f_data->size);
    if (f_data->content == NULL)
        return 84;
    if (read(fd, f_data->content, f_data->size + 1) == -1)
        return 84;
    f_data->content[f_data->size] = '\0';
    close(fd);
    return 0;
}

file_t *create_buffer(char *fn)
{
    file_t *f_data = malloc(sizeof(file_t));
    if (f_data == NULL)
        return 0;
    int fd = open(fn, O_RDONLY | 0, 0);
    struct stat st;
    if (f_data == NULL || stat(fn, &st) != 0
    || fd == -1 || !S_ISREG(st.st_mode)) {
        write(2, "Incorrect file\n", 16);
        return 0;
    }
    if (fill_buffer(f_data, st, fd))
        return 0;
    if (f_data->content == 0) {
        write(2, "Incorrect file\n", 16);
        return 0;
    }
    return f_data;
}
