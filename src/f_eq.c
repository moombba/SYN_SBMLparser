/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** f_eq
*/

#include "parser.h"

void disp_reac(char **str, int type)
{
    for (int i = 0;type == 0 && str[i]; i++) {
        if (i != 0 && i % 2 == 0)
            printf("+ ");
        printf("%s ", str[i]);
    }
    for (int i = 0;type == 1 && str[i]; i++) {
        if (i != 0 && i % 2 == 0)
            printf(" +");
        printf(" %s", str[i]);
    }
}

void get_prod(char **file, int ite, char *tf)
{
    att_t *new = 0;
    int count = 0;
    char **arr = malloc(sizeof(char *) * 100);

    for (; file[ite] != NULL; ite++) {
        if (!strcmp("speciesReference", get_tag(file[ite]))) {
            new = get_att(file[ite]);
            arr[count++] = find_att("stoichiometry", new);
            arr[count++] = find_att("species", new);
        }
        if (file[ite] == NULL || !strcmp("/listOfProducts>", get_tag(file[ite]))) {
            arr[count] = 0;
            disp_reac(arr, 1);
            exit(0);
        }
    }
}

void print_arrow(int arrow)
{
    if (arrow == 0)
        printf("->");
    else
        printf("<->");
}

void get_reac(char **f, int i, char *tf, int rev)
{
    att_t *new = 0;
    int count = 0;
    char **arr = malloc(sizeof(char *) * 100);

    for (; f[i] != NULL; i++) {
        if (!strcmp("listOfProducts>", get_tag(f[i]))) {
            arr[count] = 0;
            disp_reac(arr, 0);
            print_arrow(rev);
            get_prod(f, i, tf);
            exit(0);
        }
        if (!strcmp("speciesReference", get_tag(f[i]))) {
            new = get_att(f[i]);
            arr[count++] = find_att("stoichiometry", new);
            arr[count++] = find_att("species", new);
        }
    }
}

void find_reac(char **file, char *tag, char *att, char *tf)
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
            lel = find_att("reversible", new);
            get_reac(file, i, tf, !strcmp(lel, "false") ? 0 : 1);
            exit(0);
        }
    }
}