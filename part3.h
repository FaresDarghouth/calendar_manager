//
// Created by camil on 13/11/2023.
//

#ifndef CALENDAR_MANAGER_PART3_H
#define CALENDAR_MANAGER_PART3_H

typedef struct Contact
{
    char *lname;
    char *fname;
}Contact, *p_Contact;

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
} Rdv, * p_Rdv;

void InfoContact(p_Contact *, int *);
void loadContacts(p_Contact *, int *);
void freeContacts(p_Contact, int);
void InfoRdv();
void ScanDate();
void searchContact(struct Contact contacts[], int nbContacts);

#endif //CALENDAR_MANAGER_PART3_H