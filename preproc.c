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

// PRINT_INT(foo)
// printf("Valeur de %s: %d\n", "foo", foo)

#define PRINT_INT_1(a) printf("Valeur de " #a " : %d\n", a)

// Token
#define TOKEN(a) printf("Valeur de var" #a " vaut : %d\n", var##a)

// Ici on défini un symbol sans valeur (on peut l'utiliser comme un bool)
#define PRODUCTION
// On peut le tester avec
#ifdef PRODUCTION
    #define SIZE_MAX 34
#else
    #define SIZE_MAX 10
#endif

#define DEBUG 0

// on peut supprimer une partie du code. 
// le code ne fait plus partie du fichier source et n'est pas compilé
#ifndef PRODUCTION
static void func()
{
    #if DEBUG
        printf("J'affiche le debug\n");
    #endif
}
#endif

// le const prend une place en mémoire mais c'est une vraie variable avec un type
// define on peut l'utiliser pour la taille des tableaux
// const, on peut le passer en pointeur à des fonctions
const int BUFFER_SIZE_C = 100;
#define BUFFER_SIZE_D 100

static void func(int* i){

}

void preproc(){
    printf("Le max %d\n", MAX(5,6));

    int array1[BUFFER_SIZE_D];
    int array2[BUFFER_SIZE_C];

    //func(&BUFFER_SIZE_C);

    int somme = 45;
    PRINT_INT(somme);
    PRINT_INT_1(somme);
}