#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif*/

void allocation()
{
    printf("\033[1;32mAllocation de mémoire\n\033[0m");

    double* tab = (double*)malloc(sizeof(double) * 4);

    tab[0] = 2.3;

    free(tab);
    int a = 0;
}