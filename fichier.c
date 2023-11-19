//
// Created by squip on 01/11/2023.
//

#include "fichier.h"

/*
 * Creation of cell and list
 */

p_d_cell create_cell(int value, int level) {
    /*
     * Create a cell with a value and a level
     * The cell is initialized with a NULL next array
     */
    p_d_cell cell = (p_d_cell)malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->level = level;
    cell->next = (p_d_cell *)malloc(level * sizeof(p_d_cell));
    for (int i = 0; i < level; ++i) {
        cell->next[i] = NULL;
    }
    return cell;
}

p_d_list create_list(int max_level) {
    /*
     * Create a list with a max level
     * The list is initialized with a NULL heads array
     */
    p_d_list list = (p_d_list)malloc(sizeof(t_d_list));
    list->max_level = max_level;
    list->heads = (p_d_cell *)malloc(max_level * sizeof(p_d_cell));
    for (int i = 0; i < max_level; ++i) {
        list->heads[i] = NULL;
    }
    return list;
}

p_d_list create_list_for_search(int n) {
    p_d_list list = create_list(n);
    int nb_of_cells = power(2, n) - 1;
    for (int i = 0; i < n; ++i) {
        for (int y = power(2, i); y <= nb_of_cells; y += power(2, i + 1)) {
            sorted_insert(list, create_cell(y, i+1));
        }
    }
    return list;
}

/*-------------------------------------------------------------------------------*/

/*
 * Insertion functions
 */

void insert_head(p_d_list list, p_d_cell cell) {
    /*
     * Insert a cell at the head of the list
     * The cell is inserted at each level of the list if its level is below the list max level
     */
    if (cell->level <= list->max_level) {
        for (int i = 0; i < cell->level; ++i) {
            cell->next[i] = list->heads[i];
        }
        for (int i = 0; i < cell->level; ++i) {
            list->heads[i] = cell;
        }
    }
    else
        printf("Error: cell level is greater than list max level\n");
}

void sorted_insert(p_d_list list, p_d_cell cell) {
    /*
     * Insert a cell in the list in a sorted way
     * The cell is inserted at each level of the list if its level is below the list max level
     */
    p_d_cell temp = NULL;
    if (cell->level <= list->max_level) {
        for (int i = 0; i < cell->level; ++i) {
            if (list->heads[i] == NULL || cell->value < list->heads[i]->value) {
                cell->next[i] = list->heads[i];
                list->heads[i] = cell;
            }
            else {
                temp = list->heads[i];
                while (temp->next[i] != NULL && temp->next[i]->value < cell->value) {
                    temp = temp->next[i];
                }
                cell->next[i] = temp->next[i];
                temp->next[i] = cell;
            }
        }
    }
    else
        printf("Error: cell level is greater than list max level\n");
}

/*-------------------------------------------------------------------------------*/

/*
 * Display functions
 */

void display_list_level(p_d_list list, int level) {
    /*
     * Display the list at a given level
     */
    p_d_cell temp = NULL;
    printf("[list head_%d @-]-->", level);
    if (list->heads[level] != NULL) {
        temp = list->heads[level];
        while (temp != NULL) {
            printf("[ %d|@-]-->", temp->value);
            temp = temp->next[level];
        }
        printf("NULL");
    }
    else
        printf("NULL");
}

void display_list(p_d_list list) {
    /*
     * Display the list at each level
     */
    for (int i = 0; i < list->max_level; ++i) {
        display_list_level(list, i);
        printf("\n");
    }
}

void display_list_level_uniform(p_d_list list, int level) {
    /*
     * Display the list at a given level
     * The display is uniform, the cells are aligned
     */
    p_d_cell temp = NULL;
    p_d_cell level_0 = NULL;
    printf("[list head_%d @-]--", level);
    temp = list->heads[level];
    level_0 = list->heads[0];
    while (level_0 != NULL) {
        if (temp != level_0 || temp == NULL) {
            print_n_times_char('-', nb_digits(level_0->value)+9);
            level_0 = level_0->next[0];
        }
        else {
            printf(">[ %d|@-]--", temp->value);
            temp = temp->next[level];
            level_0 = level_0->next[0];
        }
    }
    printf(">NULL");
}

void display_list_uniform(p_d_list list) {
    /*
     * Display the list at each level
     * The display is uniform, the cells are aligned
     */
    for (int i = 0; i < list->max_level; ++i) {
        display_list_level_uniform(list, i);
        printf("\n");
    }
}
int search_value_level0(p_d_list list, int value)
{
    p_d_cell temp = NULL;
    temp = list->heads[0];
    while (temp != NULL)
    {
        if (temp->value == value)
            return 1;
        else
            temp = temp->next[0];
    }
    return 0;
}

/*int search_value_level(p_d_list list, int value, int maxlevel)
{
    p_d_cell temp = NULL;
    temp = list->heads[maxlevel];
    while (temp != NULL && temp->value != value)
    {
       if (temp->value > value)
       {
           int may = temp->value;
           temp = list->heads[maxlevel-1];
           for (int i = may; i>=0; i--)
           {
               if (temp->value == value)
                   return 1;
               else
               {
                   if (temp->value < value)
                   {
                        int may2 = li
                   }
               }
           }
       }
       else
       {

       }
    }
    return 0;
}

int search_value_level(p_d_list list, int value, int maxlevel)
{
    if (list == NULL)
        return -1;
    if (isValue(list, value,maxlevel) == 1)
        return 1;
    else
    {
        isValue(list, value, maxlevel -1)
    }
        return search_value_level(list->heads[maxlevel-1], value, maxlevel-1);
    else
        return search_value_level(list->heads[maxlevel])->next,value, maxlevel);
}*/

int isValue(p_d_list list, int value, int maxlevel)
{
    p_d_cell temp = NULL;
    temp = list->heads[maxlevel];
    while (temp != NULL)
    {
        if (temp->value == value)
            return 1;
        else
        {
            temp = temp->next[maxlevel];
            if (temp->value > value)
            {
                for (int i=temp->value; i<=0; --i)
                {
                    int may = temp->value;
                    isValue(list, value, maxlevel-1);
                    if (temp->value < value)
                    {
                        for (int j=temp->value; j < may; ++i)
                        {
                            isValue(list, value, maxlevel-1);
                        }
                    }
                }
            }
        }

    }
    return 0;
}