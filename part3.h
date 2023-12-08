//
// Created by camil on 13/11/2023.
//


#ifndef CALENDAR_MANAGER_PART3_H
#define CALENDAR_MANAGER_PART3_H

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

typedef struct Contact
{
    char *lname;
    char *fname;
}t_contact, *p_contact;



//struct for the date
typedef struct s_date
{
    int day;
    int month;
    int year;
}t_date, *p_date;

//struct for the time
typedef struct s_time
{
    int hour;
    int min;
}t_time, *p_time;

//struct for an appointment
typedef struct s_appointment
{
    t_time hour;
    t_time durate;
    char *object;
    t_date date;
    struct s_appointment *next;
}t_appointment, *p_appointment;

typedef struct s_entree
{
    t_contact contact;
    t_appointment appointment;
}t_entree, *p_entree;



typedef struct calendar{
    p_entree contact_apt;
    int level;
    struct calendar **next;
} calendar_cell;


typedef struct calendar_list {
    int max_level;
    calendar_cell **heads;
} calendar_list;

int compare_name(char*,char*);
p_appointment InfoAppointment();
char *scanString(void);
calendar_cell *create_cell();
calendar_list *create_list();
void InfoContact();
void InfoRdv();
void add_calendar(calendar_list*);
p_contact scanContact();
void display_list_level_uniform(calendar_list);

#endif //CALENDAR_MANAGER_PART3_H