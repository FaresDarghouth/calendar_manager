//
// Created by squip on 01/11/2023.
//

#include "main.h"
#include "fichier.h"
#include <stdio.h>

int main() {
    p_d_list list = create_list(5);
    print_list(list);

    insert_head(list, create_cell(18, 3));
    insert_head(list, create_cell(25, 1));
    insert_head(list, create_cell(3, 1));
    insert_head(list, create_cell(12, 3));
    printf("After insert_head:\n");
    //print_n_times("-", nb_digits(25)+9);
    printf("\n");
    //print_list(list);
    print_list_modified(list);
    return 0;
}
