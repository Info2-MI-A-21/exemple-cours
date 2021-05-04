#include <stdio.h>

#include "saisie.h"

// commenter
int foo(int val){
    return val * 2;
}

Data saisie(void)
{
    printf("\033[1;32mLa saisie\n\033[0m");
    Data d = {.value = 5, .error = 0};

    d.value = foo(d.value);

    return d;
}


