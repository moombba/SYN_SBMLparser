/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** find_line
*/

#include "parser.h"

void find_products(char **file, int ite, char *tf)
{
    att_t *new = 0;
    char *lel;
    int count = 0;
    char **arr = malloc(sizeof(char *) * 100);

    printf("List of products of reaction %s\n", tf);
    for (; file[ite] != NULL; ite++) {
        if (!strcmp("speciesReference", get_tag(file[ite]))) {
            new = get_att(file[ite]);
            lel = find_att("species", new);
            arr[count++] = lel;
        }
        if (file[ite] == NULL || !strcmp("/listOfProducts>", get_tag(file[ite]))) {
            arr[count] = 0;
            disp_arr(arr);
            exit(0);
        }
    }
    exit(0);
}

int find_p(char **file, int i, char *tf, char *reaction)
{
    att_t *new = 0;
    char *lel;

    printf("List of reactions consuming species %s (quantities)\n", tf);
    for (; file[i] != NULL; i++) {
        if (!strcmp("speciesReference", get_tag(file[i]))) {
            new = get_att(file[i]);
            lel = find_att("species", new);
            if (!strcmp(lel, tf)) {
                printf("--->%s (%s)\n", reaction, find_att("stoichiometry", new));
            }
        }
        if (file[i] == NULL || !strcmp("/listOfReactants>", get_tag(file[i]))) {
            return (0);
        }
    }
    return (0);
}

void find_reactant(char **file, int i, char *tf)
{
    att_t *new = 0;
    char *lel;
    int count = 0;
    char **arr = malloc(sizeof(char *) * 100);

    printf("List of reactants of reaction %s\n", tf);
    for (; file[i] != NULL; i++) {
        if (!strcmp("listOfProducts>", get_tag(file[i]))) {
            arr[count] = 0;
            disp_arr(arr);
            find_products(file, i, tf);
            exit(0);
        }
        if (!strcmp("speciesReference", get_tag(file[i]))) {
            new = get_att(file[i]);
            lel = find_att("species", new);
            arr[count++] = lel;
        }
    }
}

att_t *find_line(char **file, char *tag, char *att, char *tf)
{
    att_t *new = 0;
    char *lel = NULL;
    int i = 0;

    for (; file[i]; i++) {
        if (!strcmp(tag, get_tag(file[i]))) {
            new = get_att(file[i]);
            lel = find_att(att, new);
        }
        if (lel != NULL && !strcmp(lel, tf)) {
            find_reactant(file, i, tf);
            exit(0);
        }
    }
    return (new);
}

void find_reaction(char **file, char *tf)
{
    char *lel = NULL;
    att_t *new = 0;
    int i = 0;

    for (; file[i]; i++) {
        if (!strcmp("reaction", get_tag(file[i]))) {
            new = get_att(file[i]);
            lel = find_att("id", new);
            if (lel != NULL)
                find_p(file, i, tf, lel);
        }
    }
}