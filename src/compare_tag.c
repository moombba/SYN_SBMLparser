/*
** EPITECH PROJECT, 2019
** sbml_parser
** File description:
** compare_tag
*/

#include "parser.h"

int compare_tag(char *line, char *tag)
{
    int run = 0;

    for (int i = 1; line[i] != ' ' && line[i] != '>'; i++)
    {
        if (line[i] != tag[run])
            return (1);
        run++;
    }
    return (0);
}

char *get_tag(char *line)
{
    char *dupl = line;
    char *new = 0;
    int len = 0;

    while (*line++ != ' ')
        len++;
    new = malloc(sizeof(char) * (len + 1));
    for (int i = 0; *dupl++ != ' '; i++)
        new[i] =*dupl;
    new[len - 1] = 0;
    return (new);
}

buf_t *find_tag(char *line, buf_t *buf)
{
    char *new = get_tag(line);

    buf = add_start(buf, new);
    buf->att = get_att(line);
    return (buf);
}