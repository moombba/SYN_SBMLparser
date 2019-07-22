/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** sort_tetriminos
*/

#include "parser.h"

att_t *fst_swap_att(att_t *tet)
{
    att_t *save = tet->next->next;
    att_t *ret = tet->next;

    tet->next->next = tet;
    tet->next = save;
    *tet->fst = ret;
    return (ret);
}

void swap_att(int index, att_t *tetris)
{
    att_t *save1;
    att_t *save2;
    att_t *tmp = tetris;

    for (int i = 0; i < index - 1; i++)
        tmp = tmp->next;
    save1 = tmp->next;
    save2 = tmp->next->next->next;
    tmp->next = tmp->next->next;
    tmp->next->next = save1;
    save1->next = save2;
}

int sort_check_att(att_t *tetris)
{
    int i = 0;
    int count = 0;

    for (att_t *tmp = tetris; tmp->next != NULL; tmp = tmp->next) {
        i = 0;
        while (tmp->name[i] == tmp->next->name[i])
            i++;
        if (tmp->name[i] > tmp->next->name[i])
            return (count);
        count++;
    }
    return (-1);
}

att_t *sort_att(att_t *tet)
{
    int ret = sort_check_att(tet);

    while (ret != -1) {
        if (ret == 0)
            tet = fst_swap_att(tet);
        else
        {
            swap_att(ret, tet);
        }
        ret = sort_check_att(tet);
    }
    return (tet);
}

void organize_list(buf_t *first)
{
    while (first != NULL) {
        first->att = sort_att(first->att);
        first = first->next;
    }
}