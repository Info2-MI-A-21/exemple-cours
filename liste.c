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

    PileElement* elem = malloc( sizeof(PileElement) );
    elem->valeur = valeur;
    elem->next = p->sommet;

    p->sommet = elem;

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
}



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
}