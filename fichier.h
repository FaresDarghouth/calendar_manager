//
// Created by squip on 01/11/2023.
//

#ifndef PROJECT_CALENDAR_MANAGER_FICHIER_H
#define PROJECT_CALENDAR_MANAGER_FICHIER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_d_cell {
    int value;
    int level;
    struct s_d_cell **next;
} t_d_cell, *p_d_cell;

typedef struct s_d_list {
    int max_level;
    p_d_cell *heads;
} t_d_list, *p_d_list;

p_d_cell create_cell(int value, int level);

p_d_list create_list(int max_level);

void insert(p_d_list list, p_d_cell cell);

void print_cell(p_d_cell cell);

void print_list_level(p_d_list list, int level);

void print_list(p_d_list list);

#endif //PROJECT_CALENDAR_MANAGER_FICHIER_H
