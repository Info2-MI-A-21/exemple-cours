#include "main.h"
#include "tda.h"

#include <stdio.h>
#include <stdlib.h>


#define DATA 14


// ne jamais faire d'include .c
//#include "saisie.c"

// déclare la fonction
void test(void);

#include "saisie.h"
#include "algo.h"


int main(void)
{
    // fichier();
    // pointer();
    // allocation();
    // labo();
    // preproc();
    // ex_mesure();

    int result;

    test();

    Data d = saisie();

    Data d2 = algo();

    tda();
}

void test(void) { printf("\033[1;32mLe test\n\033[0m"); }