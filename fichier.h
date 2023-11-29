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

p_d_list create_list_for_search(int n);

void insert_head(p_d_list list, p_d_cell cell);

void sorted_insert(p_d_list list, p_d_cell cell);

void display_list_level(p_d_list list, int level);

void display_list(p_d_list list);

void display_list_level_uniform(p_d_list list, int level);

void display_list_uniform(p_d_list list);

int search_value_level0(p_d_list list, int value);

int search_value_dichotomy(p_d_list list, int value);

int nb_operation_search_value_level0(p_d_list list, int value);

int nb_operation_search_value_dichotomy(p_d_list list, int value);

#endif //PROJECT_CALENDAR_MANAGER_FICHIER_H
