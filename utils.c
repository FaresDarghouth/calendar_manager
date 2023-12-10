//
// Created by squip on 14/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <time.h>

void new_line() {
    printf("\n");
}

void jump() {
    printf("\n\n");
}

void print_line() {
    new_line();
    print_n_times_char('-', 80);
    jump();
}

int nb_digits(int n) {
    int count = 0;
    if (n == 0)
        return 1;
    if (n < 0)
        ++count;
    while (n != 0) {
        n /= 10;
        ++count;
    }
    return count;
}

void print_n_times_char(char c, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%c", c);
    }
}

int power(int x, int n) {
    int result = 1;
    for (int i = 0; i < n; ++i) {
        result *= x;
    }
    return result;
}

void print_menu() {
    printf("What would you like to do ?");
    jump();
    printf("\t1. Create a list\n");
    printf("\t2. Quit\n");
    jump();
}

int scan_menu() {
    int choice;
    print_menu();
    do {
        fflush(stdin);
        scanf("%d", &choice);
        if (choice != 1 && choice != 2)
            printf("Your choice must be between 1 or 2.\n");
    } while (choice != 1 && choice != 2);
    return choice;
}

void print_menu_after_creation() {
    printf("What would you like to do ?");
    jump();
    printf("\t1. Display the list\n");
    printf("\t2. Create a cell to insert\n");
    printf("\t99. Quit\n");
}

int scan_menu_after_creation() {
    int choice;
    print_menu_after_creation();
    do {
        fflush(stdin);
        scanf("%d", &choice);
        if (choice != 1 && choice != 2 && choice != 99)
            printf("Your choice must be 1, 2, or 99.\n");
    } while (choice != 1 && choice != 2 && choice != 99);
    return choice;
}

void print_menu_list_for_search() {
    printf("What would you like to do ?");
    jump();
    printf("\t1. Display the list\n");
    printf("\t2. Search for a value\n");
    printf("\t99. Quit\n");
}

int scan_menu_list_for_search() {
    int choice;
    print_menu_list_for_search();
    do {
        fflush(stdin);
        scanf("%d", &choice);
        if (choice != 1 && choice != 2 && choice != 99)
            printf("Your choice must be 1, 2, or 99.\n");
    } while (choice != 1 && choice != 2 && choice != 99);
    return choice;
}

void listen_menu() {
    int choice = scan_menu();
    switch (choice) {
        case 1: {
            fflush(stdout);
            int type = type_of_list();
            p_d_list list = scan_list(type);
            jump();
            printf("List has been created.");
            jump();
            int choice2;
            if (type == 1) {
                choice2 = scan_menu_after_creation();
                while (1) {
                    switch (choice2) {
                        case 1: {
                            jump();
                            display_list_uniform(list);
                            jump();
                            print_line();
                            break;
                        }
                        case 2: {
                            int value = scan_value();
                            print_is_present_level0(list, value);
                            print_is_present_dichotomy(list, value);
                            print_time_level0(list, value);
                            print_time_dichotomy(list, value);
                            print_nb_operation_level0(list, value);
                            print_nb_operation_dichotomy(list, value);
                            break;
                        }
                        case 99: {
                            printf("Goodbye.");
                            exit(0);
                        }
                        default:
                            break;
                    }
                    choice2 = scan_menu_after_creation();
                }
            }
            else {
                choice2 = scan_menu_list_for_search();
                while (1) {
                    switch (choice2) {
                        case 1: {
                            jump();
                            display_list_uniform(list);
                            jump();
                            print_line();
                            break;
                        }
                        case 2: {
                            p_d_cell cell = scan_cell(list);
                            int method = insert_method();
                            switch (method) {
                                case 1:
                                    insert_head(list, cell);
                                    break;
                                case 2:
                                    sorted_insert(list, cell);
                                    break;
                                default:
                                    break;
                            }
                            print_line();
                            printf("Cell has been inserted.");
                            print_line();
                            break;
                        }
                        case 99: {
                            printf("Goodbye.");
                            exit(0);
                        }
                        default:
                            break;
                    }
                    choice2 = scan_menu_list_for_search();
                }
            }
        }
        case 2: {
            printf("Goodbye.");
            exit(0);
        }
        default:
            break;
    }
}

int type_of_list() {
    int type;
    do {
        fflush(stdin);
        printf("Enter the type of list:\n");
        jump();
        printf("\t1. Normal list\n");
        printf("\t2. List for researches\n");
        scanf("%d", &type);
        if (type != 1 && type != 2)
            printf("Your choice must be 1 or 2.\n");
    } while (type != 1 && type != 2);
    return type;
}

p_d_list scan_list(int type) {
    int max_level;
    printf("Enter the max level of the list: ");
    do {
        fflush(stdin);
        scanf("%d", &max_level);
        if (max_level < 1)
            printf("The max level of the list must be greater than 0.\n");
    } while (max_level < 1);
    switch (type) {
        case 1:
            scanf("%d", &max_level);
            return create_list(max_level);
        case 2:
            scanf("%d", &max_level);
            return create_list_for_search(max_level);
        default:
            return NULL;
    }
}

p_d_cell scan_cell(p_d_list list) {
    int value, level;
    printf("Enter the value of the cell: ");
    scanf("%d", &value);
    do {
        fflush(stdin);
        printf("Enter the level of the cell: ");
        scanf("%d", &level);
        if (level > list->max_level)
            printf("The level of the cell must be less than or equal to the max level of the list.\n");
    } while (level > list->max_level);
    return create_cell(value, level);
}

int insert_method() {
    int method;
    do {
        printf("Enter the method of insertion:\n");
        printf("1. Insert in head\n");
        printf("2. Sorted insertion\n");
        scanf("%d", &method);
        if (method != 1 && method != 2)
            printf("Your choice must be 1 or 2.\n");
    } while (method != 1 && method != 2);
    return method;
}

int scan_value() {
    int value;
    printf("Enter the value to search: ");
    scanf("%d", &value);
    return value;
}

void print_is_present_level0(p_d_list list, int value) {
    if (search_value_level0(list, value) == 1)
        printf("%d is present.\n", value);
    else
        printf("%d is not present.\n", value);
}

void print_is_present_dichotomy(p_d_list list, int value) {
    if (search_value_dichotomy(list, value) == 1)
        printf("%d is present.\n", value);
    else
        printf("%d is not present.\n", value);
}

void print_time_level0(p_d_list list, int value) {
    startTimer();
    search_value_level0(list, value);
    stopTimer();
    printf("Time for search_value_level0: ");
    displayTime();
}

void print_time_dichotomy(p_d_list list, int value) {
    startTimer();
    search_value_dichotomy(list, value);
    stopTimer();
    printf("Time for search_value_dichotomy: ");
    displayTime();
}

void print_nb_operation_level0(p_d_list list, int value) {
    printf("Number of operations for search_value_level0: %d\n", nb_operation_search_value_level0(list, value));
}

void print_nb_operation_dichotomy(p_d_list list, int value) {
    printf("Number of operations for search_value_dichotomy: %d\n", nb_operation_search_value_dichotomy(list, value));
}

void print_both_np_operation(p_d_list list) {
    srand(time(NULL));
    int random = rand() % power(2, list->max_level) + 1;
    printf("For a list of %d levels and %d elements:\n", list->max_level, power(2, list->max_level));
    printf("Random number: %d\n", random);
    print_nb_operation_level0(list, random);
    print_nb_operation_dichotomy(list, random);
}

void print_both_np_operation_for_all_lists() {
   for (int i = 1; i <= 3; ++i) {
       p_d_list list = create_list_for_search(i);
       print_both_np_operation(list);
       jump();
   }
}

void print_both_np_operation_aligned() {
    for (int i = 1; i <= 17; ++i) {
        p_d_list list = create_list_for_search(i);
        int value = power(2, list->max_level);
        printf("%d;", nb_operation_search_value_level0(list, value));
    }
    new_line();
    for (int i = 1; i <= 17; ++i) {
        p_d_list list = create_list_for_search(i);
        int value = power(2, list->max_level);
        printf("%d;", nb_operation_search_value_dichotomy(list, value));
    }
}