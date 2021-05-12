
#include <string.h>
#include <stdio.h>

#include "contact.h"

// programme
void tda() { 
    printf("\033[1;34mExemple de TDA\n\033[0m"); 

    List list;
    // on ne doit pas accéder aux champs de la structure
    //list.nbrContacts = 0;
    initList(&list);

    // ce code est désactivé car il n'est pas bon, il accéde directement aux champs
    // de la structure et il faut passer par les fonctions
    #if(0)
    strcpy(list.contacts[0].name, "Alice");
    list.contacts[0].id = 1;
    list.nbrContacts++;

    strcpy(list.contacts[1].name, "Bob");
    list.contacts[1].id = 123;
    list.nbrContacts++;
    #endif

    // utilisation du TDA
    addContact(&list, "Alice", 1);
    addContact(&list, "Bob", 2);
    printContactList(&list);
    
    printf("Name : %s\n", getName(&list, 1));
}