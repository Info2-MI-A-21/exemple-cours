
#include <stdio.h>

#include "algo.h"

Data algo(void)
{
    printf("\033[1;31mAlgo\n\033[0m");
    Data d = saisie();
    d.value = 45;
    return d;
}