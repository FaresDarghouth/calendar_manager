//
// Created by camil on 13/11/2023.
//

#ifndef CALENDAR_MANAGER_PART3_H
#define CALENDAR_MANAGER_PART3_H

typedef struct Contact
{
    char *lname;
    char *fname;
}Contact;

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

void InfoContact();
void InfoRdv();


#endif //CALENDAR_MANAGER_PART3_H