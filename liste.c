#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//      type  |  Alias
typedef int      MonType;

/*struct {
    int val;
};*/
// on l'utilise avec typedef
typedef struct { int val; } MyData;
//         type            | alias


struct Test{
    int val;
};
typedef struct Test StrcutTest;
//     type        | Alias


typedef struct Test1 { int val; } StrcutTest1;
//           Type                 | Alias



typedef struct Data
{
    int value;
    struct Data* pointeur;
} Data;



typedef struct PileElement {
    double valeur;
    struct PileElement* next;
} PileElement;

typedef struct Pile {
    PileElement* sommet;
} Pile;

bool empiler(Pile* p, double valeur){
    if( p == NULL ){
        return false;
    }

    PileElement* elem = (PileElement*)malloc( sizeof(PileElement) );
    if( elem == NULL ){
        return false;
    }

    elem->valeur = valeur;
    elem->next = p->sommet;

    p->sommet = elem;

    return true;
}

bool depiler(Pile* p, double* valeur){
    if( p == NULL || p->sommet == NULL ){
        return false;
    }

    PileElement* courant = p->sommet;

    *valeur = courant->valeur;

    p->sommet = courant->next;

    free( courant );

    return true;
}

int pile_nbr(Pile* p){
    int cpt = 0;
    PileElement* courant = p->sommet;
    while( courant != NULL ){
        cpt++;
        courant = courant->next;
    }
    return cpt;
}

void test_pile() {
    Pile p = {0};

    empiler(&p, 34);
    empiler(&p, 12);
    empiler(&p, 6);

    printf("Nbr : %d\n", pile_nbr(&p));

    double val;
    while( depiler(&p, &val) ){
        printf("Depiler : %.2lf\n", val);
    }
}


// File
typedef struct
{
    int id;
    double value;
} DataFile;

struct ElemFile
{
    DataFile val;
    struct ElemFile* next;
};
typedef struct ElemFile ElemFile;
// ==
/*
typedef struct ElemFile
{
    Data val;
    struct ElemFile* next;
} ElemFile;*/

typedef struct
{
    ElemFile* head;
    ElemFile* queue;
} File;

bool inserer_file(File* f, DataFile* v)
{
    if (f == NULL)
    {
        return false;
    }

    ElemFile* e = malloc(sizeof(ElemFile));
    if (e == NULL)
    {
        return false;
    }

    e->val = *v;
    e->next = NULL;
    
    if( f->head == NULL ){
        f->head = e;
    }
    else{
        f->queue->next = e;
    }

    f->queue = e;

    return true;
}

bool retirer_file(File* f, DataFile* v)
{
    if (f == NULL || f->head == NULL)
    {
        return false;
    }

    ElemFile* cur = f->head;
    *v = cur->val;

    f->head = cur->next;

    if( f->head == NULL ){
        f->queue = NULL;
    }

    free(cur);

    return true;
}

bool find_file(File* f, int id, DataFile* v){

    if(f->head == NULL){
        return false;
    }

    ElemFile* current = f->head;
    do
    {
        if (current->val.id == id)
        {
            *v = current->val;
            return true;
        }
        current = current->next;
    } while (current != NULL);

    return false;
}

int count_file(File* f){
    ElemFile* current = f->head;
    int cpt = 0;
    while ( current != NULL )
    {
        cpt++;
        current = current->next;
    }
    return cpt;
}

void test_file()
{
    printf("\nTest file\n");
    File f = {0};
    DataFile d = {.id=12, .value=5.6};

    DataFile dd = (DataFile){4, 4.1};

    inserer_file(&f, &d);
    inserer_file(&f, &dd);
    inserer_file(&f, &((DataFile){4, 4.1}));
    inserer_file(&f, &((DataFile){2, 2.6}));
    inserer_file(&f, &((DataFile){3, 3.2}));

    DataFile v;

    if(find_file(&f, 2, &v)){
        printf("Elem find : %d  / %.2lf\n", v.id, v.value);
    }

    while (retirer_file(&f, &v))
    {
        printf("Elem : %d  / %.2lf\n", v.id, v.value);
    }
}

/*
- FIFO, first in, first out
- inserer
- retirer
- afficher la liste des éléments
*/


void liste(){
    printf("\033[1;34mExemple de liste\n\033[0m");

    struct Test maVariable;

    Data d1 = {.value = 1, .pointeur = NULL};
    Data d2 = {.value = 2, .pointeur = &d1};
    Data d3 = {.value = 3, .pointeur = &d2};
    Data d4 = {.value = 4, .pointeur = &d3};
    d1.pointeur = &d4;

    printf("\nHello\n");

    int val = d1.pointeur->value;
    printf("La valeur = %d\n", val);

    val = d1.pointeur->pointeur->pointeur->pointeur->pointeur->pointeur->pointeur->value;
    printf("La valeur = %d\n", val);

    test_pile();

    test_file();
}