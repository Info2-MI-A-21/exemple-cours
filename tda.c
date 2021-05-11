
#include <string.h>
#include <stdio.h>

// fichier lib
typedef struct
{
    char name[20];
    int id;
} Contact;

typedef struct 
{
    Contact contacts[20];
    int nbrContacts;
} List;

// ajout / suppression -> modifier nbrContact

char* getName(List* list, int pos){
    return list->contacts[pos].name;
}

// programme
void tda() { 
    printf("\033[1;34mExemple de TDA\n\033[0m"); 

    List list;
    list.nbrContacts = 0;

    strcpy(list.contacts[0].name, "Alice");
    list.contacts[0].id = 1;
    list.nbrContacts++;

    strcpy(list.contacts[1].name, "Bob");
    list.contacts[1].id = 123;
    list.nbrContacts++;

    printf("Name : %s\n", getName(&list, 1));

    // on doit éviter pas d'accès aux champs
    list.nbrContacts = 34;
}