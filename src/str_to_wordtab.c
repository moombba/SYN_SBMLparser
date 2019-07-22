/*
** EPITECH PROJECT, 2019
** sbml_parser
** File description:
** str_to_wordtab
*/

#include "parser.h"

int len_to_char(char *str, char c)
{
    int count = 0;

    while (str[count] && str[count] != c) {
        count++;
    }
    return (count);
}

char **fill_arr(char *str, int count, char c)
{
    int len = 0;
    int col = 0;
    int u = 0;
    char **arr = malloc(sizeof(char *) * (count + 2));

    while (col <= count) {
        u = 0;
        len = len_to_char(str, c);
        arr[col] = malloc(sizeof(char) * (len + 1));
        for (; u < len; u++, str++)
            arr[col][u] = *str;
        arr[col][u] = '\0';
        str++;
        col++;
    }
    arr[count + 1] = NULL;
    return (arr);
}

char **str_to_wordtab(char *str, char c)
{
    int count = 0;
    char **new = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            count += 1;
    }
    new = fill_arr(str, count, c);
    return (new);
}