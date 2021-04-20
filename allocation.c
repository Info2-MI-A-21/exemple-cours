#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif*/

void ex4()
{
    printf("Ex 4 allocation\n");

    int size = 7;
    int* tab = (int*)malloc(sizeof(int) * size);
    if( tab == NULL )
        exit(EXIT_FAILURE);

    for(int i = 0; i<20; i++){
        tab[i] = i;
        
        if( i < size )
            tab[i] = i;
        else{
            int* tmp = (int*)malloc(sizeof(int) * size * 2);

            if( tmp == NULL ){
                free(tab);
                exit(EXIT_FAILURE);
            }

            memcpy(tmp, tab, sizeof(int)*size);
            printf("La nouvelle taille du tableau vaut : %d\n", size );

            size *= 2;

            free(tab); // libèrer la première zone
            tab = tmp; // redirige tab sur la nouvelle zone
        }
    }

    free(tab);
}

void ex4_bis()
{
    printf("Ex 4 bis allocation\n");
    int size = 7;
    int* tab = (int*)malloc(sizeof(int) * size);
    if( tab == NULL )
        exit(EXIT_FAILURE);

    for(int i = 0; i<20; i++){
        if( i < size )
            tab[i] = i;
        else{
            int* tmp = (int*)realloc(tab, sizeof(int) * size * 2);
            //tab = (int*)realloc(tab, sizeof(int) * size * 2);
            if( tmp == NULL )
            {
                free(tab);
                exit(EXIT_FAILURE);
            }

            size = size * 2;
            printf("La nouvelle taille du tableau vaut : %d\n", size );

            tab = tmp;
        }
    }

    free(tab);
}

void allocation()
{
    printf("\033[1;32mAllocation de mémoire\n\033[0m");

    double* tab = (double*)malloc(sizeof(double) * 4);

    tab[0] = 2.3;

    free(tab);
    int a = 0;
}