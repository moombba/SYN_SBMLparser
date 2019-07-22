/*
** EPITECH PROJECT, 2019
** sbml_parser
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

typedef struct att_s {
    char *name;
    char *value;
    struct att_s **fst;
    struct att_s *next;
} att_t;

typedef struct buf_s {
    char *name;
    att_t *att;
    struct buf_s *next;
} buf_t;

#endif /* !LIST_H_ */