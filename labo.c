// Ce programme est un exemple de cours pour les laboratoires

#include "stdio.h"
#include "stdlib.h"

#define NUMBER_VAL 12

typedef struct
{
    int x;
    int y;
} Point;

void func(Point* p)
{
    p->x = 0;
    p->y = 0;
}

void labo()
{
    printf("Exemple labo\n");
    // Déclaration de la variable i // commentaire inutile
    // int i; réduit scope

    int a;
    double frequency = 2.3;

    int VarVar;
    int varVar;
    int var_var;
    int addIpHtml;

    printf("Veuillez entrer la valeur de a \n>");
    

    printf("Valeur %d", a);

    double result = a * 2.3 + 4;

    {
        Point p;
        p.x = 12;
    }

    printf("Ma valeur %d", a);

    for (int i = 4; i > 0; i--)
    {
        printf("Res 1 : %d\n", a);
        printf("Res 2 : %.2lf\n", frequency);
    }
}