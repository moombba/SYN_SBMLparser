/*
** EPITECH PROJECT, 2019
** sbml_parser
** File description:
** get_file
*/

#include "parser.h"

int get_size(char *file_name)
{
    struct stat sb;

    if (stat(file_name, &sb) == -1)
        exit(84);
    return (sb.st_size);
}

char **get_file(char *file_name)
{
    int fd = open(file_name, 00);
    int size = get_size(file_name);
    char file[size + 1];

    if (fd == -1)
        exit(84);
    read(fd, file, size);
    file[size] = '\0';
    return (str_to_wordtab(file, '\n'));
}
