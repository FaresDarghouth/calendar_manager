//
// Created by camil on 13/11/2023.
//

#include "part3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX_NAME_LENGTH 20


char *scanString() {
    char *saisie = (char*)malloc(sizeof(char));
    fgets(saisie, MAX_NAME_LENGTH, stdin);
    return saisie;
}


p_contact scanContact() {
    p_contact contact = (p_contact)malloc(sizeof(t_contact));

    printf("Entrez le nom : ");
    contact->lname = scanString();

    printf("Entrez le prenom : ");
    contact->fname = scanString();

    return contact;
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
            fflush(stdout);
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
            fflush(stdout);
            valid = 1;
        }
    }
    while(valid == 1);

    return time;
}

p_appointment ScanAppointment() {
    p_appointment myAppointment = (p_appointment)malloc(sizeof(t_appointment));

    printf("Entrez l'heure du rendez-vous au format hh:mm : ");
    fflush(stdout);
    myAppointment->hour = SecureScanTime(); // Pour l'heure du rdv

    printf("Entrez la durée du rendez-vous au format hh:mm : \n");
    fflush(stdout);
    myAppointment->durate = SecureScanTime(); // Pour la durée du rdv

    printf("Entrez l'objet du rendez-vous : \n");
    fflush(stdout);
    myAppointment->object = scanString(); // Pour l'objet du rdv

    printf("Entrez la date de rendez-vous au format jj/mm/aaaa : \n");
    fflush(stdout);
    myAppointment->date = SecureScanDate(); // Pour la date du rdv

    myAppointment->next = NULL;

    return myAppointment;
}

void getHour(p_appointment myAppointment) {
    printf("Rendez-vous à %d:%d\n", myAppointment->hour->hour, myAppointment->hour->min);
}

void getAppointment(p_appointment myAppointment) {
    printf("Rendez-vous du %d/%d/%d à %d:%d, durée de %d:%d, objet : %s\n", myAppointment->date->day, myAppointment->date->month, myAppointment->date->year, myAppointment->hour->hour, myAppointment->hour->min, myAppointment->durate->hour, myAppointment->durate->min, myAppointment->object);
}

//Fonction permettant la recherche d'un contact et propose une complétion automatique
/*void searchContact(t_contact contacts[], int nbContacts)
{
    char partialName[MAX_NAME_LENGTH];
    do {
        printf("Entrez le nom : ");
        fgets(partialName, MAX_NAME_LENGTH, stdin);
        partialName[strcspn(partialName, "\n")] = '\0'; // Supprime le saut de ligne de fgets

        if (strlen(partialName) < 3) {
            printf("Entrez au moins 3 lettres.\n");
        }
    } while (strlen(partialName) < 3);

    printf("Résultats de la recherche :\n");
    for (int i = 0; i < nbContacts; i++)
    {
        if (strncmp(contacts[i].fname, partialName, strlen(partialName)) == 0 || strncmp(contacts[i].lname, strlen(partialName)) == 0)
        {
            printf("%s %s \n", contacts[i].fname, contacts[i].lname);
        }
    }
}

void loadContacts(p_contact *contacts, int *nbContacts)
{
    FILE *file = fopen("contacts.txt", "r");
    if (file != NULL)
    {
        t_contact contact;
        while (fscanf(file, "%ms %ms", &contact.lname, &contact.fname) == 2)
        {
            *contacts = realloc(*contacts, (*nbContacts+1)*sizeof(t_contact));
            (*contacts)[*nbContacts++] = contact;
        }
        fclose(file);
    }
    else
        printf("Le fichier de contacts n'existe pas encore.\n");
}

void freeContacts(p_contact contacts, int nbContacts)
{
    for (int i = 0; i < nbContacts; ++i)
    {
        free(contacts[i].lname);
        free(contacts[i].fname);
    }
    free(contacts);
}*/