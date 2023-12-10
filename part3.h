//
// Created by maxen on 08/12/2023.
//

#ifndef UNTITLED2_PART3_H
#define UNTITLED2_PART3_H

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
    p_time hour;
    p_time durate;
    char *object;
    p_date date;
    struct s_appointment *next;
}t_appointment, *p_appointment;



typedef struct calendar{
    t_contact *contact;
    t_appointment appointment;
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
calendar_cell *create_cell(t_contact*);
calendar_list *create_list();
void InfoContact();
void InfoRdv();
//void add_calendar(calendar_list*);
p_contact scanContact();
int isLeapYear(int);
int isValidDate(p_date);
int isValidTime(p_time time);
p_date SecureScanDate();
p_time SecureScanTime();
p_appointment ScanAppointment();
void getHour(p_appointment);
void display_list_uniform(calendar_list*);
void getAppointment(p_appointment);
void insert_in_calendar(calendar_list*, calendar_cell *,int);
void display_list_level_uniform(calendar_list *, int);
void sorted_insert(calendar_list *list, calendar_cell *cell, int level);

#endif //CALENDAR_MANAGER_PART3_H

#endif //UNTITLED2_PART3_H
