//
// Created by squip on 14/11/2023.
//

#include "utils.h"

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

void print_n_times(char *str, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s", str);
    }
}