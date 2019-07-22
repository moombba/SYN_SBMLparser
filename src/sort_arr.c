/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** sort_arr
*/

#include "parser.h"

char **swap_s(char **arr, int i)
{
    char *save = arr[i];

    arr[i] = arr[i + 1];
    arr[i + 1] = save;
    return (arr);
}

int check(char **arr)
{
    int i = 0;

    for (int u = 0; arr[i + 1]; i++) {
        u = 0;
        while (arr[i] && arr[i][u] == arr[i + 1][u])
            u++;
        if (arr[i][u] > arr[i + 1][u])
            return (i);
    }
    return (-1);
}

void disp_arr(char **arr)
{
    int ret = check(arr);

    while (ret != -1) {
        arr = swap_s(arr, ret);
        ret = check(arr);
    }
    for (int i = 0; arr[i]; i++) {
        printf("--->%s\n", arr[i]);
    }
}