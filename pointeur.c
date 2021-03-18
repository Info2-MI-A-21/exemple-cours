#include <stdio.h>

void exercice_pointeur(){
    // Ex 2 fichier pointeur
    int tab[] = {1,2,3,4};
    int* pi = tab;

    // pi valeur => adresse = adresse tab = adresse première valeur
    // *pi => la valeur à l'adresse de : 
    printf("Val 1 : %d\n", *pi);
}

void type_et_pointeur()
{
    int i = 0x1234;
    char c = 'a';

    int* pi = &i;
    // warning du compilateur, le type est faux
    int* pi1 = &c;

    int tab[] = {1,2,3};

    int* pitab = tab + 4;
    
    int val = *(pitab++);

    printf("%d", *pi1);
}

void pointer(){
    printf("\033[1;32mExemple sur les pointeurs\n\033[0m");    

    type_et_pointeur();

    exercice_pointeur();
}