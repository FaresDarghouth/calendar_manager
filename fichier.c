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
        list->heads[i] = create_cell(0, i);
    }
    return list;
}

void insert(p_d_list list, p_d_cell cell) {
    if (cell->level < list->max_level) {
        for (int i = 0; i < cell->level; ++i) {
            list->heads[i] = cell;
        }
    }

}

void print_empty_list(p_d_list list) {
    for (int i = 0; i < list->max_level; ++i) {
        printf("[list head_%d @-]-->%p\n", i, list->heads[i]);
    }
}