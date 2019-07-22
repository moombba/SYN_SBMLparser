/*
** EPITECH PROJECT, 2019
** sbml_parser
** File description:
** handle_flag
*/

#include "parser.h"

void init_struct(arg_t *arg)
{
    arg->id = NULL;
    arg->eq = 0;
    arg->json = 0;
}

void check_flags(char **argv, arg_t *arg, int i)
{
    if (argv[i][1] == 'i') {
        if (argv[i + 1] != NULL)
            arg->id = argv[i + 1];
        else
            arg->id = argv[0];
        return;
    }
    if (argv[i][1] == 'e') {
        arg->eq = 1;
        return;
    }
    if (strcmp(argv[i], "-json") == 0) {
        arg->json = 1;
        return;
    }
    else {
        exit (84);
    }
}

void handle_flags(arg_t *arg, int argc, char **argv)
{
    for (int i = 0; argv[i]; i++) {
        if (argv[i][0] == '-')
            check_flags(argv, arg, i);
    }
}