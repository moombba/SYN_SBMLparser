/*
** EPITECH PROJECT, 2019
** sbml_parser
** File description:
** check_tags
*/

#include "parser.h"

int check_tag(char *tf, buf_t *buf)
{
    for (buf_t *tmp = buf; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tf, tmp->name) == 0)
            return (1);
    }
    return (0);
}