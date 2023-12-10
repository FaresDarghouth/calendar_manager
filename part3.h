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
    p_date date;
    p_time hour;
    p_time durate;
    char *object;
} t_appointment, *p_appointment;

typedef struct s_entry {
    int level;
    char *name;
    p_appointment *appointments;
} t_entry, *p_entry;

typedef struct s_agenda {
    int max_level;
    p_entry *entries;
} t_agenda, *p_agenda;

char *scanString();
int isLeapYear(int year);
int isValidDate(p_date date);
int isValidTime(p_time time);
p_date SecureScanDate();
p_time SecureScanTime();

p_contact ScanContact();
p_appointment ScanAppointment();
char *contact_to_string(p_contact myContact);
char *string_to_lowercase(char *string);
p_entry ScanEntry();
p_agenda createAgenda();

//void sorted_insert(p_agenda agenda, p_entry entries);

void getAppointment(p_appointment);



#endif //CALENDAR_MANAGER_PART3_H