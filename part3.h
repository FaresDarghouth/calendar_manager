//
// Created by camil on 13/11/2023.
//

#ifndef CALENDAR_MANAGER_PART3_H
#define CALENDAR_MANAGER_PART3_H



char *scanString(void);

typedef struct Rdv
{
    int day;
    int month;
    int year;
    int hour;
    int min;
    int dur_hour;
    int dur_min;
    char *object;
    struct Rdv* next;
} Rdv;

typedef struct Contact
{
    char *lname;
    char *fname;
    int level;
    Rdv apt;
    struct Contact **next;

}contact, *p_d_cell;

void InfoContact();
void InfoRdv();

typedef struct s_d_list {
    int max_level;
    p_d_cell *heads;
} t_d_list, *p_d_list;

#endif //CALENDAR_MANAGER_PART3_H