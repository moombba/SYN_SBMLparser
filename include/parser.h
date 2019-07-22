/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** parser
*/

#ifndef PARSER_H_
    #define PARSER_H_

#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "list.h"

typedef struct arg_s
{
    char *id;
    int eq;
    int json;
} arg_t;

buf_t *add_start(buf_t*, char*);
void add_end(buf_t*, char*);
int check_tag(char *tf, buf_t *buf);
att_t *sort_att(att_t *tet);
buf_t *create_list(char **);
void organize_list(buf_t *first);
void add_mid(buf_t*, buf_t*, char*);
int my_list_size(buf_t*);
char **str_to_wordtab(char *str, char c);
buf_t *sort_list(buf_t *tet);
char **get_file(char *file_name);
char *clean_str(char *str);
int len_to_char(char *str, char c);
buf_t *find_tag(char *, buf_t *);
char *str_clean(char *str);
att_t *add_att(att_t *next, char *name, char *);
int compare_tag(char *l, char *t);

int count_char(char *str, char c);

void handle_flags(arg_t *arg, int argc, char **argv);
void init_struct(arg_t *arg);
void error_check(int ac, char **av);

att_t *get_att(char *l);
char *get_tag(char *l);

void find_reac(char **file, char *tag, char *att, char *tf);

char *find_att(char *name, att_t *att);

att_t *find_line(char **file, char *tag, char *att, char *);

void disp_arr(char **arr);


int sort_att_name(att_t *n1, att_t *n2);

void s_parser(buf_t *tags);
void disp_all_species(buf_t *tg);
int deter_id(buf_t *tg, char *id, char **);
void info_extrct(buf_t *tg, char *id, char **);

void find_reaction(char **file, char *tf);

#endif /* !PARSER_H_ */