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

calendar_list *create_list() {
    /*
     * Create a list with a max level
     * The list is initialized with a NULL heads array
     */
    int max_level = 4;
    calendar_list *list = (calendar_list *)malloc(sizeof(calendar_list));
    list->max_level = max_level;

    list->heads = (calendar_cell **)malloc(max_level * sizeof(calendar_cell *));
    for (int i = 0; i < max_level; ++i) {
        list->heads[i] = NULL;
    }
    return list;
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


calendar_cell *create_cell() {
    /*
     * Create a cell with a value and a level
     * The cell is initialized with a NULL next array
     */
    calendar_cell *cell = (calendar_cell *)malloc(sizeof(calendar_cell));
    cell->contact_apt->contact = *scanContact();
    cell->contact_apt->appointment = infoAppointment();
    cell->level = 4;
    cell->next = (calendar_cell **)malloc(cell->level * sizeof(calendar_cell*));
    for (int i = 0; i < cell->level; ++i) {
        cell->next[i] = NULL;
    }
    return cell;
}

int compare_name(char* name1,char* name2)  {
    //Cas 0 = first letter not equal
    //Cas 1 = second letter not equal
    //Cas 2 = third letter not equal
    //Cas 3 = fourth letter not equal
    int i = 0;
    if(name1[0] != name2[0]){
        i = 0;
    }else{
        if(name1[1] != name2[1]){
            i = 1;
        }else{
            if(name1[2] != name2[2]){
                i = 2;
            }else{
                i = 3;
            }
        }
    }
    return i;
}

void add_calendar (calendar_list* calendar){
    int i, j, c = 1;
    calendar_cell *new_cell;
    calendar_cell *temp;
    while(c == 1){
        new_cell = create_cell();
        if(calendar->heads[3] == NULL ){
            for (i = 0; i < calendar->max_level; i++){
                calendar->heads[i] = new_cell;
            }
        }else {
            for(j = 0; j < calendar->max_level; j++){
                temp = calendar->heads[j];
                switch (compare_name(new_cell->contact_apt->contact.lname,temp->contact_apt->contact.lname)) {
                    case 0 : // first letter not equal
                        if((int) new_cell->contact_apt->contact.lname[0] < (int) temp->contact_apt->contact.lname[0]){
                            for (i = 0; i < j; i++){
                                new_cell->next[i] = temp->next[i];
                                temp->next[i] = new_cell;
                            }
                        }else{
                            while((temp->next != NULL) || ((int) new_cell->next[j]->contact_apt->contact.lname[0] < (int) temp->next[j]->contact_apt->contact.lname[0])){
                                temp = temp->next[j];
                            }
                            for (i = 0; i<j; i++){
                                new_cell->next[i] = temp->next[i];
                                temp->next[i] = new_cell;
                            }
                        }
                    case 1 : // second letter not equal
                        if((int) new_cell->contact_apt->contact.lname[1] < (int) temp->contact_apt->contact.lname[1]){
                            for (i = 0; i < j; i++){
                                new_cell->next[i] = temp->next[i];
                                temp->next[i] = new_cell;
                            }
                        }else{
                            while((temp->next != NULL) || ((int) new_cell->next[j]->contact_apt->contact.lname[1] < (int) temp->next[j]->contact_apt->contact.lname[1])){
                                temp = temp->next[j];
                            }
                            for (i = 0; i<j; i++){
                                new_cell->next[i] = temp->next[i];
                                temp->next[i] = new_cell;
                            }
                        }
                    case 2 : // third letter not equal
                        if((int) new_cell->contact_apt->contact.lname[2] < (int) temp->contact_apt->contact.lname[2]){
                            for (i = 0; i < j; i++){
                                new_cell->next[i] = temp->next[i];
                                temp->next[i] = new_cell;
                            }
                        }else{
                            while((temp->next != NULL) || ((int) new_cell->next[j]->contact_apt->contact.lname[2] < (int) temp->next[j]->contact_apt->contact.lname[2])){
                                temp = temp->next[j];
                            }
                            for (i = 0; i<j; i++){
                                new_cell->next[i] = temp->next[i];
                                temp->next[i] = new_cell;
                            }
                        }
                    case 3 : // fourth letter not equal
                        if((int) new_cell->contact_apt->contact.lname[3] < (int) temp->contact_apt->contact.lname[3]){
                            for (i = 0; i < j; i++){
                                new_cell->next[i] = temp->next[i];
                                temp->next[i] = new_cell;
                            }
                        }else{
                            while((temp->next != NULL) || ((int) new_cell->next[j]->contact_apt->contact.lname[3] < (int) temp->next[j]->contact_apt->contact.lname[3])){
                                temp = temp->next[j];
                            }
                            for (i = 0; i<j; i++){
                                new_cell->next[i] = temp->next[i];
                                temp->next[i] = new_cell;
                            }
                        }
                }
            }
        }
        printf("Enter 1 if you want to continue otherwise enter 0: ");
        scanf("%d", &c);
    }
}