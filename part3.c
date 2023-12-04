//
// Created by camil on 13/11/2023.
//

#include "part3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*char *scanString(void)
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

void ScanDate(Rdv date)
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
        if (sscanf(buffer, "%2d/%2d/%4d", dday.day, dmonth.month, dyear.year);
        {

        }
    }
}

void InfoRdv()
{
    Rdv rdv;
    printf("Entrez la date de rendez-vous : ");
    rdv.day
}*/
/*
void new_contact(p_d_list list){
    int u = 0;
    p_d_cell contact = (p_d_cell)(malloc(sizeof(contact)));
    printf("Entrez le nom : ");
    contact -> lname = scanString();
    printf("Entrez le prénom : ");
    contact -> fname = scanString();

    if (list->heads == NULL){
        list -> heads = contact->fname;
        contact -> level = 4;
        contact -> next = (p_d_cell *)malloc(contact -> level* sizeof(p_d_cell));
        for(int i = 0; i < contact -> level; ++i){
            contact -> next[i] = NULL;
        }
    }else{
        p_d_cell temp = list -> heads;
        while (temp->next.fname[u] >= contact->fname[u]){
            temp = temp->next;
        }
        if(temp -> fname[u] > contact->fname[u]){

        }else{

        }
    }
}*/

char *scanString(void)
{
    int validation = 0;
    char temp[50];
    scanf(" %49[^\n]", temp); // Lire jusqu'au caractère de nouvelle ligne, permettant des espaces
    while(validation != strlen(temp)){
        validation = 0;
        for (int i = 0; i < strlen(temp); i++){
            if ((64 < temp[i]) && (temp[i] < 91)){
                temp[i] = temp[i] + 32;
            }
            if(97 > temp[i] || temp[i] > 122){
                printf("syntaxe invalide ! : ");
                temp[0] = '\0';
                scanf("%s", temp);
                validation = 0;
                break;
            }
            validation++;
        }
    }
    char *saisie = (char *)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy(saisie, temp); // Copier la chaîne dans la mémoire allouée
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
