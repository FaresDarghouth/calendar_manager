//
// Created by squip on 01/11/2023.
//

#include "main.h"

void is_present(p_d_list list, int value) {
    if (search_value_dichotomy(list, value) == 1)
        printf("%d is present.\n", value);
    else
        printf("%d is not present.\n", value);
}

int main() {
    /*p_d_list list = create_list(5);
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
    display_list_uniform(list2);*/
    p_d_list list3 = create_list_for_search(3);
    printf("After create_list_for_search:");
    newline();
    newline();
    display_list_uniform(list3);
    for (int i = -5; i <= power(2, list3->max_level + 1); ++i) {
        is_present(list3, i);
    }
    return 0;
}
