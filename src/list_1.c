/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** list_1
*/

#include "parser.h"

buf_t *add_start(buf_t *next, char *str)
{
    buf_t *list = malloc(sizeof(buf_t));

    list->name = str;
    list->att = NULL;
    list->next = next;
    return (list);
}

att_t *add_att(att_t *next, char *name, char *value)
{
    att_t *list = malloc(sizeof(att_t));

    list->name = name;
    list->value = value;
    list->fst = &list;
    list->next = next;
    return (list);
}

void add_end(buf_t *begin, char *str)
{
    buf_t *list = malloc(sizeof(*list));
    buf_t *tmp = begin;

    list->name = str;
    list->next = NULL;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = list;
}

void add_mid(buf_t *prev, buf_t *next, char *str)
{
    buf_t *add = malloc(sizeof(buf_t *));

    add->name = str;
    add->next = next->next;
    prev->next = add;
}

buf_t *create_list(char **ar)
{
    buf_t *next = NULL;
    int i = 0;

    for (; ar[i + 1] != NULL; i += 1);
    for (; i >= 0; i -= 1)
        next = add_start(next, ar[i]);
    return (next);
}