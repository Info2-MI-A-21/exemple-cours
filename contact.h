#pragma once

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

char* getName(List* list, int pos);
void addContact(List* l, char name[], int id);
void printContactList(List* l);
void initList(List* l);