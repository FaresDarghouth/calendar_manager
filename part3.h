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
}t_contact, *p_contact;

typedef struct calendar{
    p_contact contact;
    Rdv *appointment;
    int level;
    struct calendar **next;
} calendar;


typedef struct calendar_list {
    int max_level;
    calendar **heads;
} calendar_list;


calendar_list *create_list();
char *scanString(void);
void InfoContact();
void InfoRdv();



#endif //CALENDAR_MANAGER_PART3_H