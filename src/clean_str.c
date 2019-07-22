/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** clean_str
*/

#include "parser.h"

int final_len(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] != ' ' && str[i] != '\t')
            count++;
    return (count);
}

char *clean_str(char *str)
{
    int f_len = final_len(str);
    char *new = malloc(sizeof(char) * (f_len + 1));
    int run = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            new[run++] = str[i];
        }
    }
    new[f_len] = '\0';
    free(str);
    return (new);
}

char *str_clean(char *str)
{
    int len = 0;
    char *new = NULL;

    for (; *str == ' '; str++);
    len = strlen(str);
    new = malloc(sizeof(char) * (len + 1));
    for (int i = 0; str[i]; i++)
        new[i] = str[i];
    new[len] = 0;
    return (new);
}