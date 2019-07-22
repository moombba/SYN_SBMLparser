/*
** EPITECH PROJECT, 2019
** sbml_parser
** File description:
** s_parser
*/

#include "parser.h"

void disp(buf_t *tmp)
{
    printf("%s\n", tmp->name);
    for (att_t *lol = tmp->att; lol != NULL; lol = lol->next)
        printf("--->%s\n", lol->name);
}

void s_parser(buf_t *tags)
{
    char *tag = "prout";

    for (buf_t *tmp = tags; tmp != NULL; tmp = tmp->next) {
        if ((strcmp(tag, tmp->name) != 0)) {
            disp(tmp);
            tag = tmp->name;
        }
    }
    exit(0);
}