#include "contact.h"
#include <string.h>
#include <stdio.h>

// La fonction de création de contact n'est pas accessible de l'extérieur

// Attention ici il faut retourner une copie et non une adresse
Contact createContact(char name[], int id){
    Contact c = {.id = id};
    strcpy(c.name, name);
    return c;  
}

void initList(List* l){
    l->nbrContacts = 0;
}

char* getName(List* list, int pos){
    return list->contacts[pos].name;
}

void addContact(List* l, char name[], int id){
    l->contacts[l->nbrContacts++] = createContact(name, id);
}

void printContactList(List* l){
    for(int i=0; i<l->nbrContacts; i++){
        // utilie uniquement pour simplifier l'écriture du printf
        Contact* c = &(l->contacts[i]);
        printf("Contact id : %d / name : %s\n", c->id, c->name);
    }
}