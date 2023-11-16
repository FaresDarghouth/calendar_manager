//
// Created by squip on 01/11/2023.
//

#include "main.h"

int main() {
    p_d_list list = create_list(5);
    printf("After create_list (empty list):");
    newline();
    newline();
    display_list_uniform(list);
    print_line();

    insert_head(list, create_cell(18, 3));
    insert_head(list, create_cell(25, 1));
    insert_head(list, create_cell(3, 1));
    insert_head(list, create_cell(12, 3));
    insert_head(list, create_cell(7, 2));
    insert_head(list, create_cell(1, 5));
    insert_head(list, create_cell(2, 1));
    insert_head(list, create_cell(4, 1));
    printf("After insert_head:");
    newline();
    newline();
    display_list_uniform(list);
    print_line();

    p_d_list list2 = create_list(5);
    sorted_insert(list2, create_cell(5, 3));
    sorted_insert(list2, create_cell(4, 1));
    sorted_insert(list2, create_cell(2, 1));
    sorted_insert(list2, create_cell(1, 3));
    printf("After sorted_insert:");
    newline();
    newline();
    display_list_uniform(list2);
    print_line();

    sorted_insert(list2, create_cell(3, 4));
    printf("After sorted_insert with cell->value = 3:");
    newline();
    newline();
    display_list_uniform(list2);
    return 0;
}
