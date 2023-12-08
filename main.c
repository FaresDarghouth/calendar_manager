//
// Created by squip on 01/11/2023.
//

#include "main.h"


int main() {

    calendar_list *liste = create_list();
    add_calendar(liste);
    display_list_level_uniform(*liste);
    return 0;
}
