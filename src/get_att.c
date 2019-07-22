/*
** EPITECH PROJECT, 2019
** sbml_parser
** File description:
** get_att
*/

#include "parser.h"

char *value_get(char *line)
{
    int len = 0;
    char *new = 0;

    while (*line != 34)
        line++;
    line++;
    for (; line[len] != 34; len++);
    new = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        new[i] = line[i];
    new[len] = '\0';

    return (new);
}

int go_to_att(char *line)
{
    int run = 0;
    int count = 0;

    for (; count < 2; run++)
        if (line[run] == '\"')
            count++;
    if (line[run] == '>' || (line[run] == 47 && line[run + 1] == '>')
    || (line[run] == ' ' && line[run + 1] == '>')) {
        return (-1);
    }
    return (run + 1);
}

char *att_get(char *line)
{
    int len = 0;
    char *new;

    while (line[len] != ' ')
        len++;
    new = malloc(sizeof(char) * (len + 1));
    for (int i = 0; line[i] != '='; i++) {
        new[i] = line[i];
    }
    new[len] = 0;
    return (new);
}

att_t *get_att(char *line)
{
    int jump = 0;
    att_t *new = NULL;

    for (; *line != ' '; line++);
    line++;
    new = add_att(new, att_get(line), value_get(line));
    value_get(line);
    jump = go_to_att(line);
    if (jump != - 1) {
        line += jump;
        new = add_att(new, att_get(line), value_get(line));
        value_get(line);
    }
    while (jump != -1) {
        jump = go_to_att(line);
        if (jump != -1) {
            line += jump;
            new = add_att(new, att_get(line), value_get(line));
            value_get(line);
        }
    }
    return (new);
}