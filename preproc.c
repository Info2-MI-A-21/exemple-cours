#include <stdio.h>

// include
#include <stdlib.h>

// define
#define SIZE 12

// macro, pas de ;
// ne pas oublier de mettre de () pour la priorité
#define MAX(a,b) (a > b ? a : b)

// Mettre en chaine
#define PRINT_INT(a) printf("Valeur de %s: %d\n", #a, a)
#define PRINT_INT_1(a) printf("Valeur de " #a " : %d\n", a)

// Token
#define TOKEN(a) printf("Valeur de var" #a " vaut : %d\n", var##a)

// Ici on défini un symbol sans valeur
#define PRODUCTION
// On peut le tester avec
#ifdef PRODUCTION
    #define SIZE_MAX 34
#else
    #define SIZE_MAX 10
#endif

#define DEBUG 0

#ifndef PRODUCTION
static void func()
{
    #if DEBUG
        printf("J'affiche le debug\n");
    #endif
}
#endif


void preproc(){
    printf("Le max %d\n", MAX(5,6));

    int somme = 45;
    PRINT_INT(somme);
    PRINT_INT_1(somme);
}