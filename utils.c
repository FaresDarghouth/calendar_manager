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

void print_both_np_operation(p_d_list list, int value) {
    srand(time(NULL));
    int random = rand() % power(2, list->max_level) + 1;
    printf("Random number: %d\n", random);
    print_nb_operation_level0(list, random);
    print_nb_operation_dichotomy(list, random);
}