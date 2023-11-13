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
    insert_head(list, create_cell(25, 4));
    printf("After insert_head:\n");

    print_list(list);
    return 0;
}
