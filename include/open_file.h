/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** open_file
*/

#ifndef OPEN_FILE_H_
    #define OPEN_FILE_H_

    #include <unistd.h>

    typedef struct {
        char *content;
        size_t size;
    } file_t;

#endif /* !OPEN_FILE_H_ */
