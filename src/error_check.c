/*
** EPITECH PROJECT, 2019
** sbml_parser
** File description:
** error_check
*/

#include "parser.h"

void disp_help(void)
{
    printf("USAGE\n");
    printf("      ./SBMLparser SBMLfile [-i ID [-e]] [-json]\n\n");
    printf("DESCRIPTION\n");
    printf("      SBMLfile    SBML file\n");
    printf("      -i ID       id of the compartment,\
    reaction or product to be extracted\n");
    printf("                  (ignored if uncorrect)\n");
    printf("      -e          print the equation\
    if a reaction ID is given as argument\n");
    printf("                  (ignored otherwise)\n");
    printf("      -json       transform the file into a JSON file\n");
    exit(0);
}

void error_check(int ac, char **av)
{
    if (ac < 2 || ac > 6)
        exit(84);
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        disp_help();
}