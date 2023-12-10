
#include "part3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"



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


char *scanString(void)
{
    int validation = 0;
    char temp[50];
    scanf(" %49[^\n]", temp);
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
    p_contact contact = (p_contact)malloc(sizeof(t_contact));
    printf("Entrez le nom : ");
    contact->lname = scanString();
    printf("Entrez le prenom : ");
    contact->fname = scanString();

    printf("Contact enregistre :\nNom : %s\nPrenom : %s\n", contact->lname,  contact->fname);
    printf("L1");
    return contact;
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


calendar_cell *create_cell(p_entree entree, int level) {
    /*
     * Create a cell with a value and a level
     * The cell is initialized with a NULL next array
     */
    calendar_cell *cell = (calendar_cell *)malloc(sizeof(calendar_cell));
    cell->contact_apt = entree;
    cell->level = level;
    cell->next = (calendar_cell **)malloc(level* sizeof(calendar_cell*));
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
    int i;
    printf("%s", name1);
    printf("%s", name2);
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

void display_list_level_uniform(calendar_list list) {
    /*
     * Display the list at a given level
     * The display is uniform, the cells are aligned
     */
    calendar_cell *temp = NULL;
    calendar_cell *level_0 = NULL;
    printf("[list head_%d @-]--", 4);
    temp = list.heads[4];
    level_0 = list.heads[0];
    while (level_0 != NULL) {
        if (temp != level_0 || temp == NULL) {
            print_n_times_char('-', nb_digits((int) strlen(level_0->contact_apt->contact.lname))+9);
            level_0 = level_0->next[0];
        }
        else {
            printf(">[ %s|@-]--", temp->contact_apt->contact.lname);
            temp = temp->next[4];
            level_0 = level_0->next[0];
        }
    }
    printf(">NULL");
}

void add_calendar (calendar_list* calendar){
    int i, j, c = 1;
    calendar_cell *new_cell;
    calendar_cell *temp;
    calendar->max_level = 4;
    p_entree entree = (t_entree *)malloc(sizeof(t_entree));
    while(c == 1){
        entree->contact = *scanContact();
        //new_cell = create_cell();
        if(calendar->heads[3] == NULL ){
            new_cell = create_cell(entree, 4);
            for (i = 0; i < calendar->max_level; i++){
                calendar->heads[i] = new_cell;
                printf("%s", calendar->heads[i]->contact_apt->contact.lname);
            }
        }else {
            for(j = 0; j < calendar->max_level; j++){
                temp = calendar->heads[j];
                switch (compare_name(entree->contact.lname,temp->contact_apt->contact.lname)) {
                    case 0 : // first letter not equal
                        new_cell = create_cell(entree, 4);
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
                        new_cell = create_cell(entree, 3);
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
                        new_cell = create_cell(entree, 2);
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
                        new_cell = create_cell(entree, 1);
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
        display_list_level_uniform(*calendar);
        printf("Enter 1 if you want to continue otherwise enter 0: ");
        scanf("%d", &c);
    }
}


