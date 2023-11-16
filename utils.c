//
// Created by squip on 14/11/2023.
//

#include "utils.h"

void newline() {
    printf("\n");
}

void print_line() {
    newline();
    print_n_times_char('-', 80);
    newline();
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