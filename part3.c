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
}


int saisirDate(int *jour, int *mois, int *annee) {
    char buffer[100]; // Taille du tampon pour stocker la saisie de l'utilisateur

    do {
        printf("Veuillez saisir une date (jj/mm/aaaa) : ");

        // Utilisation de fgets pour une saisie sécurisée
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d/%d/%d", jour, mois, annee) == 3) {
                // Vérifie que la saisie est correcte
                if (*jour >= 1 && *jour <= 31 && *mois >= 1 && *mois <= 12 && *annee >= 1000) {
                    return 1; // Saisie valide
                } else {
                    printf("Date invalide. Veuillez réessayer.\n");
                }
            } else {
                printf("Saisie incorrecte. Veuillez réessayer.\n");
            }
        } else {
            printf("Erreur lors de la saisie. Veuillez réessayer.\n");
        }

    } while (1);
}

void ScanDate()
{
    char buffer[11];
    t_rdv dday;
    t_rdv dmonth;
    t_rdv dyear;

    int saisie_inval = 0;
    do
    {
        printf("Entrez la date de rendez-vous au format jj/mm/aaaa : ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%2d/%2d/%4d", dday.day, dmonth.month, dyear.year);
        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
        }
        if (sscanf(buffer, "%2d/%2d/%4d", dday.day, dmonth.month, dyear.year))
        {
            saisie_inval =1;
        }
        else
        {
            printf("Format incorrect. Veuillez réessayer.\n");
        }
        free(buffer);
    }
    while(saisie_inval==0);
}

void InfoRdv()
{
    t_rdv rdv;
    ScanDate();
}

//Fonction permettant la recherche d'un contact et propose une complétion automatique
void searchContact(t_contact contacts[], int nbContacts)
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