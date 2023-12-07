//
// Created by camil on 13/11/2023.
//

#include "part3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX_NAME_LENGTH 20


char *scanString(void)
{
    char *saisie = (char*)malloc(sizeof(char));
    scanf("%s", saisie);
    return saisie;
}


p_contact scanContact()
{
    t_contact contact;
    printf("Entrez le nom : ");
    contact.lname = scanString();

    printf("Entrez le prenom : ");
    contact.fname = scanString();

    printf("Contact enregistre :\nNom : %s\nPrenom : %s\n", contact.lname,  contact.fname);
}

int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int isValidDate(p_date date)
{
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

int SecureScanDate(p_date date)
{
    char buffer[11];
    int saisie_inval = 0;

    do
    {
        printf("Entrez la date de rendez-vous au format jj/mm/aaaa : ");
        fgets(buffer, sizeof(buffer), stdin);

        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
        }
        if (sscanf(buffer, "%2d/%2d/%4d", date->day, date->month, date->year) == 3 && isValidDate(date))
        {
            saisie_inval = 0; // Valid entry
        }
        else
        {
            printf("Format incorrect. Veuillez réessayer.\n");
            saisie_inval = 1;
        }
    }
    while(saisie_inval == 1);

    return saisie_inval;
}

int isValidTime(p_time time)
{
    return (time->hour >= 0 && time->hour <= 23 && time->min >= 0 && time->min <= 59);
}

int SecureScanTime(p_time time)
{
    char buffer[6];
    int saisie_inval = 0;

    do
    {
        printf("Entrez l'heure de rendez-vous au format hh:mm : ");
        fgets(buffer, sizeof(buffer), stdin);

        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
        }
        if (sscanf(buffer, "%2d:%2d", time->hour, time->min) == 2 && isValidTime(time))
        {
            saisie_inval = 0; // Valid entry
        }
        else
        {
            printf("Format incorrect ou heure invalide. Veuillez réessayer.\n");
            saisie_inval = 1;
        }
    }
    while(saisie_inval == 1);

    return saisie_inval;
}

int SecureScanDurate(p_time durate)
{
    char buffer[6];
    int saisie_inval = 0;

    do
    {
        printf("Entrez la durée du rendez-vous au format hh:mm : ");
        fgets(buffer, sizeof(buffer), stdin);

        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
        }
        if (sscanf(buffer, "%2d:%2d", durate->hour, durate->min) == 2 && isValidTime(durate))
        {
            saisie_inval = 0; // Valid entry
        }
        else
        {
            printf("Format incorrect ou durée invalide. Veuillez réessayer.\n");
            saisie_inval = 1;
        }
    }
    while(saisie_inval == 1);

    return saisie_inval;
}

p_appointment InfoAppointment()
{
    p_appointment myAppointment;

    printf("Entrez les informations pour le rendez-vous :\n");

    SecureScanTime(myAppointment); // Pour l'heure du rdv
    SecureScanDurate(myAppointment); // Pour la durée du rdv
    SecureScanDate(myAppointment); // Pour la date du rdv

    return myAppointment;
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