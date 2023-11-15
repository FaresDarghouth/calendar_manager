//
// Created by squip on 01/11/2023.
//

#include "fichier.h"

p_d_cell create_cell(int value, int level) {
    p_d_cell cell = (p_d_cell)malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->level = level;
    cell->next = (p_d_cell *)malloc(level * sizeof(p_d_cell));
    for (int i = 0; i < level; ++i) {
        cell->next[i] = NULL;
    }
    return cell;
}

p_d_list create_list(int max_level) {
    p_d_list list = (p_d_list)malloc(sizeof(t_d_list));
    list->max_level = max_level;
    list->heads = (p_d_cell *)malloc(max_level * sizeof(p_d_cell));
    for (int i = 0; i < max_level; ++i) {
        list->heads[i] = NULL;
    }
    return list;
}

void insert_head(p_d_list list, p_d_cell cell) {
    if (cell->level <= list->max_level) {
        for (int i = 0; i < cell->level; ++i) {
            cell->next[i] = list->heads[i];
        }
        for (int i = 0; i < cell->level; ++i) {
            list->heads[i] = cell;
        }
    }
    else
        printf("Error: cell level is greater than list max level\n");
}

void display_list_level(p_d_list list, int level) {
    p_d_cell temp = NULL;
    printf("[list head_%d @-]-->", level);
    if (list->heads[level] != NULL) {
        temp = list->heads[level];
        while (temp != NULL) {
            printf("[ %d|@-]-->", temp->value);
            temp = temp->next[level];
        }
        printf("NULL");
    }
    else
        printf("NULL");
}

void display_list_level_uniform(p_d_list list, int level) {
    p_d_cell temp = NULL;
    p_d_cell level_0 = NULL;
    printf("[list head_%d @-]--", level);
    temp = list->heads[level];
    level_0 = list->heads[0];
    while (level_0 != NULL) {
        if (temp != level_0 || temp == NULL) {
            print_n_times("-", nb_digits(level_0->value)+9);
            level_0 = level_0->next[0];
        }
        else {
            printf(">[ %d|@-]--", temp->value);
            temp = temp->next[level];
            level_0 = level_0->next[0];
        }
    }
    printf(">NULL");
}

void display_list(p_d_list list) {
    for (int i = 0; i < list->max_level; ++i) {
        display_list_level(list, i);
        printf("\n");
    }
}

void display_list_uniform(p_d_list list) {
    for (int i = 0; i < list->max_level; ++i) {
        display_list_level_uniform(list, i);
        printf("\n");
    }
}

void sorted_insert(p_d_list list, p_d_cell cell) {
    p_d_cell temp = NULL;
    if (cell->level <= list->max_level) {
        for (int i = 0; i < cell->level; ++i) {
            if (list->heads[i] == NULL || cell->value < list->heads[i]->value) {
                cell->next[i] = list->heads[i];
                list->heads[i] = cell;
            }
            else {
                temp = list->heads[i];
                while (temp->next[i] != NULL && temp->next[i]->value < cell->value) {
                    temp = temp->next[i];
                }
                cell->next[i] = temp->next[i];
                temp->next[i] = cell;
            }
        }
    }
    else
        printf("Error: cell level is greater than list max level\n");
}