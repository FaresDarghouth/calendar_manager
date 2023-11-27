//
// Created by camil on 13/11/2023.
//

#include "part3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *scanString(void)
{
    char *saisie = (char*)malloc(sizeof(char));
    scanf("%s", saisie);
    return saisie;
}


void InfoContact()
{
    Contact contact;
    printf("Entrez le nom : ");
    contact.lname = scanString();

    printf("Entrez le prenom : ");
    contact.fname = scanString();

    printf("Contact enregistre :\nNom : %s\nPrenom : %s\n", contact.lname,  contact.fname);
}

/*void ScanDate(char date)
{
    char buffer[11];
    Rdv dday;
    Rdv dmonth;
    Rdv dyear;

    int saisie_inval = 0;
    do
    {
        printf("Entrez la date de rendez-vous au format jj/mm/aaaa : ");
        fgets(buffer, sizeof(buffer), stdin);
        {
            size_t length = strlen(buffer);
            if (length > 0 && buffer[length - 1] == '\n') {
                buffer[length - 1] = '\0';
            }
            if (sscanf(buffer, "%2d/%2d/%4d", dday.day, dmonth.month, dyear.year))
            {
                strcpy((char *) date, buffer);
                break;
            }
            else
            {
                printf("Format incorrect. Veuillez réessayer.\n");
            }
        }
        else
        {
            printf("Erreur de saisie. Veuillez réessayer.\n");
            free(buffer);

        }
    }
    while(1);
}*/

void ScanDate()
{
    char buffer[11];
    Rdv dday;
    Rdv dmonth;
    Rdv dyear;

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
    Rdv rdv;
    ScanDate();
}