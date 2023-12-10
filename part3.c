//
// Created by camil on 13/11/2023.
//

#include "part3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAX_NAME_LENGTH 200


char *scanString() {
    char *saisie = (char*)malloc(sizeof(char));
    fgets(saisie, MAX_NAME_LENGTH, stdin);
    return saisie;
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int isValidDate(p_date date) {
    if (date->year < 1) {
        return 0; // Invalid year
    }
    if (date->month < 1 || date->month > 12) {
        return 0; // Invalid year
    }

    int daysInMonth;
    switch (date->month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
        case 2:
            if (isLeapYear(date->year))
            {
                daysInMonth = 29;
            }
            else
            {
                daysInMonth = 28;
            }
            break;
        default:
            return 0; // Invalid month
    }
    return (date->day >= 1 && date->day <= daysInMonth);
}

int isValidTime(p_time time) {
    return (time->hour >= 0 && time->hour <= 23 && time->min >= 0 && time->min <= 59);
}

p_date SecureScanDate() {
    char buffer[11];
    int valid = 0;
    p_date date = (p_date)malloc(sizeof(t_date));

    do
    {
        fflush(stdin); // Clear input buffer (stdin
        fgets(buffer, sizeof(buffer), stdin);

        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }
        if (sscanf(buffer, "%2d/%2d/%4d", &date->day, &date->month, &date->year) == 3 && isValidDate(date)) {
            valid = 0; // Valid entry
        }
        else {
            printf("Format incorrect ou date invalide. Veuillez réessayer.\n");
            valid = 1;
        }
    }
    while(valid == 1);

    return date;
}

p_time SecureScanTime() {
    char buffer[6];
    int valid = 0;
    p_time time = (p_time)malloc(sizeof(t_time));

    do
    {
        fflush(stdin); // Clear input buffer (stdin
        fgets(buffer, sizeof(buffer), stdin);

        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }
        if (sscanf(buffer, "%2d:%2d", &time->hour, &time->min) == 2 && isValidTime(time)) {
            valid = 0; // Valid entry
        }
        else {
            printf("Format incorrect ou heure invalide. Veuillez réessayer.\n");
            valid = 1;
        }
    }
    while(valid == 1);

    return time;
}

p_contact ScanContact() {
    p_contact myContact = (p_contact)malloc(sizeof(t_contact));

    printf("Entrez le nom du contact : ");
    myContact->lname = scanString(); // Pour le nom du contact

    printf("Entrez le prénom du contact : ");
    myContact->fname = scanString(); // Pour le prénom du contact

    return myContact;
}

p_appointment ScanAppointment() {
    p_appointment myAppointment = (p_appointment)malloc(sizeof(t_appointment));

    printf("Entrez la date de rendez-vous au format jj/mm/aaaa : ");
    myAppointment->date = SecureScanDate(); // Pour la date du rdv

    printf("Entrez l'heure du rendez-vous au format hh:mm : ");
    fflush(stdout);
    myAppointment->hour = SecureScanTime(); // Pour l'heure du rdv

    printf("Entrez la durée du rendez-vous au format hh:mm : ");
    myAppointment->durate = SecureScanTime(); // Pour la durée du rdv

    printf("Entrez l'objet du rendez-vous : \n");
    myAppointment->object = scanString(); // Pour l'objet du rdv

    return myAppointment;
}

char *contact_to_string(p_contact myContact) {
    char *contact = (char*)malloc(sizeof(char));
    strcat(contact, myContact->lname);
    strcat(contact, "_");
    strcat(contact, myContact->fname);
    return contact;
}

char *string_to_lowercase(char *string) {
    char *lowercase = (char*)malloc(sizeof(char));
    for (int i = 0; i < strlen(string); ++i) {
        lowercase[i] = tolower(string[i]);
    }
    return lowercase;
}

p_entry ScanEntry() {
    p_entry myEntry = (p_entry)malloc(sizeof(t_entry));
    myEntry->level = 4;
    myEntry->name = string_to_lowercase(contact_to_string(ScanContact()));
    myEntry->appointments = (p_appointment*)malloc(myEntry->level * sizeof(p_appointment));
    for (int i = 0; i < myEntry->level; ++i) {
        myEntry->appointments[i] = NULL;
    }
    return myEntry;
}

p_agenda createAgenda() {
    p_agenda myAgenda = (p_agenda)malloc(sizeof(t_agenda));
    myAgenda->max_level = 4;
    myAgenda->entries = (p_entry*)malloc(myAgenda->max_level * sizeof(p_entry));
    for (int i = 0; i < myAgenda->max_level; ++i) {
        myAgenda->entries[i] = NULL;
    }
    return myAgenda;
}

void sorted_insert(p_agenda agenda, p_entry entry) {
    int i = 0;
    while (i < agenda->max_level && agenda->entries[i] != NULL) {
        i++;
    }
    if (i == agenda->max_level) {
        agenda->max_level *= 2;
        agenda->entries = (p_entry*)realloc(agenda->entries, agenda->max_level * sizeof(p_entry));
    }
    agenda->entries[i] = entry;
}

void getAppointment(p_appointment myAppointment) {
    printf("Rendez-vous du %d/%d/%d à %d:%d, durée de %d:%d, objet : %s\n", myAppointment->date->day, myAppointment->date->month, myAppointment->date->year, myAppointment->hour->hour, myAppointment->hour->min, myAppointment->durate->hour, myAppointment->durate->min, myAppointment->object);
}

