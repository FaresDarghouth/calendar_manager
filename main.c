//
// Created by squip on 01/11/2023.
//

#include "main.h"
#include "fichier.h"
#include <stdio.h>

int main() {
    p_d_list list = create_list(5);
    print_list(list);

    insert(list, create_cell(18, 3));
    //insert(list, create_cell(25, 4));
    printf("After insert:\n");

    print_list(list);
    printf("plus de pb lets go");
    return 0;
}
