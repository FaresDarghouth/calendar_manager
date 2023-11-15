//
// Created by squip on 01/11/2023.
//

#include "main.h"
#include "fichier.h"
#include <stdio.h>

int main() {
    p_d_list list = create_list(5);
    display_list_uniform(list);

    insert_head(list, create_cell(18, 3));
    insert_head(list, create_cell(25, 1));
    insert_head(list, create_cell(3, 1));
    insert_head(list, create_cell(12, 3));
    insert_head(list, create_cell(7, 2));
    insert_head(list, create_cell(1, 5));
    insert_head(list, create_cell(2, 1));
    insert_head(list, create_cell(4, 1));
    printf("After insert_head:\n\n");
    display_list_uniform(list);

    p_d_list list2 = create_list(5);
    sorted_insert(list2, create_cell(1, 3));
    sorted_insert(list2, create_cell(2, 1));
    sorted_insert(list2, create_cell(3, 1));
    sorted_insert(list2, create_cell(5, 1));
    printf("After sorted_insert:\n\n");
    display_list_uniform(list2);
    sorted_insert(list2, create_cell(4, 3));
    sorted_insert(list2, create_cell(1, 4));
    printf("After sorted_insert with cell->value = 4:\n\n");
    display_list_uniform(list2);
    return 0;
}
