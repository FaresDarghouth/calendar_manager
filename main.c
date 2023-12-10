//
// Created by squip on 01/11/2023.
//

#include "main.h"
#include "part3.h"

int main() {
    /*
     * Manual implementation of the functions
    p_d_list list = create_list(5);
    printf("After create_list (empty list):");
    jump();
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
    jump();
    display_list_uniform(list);
    print_line();

    p_d_list list2 = create_list(5);
    sorted_insert(list2, create_cell(5, 3));
    sorted_insert(list2, create_cell(4, 1));
    sorted_insert(list2, create_cell(2, 1));
    sorted_insert(list2, create_cell(1, 3));
    printf("After sorted_insert:");
    jump();
    display_list_uniform(list2);
    print_line();

    sorted_insert(list2, create_cell(3, 4));
    printf("After sorted_insert with a value of 3 and a level of 4:");
    jump();
    display_list_uniform(list2);
    print_line();

//---------------------------------------------------------------------------------------------

    p_d_list list3 = create_list_for_search(3);
    printf("After create_list_for_search:");
    jump();
    display_list_uniform(list3);
    printf("Test of search_value_level0:");
    jump();
    for (int i = -5; i <= power(2, list3->max_level + 1); ++i) {
        print_is_present_level0(list3, i);
    }

    print_line();

    printf("Test of search_value_dichotomy:");
    jump();
    for (int i = -5; i <= power(2, list3->max_level + 1); ++i) {
        print_is_present_dichotomy(list3, i);
    }

    print_line();

    print_both_np_operation_for_all_lists();*/

    //print_both_np_operation_aligned();


//---------------------------------------------------------------------------------------------


    /*
     * Implementation of the functions with the menu for the 2 first parts
     */
    setbuf(stdout, NULL);
    listen_menu();

    return 0;
}
