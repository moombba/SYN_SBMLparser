/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** sort_name
*/

#include "parser.h"

int sort_att_name(att_t *att1, att_t *att2)
{
    char *n1 = att1->next->next->value;
    char *n2 = att2->next->next->value;

    if (!strcmp(n1, n2))
        return (0);
    while (*n1 == *n2) {
        n1++;
        n2++;
    }
    if (*n1 > *n2)
        return (1);
    return (0);
}