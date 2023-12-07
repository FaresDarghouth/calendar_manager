//
// Created by camil on 13/11/2023.
//

#ifndef CALENDAR_MANAGER_PART3_H
#define CALENDAR_MANAGER_PART3_H

typedef struct s_contact {
    char *lname;
    char *fname;
} t_contact, *p_contact;

//struct for the date
typedef struct s_date {
    int day;
    int month;
    int year;
} t_date, *p_date;


//struct for the time
typedef struct s_time {
    int hour;
    int min;
} t_time, *p_time;

//struct for an appointment
typedef struct s_appointment {
    p_time hour;
    p_time durate;
    char *object;
    p_date date;
    struct s_appointment *next;
} t_appointment, *p_appointment;

typedef struct s_entree {
    t_contact contact;
    t_appointment appointment;
} t_entree, *p_entree;


char *scanString();
p_contact scanContact();
int isLeapYear(int);
int isValidDate(p_date);
int isValidTime(p_time);
p_date SecureScanDate();
p_time SecureScanTime();

p_appointment ScanAppointment();
void getAppointment(p_appointment);



/*void searchContact(t_contact contacts[], int nbContacts);
void loadContacts(p_contact *, int *);
void freeContacts(p_Contact, int);*/

#endif //CALENDAR_MANAGER_PART3_H