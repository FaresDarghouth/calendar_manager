//
// Created by camil on 13/11/2023.
//

#ifndef CALENDAR_MANAGER_PART3_H
#define CALENDAR_MANAGER_PART3_H

typedef struct s_contact
{
    char *lname;
    char *fname;
}t_contact, *p_contact;

char *scanString(void);


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

p_contact scanContact();
int isLeapYear(int);
int isValidDate(p_date);
int SecureScanDate(p_date);
int isValidTime(p_time);
int SecureScanTime(p_time);
int SecureScanDurate(p_time);

p_appointment InfoAppointment();



/*void searchContact(t_contact contacts[], int nbContacts);
void loadContacts(p_contact *, int *);
void freeContacts(p_Contact, int);*/

#endif //CALENDAR_MANAGER_PART3_H