/*
** EPITECH PROJECT, 2019
** SYN_SBMLparser_2018
** File description:
** count_space
*/

#include "parser.h"

int count_char(char *str, char ch)
{
    int count = 0;

    while (*str++ != '\0') {
        if (*str == ch)
            count++;
    }
    return (count);
}