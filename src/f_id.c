/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** f_id
*/

#include "parser.h"

void lol(buf_t *bob)
{
    while (bob != NULL) {
        printf("%s\n", bob->name);
        bob = bob->next;
    }
    exit (0);
}

void id_compart(buf_t *tg, char *id)
{
    printf("List of species in compartment %s\n", id);
    for (buf_t *tmp = tg; tmp != NULL; tmp = tmp->next) {
        if (!strcmp("species", tmp->name)
        && !strcmp(id, find_att("compartment", tmp->att)))
            printf("--->%s\n", find_att("name", tmp->att));
    }
    exit(0);
}

void disp_all_species(buf_t *tg)
{
    printf("List of species\n");
    for (buf_t *tmp = tg; tmp != NULL; tmp = tmp->next) {
        if (!strcmp("species", tmp->name))
            printf("--->%s\n", find_att("name", tmp->att));
    }
    exit(0);
}

int deter_id(buf_t *tg, char *id, char **file)
{
    for (buf_t *tmp = tg; tmp != NULL; tmp = tmp->next) {
        if (!strcmp("species", tmp->name)
        && !strcmp(id, find_att("compartment", tmp->att)))
            return (1);
        if (!strcmp("reaction", tmp->name)
        && !strcmp(id, find_att("id", tmp->att)))
            find_line(file, "reaction", "id", id);
    }
    for (buf_t *tmp = tg; tmp != NULL; tmp = tmp->next)
    {
        if (!strcmp("speciesReference", tmp->name)
        && !strcmp(id, find_att("species", tmp->att))) {
            find_reaction(file, id);
            exit (0);
        }
    }
    return (0);
}

void info_extrct(buf_t *tg, char *id, char **file)
{
    int c = deter_id(tg, id, file);

    switch (c)
    {
    case 1 :
        id_compart(tg, id);
        break;
    default:
        disp_all_species(tg);
        break;
    }
}