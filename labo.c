// Ce programme est un exemple de cours pour les laboratoires

#include "stdio.h"
#include "stdlib.h"

typedef struct {
    int x;
    int y;
} Point;

void func(Point* p){
    p->x = 0;
    p->y = 0;
}

void labo(){
    printf("Exemple labo\n");
    // Déclaration de la variable i
    int i;

    int a;
    double frequency = 2.3;

    printf("Veuillez entrer la valeur de a \n>");
    scanf("%d", &a);

    double result = a * 2.3+4;


    Point p;
    p.x = 12;

    for(i=4; i>0; i--){
        printf("Res 1 : %d\n", a);
        printf("Res 2 : %.2lf\n", frequency);
    }
}