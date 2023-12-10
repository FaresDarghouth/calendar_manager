//
// Created by squip on 14/11/2023.
//

#ifndef CALENDAR_MANAGER_UTILS_H
#define CALENDAR_MANAGER_UTILS_H

#include "fichier.h"
#include "timer.h"

void new_line();

void jump();

void print_line();

int nb_digits(int n);

void print_n_times_char(char c, int n);

int power(int x, int n);

void print_menu();

int scan_menu();

void print_menu_after_creation();

int scan_menu_after_creation();

void print_menu_list_for_search();

int scan_menu_list_for_search();

void listen_menu();

int type_of_list();

p_d_list scan_list(int type);

p_d_cell scan_cell(p_d_list list);

int insert_method();

int scan_value();

void print_is_present_level0(p_d_list list, int value);

void print_is_present_dichotomy(p_d_list list, int value);

void print_time_level0(p_d_list list, int value);

void print_time_dichotomy(p_d_list list, int value);

void print_nb_operation_level0(p_d_list list, int value);

void print_nb_operation_dichotomy(p_d_list list, int value);

void print_both_np_operation(p_d_list list);

void print_both_np_operation_for_all_lists();

void print_both_np_operation_aligned();

#endif //CALENDAR_MANAGER_UTILS_H
