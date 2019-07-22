/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** sbml_parser
*/

#include "parser.h"

char *find_att(char *name, att_t *att)
{
    for (att_t *tmp = att; tmp != NULL; tmp = tmp->next) {
        if (!strcmp(name, tmp->name))
            return (tmp->value);
    }
    return ("NULL");
}

void display(arg_t *ar, buf_t *tg, char **file)
{
    if (ar->id != NULL && !strcmp(ar->id, "./SBML_parser")) {
        disp_all_species(tg);
        exit(0);
    }
    if (ar->id == NULL && ar->id + ar->json == 0)
        s_parser(tg);
    if (ar->id != NULL && ar->eq == 1)
        find_reac(file, "reaction", "id", ar->id);
    if (ar->id != NULL && ar->eq == 0)
        info_extrct(tg, ar->id, file);
}

void sbml_parser(char **file, arg_t *arg)
{
    buf_t *tags = NULL;

    for (int i = 0; file[i]; i++)
        file[i] = str_clean(file[i]);
    for (int i = 1; file[i]; i++) {
        if (file[i][1] != '/' && count_char(file[i], ' ') > 0) {
            tags = find_tag(file[i], tags);
        }
    }
    organize_list(tags);
    display(arg, tags, file);
}

int main(int ac, char **av)
{
    char **file;
    arg_t arg;

    init_struct(&arg);
    error_check(ac, av);
    handle_flags(&arg, ac, av);
    file = get_file(av[1]);
    sbml_parser(file, &arg);
    return (0);
}