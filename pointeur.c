#include <stdio.h>

void exercice_pointeur()
{
    // Ex 2 fichier pointeur
    int tab[] = {1, 2, 3, 4};
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

    int tab[] = {1, 2, 3};

    int* pitab = tab + 4;

    int val = *(pitab++);

    printf("%d", *pi1);
}

void pointeur_inc()
{
    char* txt = "Bonjour";
    char* pc = txt;

    char res = (*pc);  // res = B
    res = res + 1;  // res = C

    puts("Example post et pre inc");
    printf("Val 1 : %c\n", *pc);
    printf("Val 2 : %c\n", (*pc) + 1);
    printf("Val 3 : %c\n", *pc++);
    pc = txt;
    printf("Val 4 : %c\n", *++pc);
}

void pointer_text()
{
    char txt1[] = "Hello";
    char* txt2 = "Hello";

    // identique
    char c1 = txt1[2];
    char c2 = txt2[2];
}

void func_void(void* add)
{
    // cast de pointeur
    char* pc = (char*)add;
    char c = *pc;

    // interdit
    // char c1 = *add;
}

void arithm_pointer()
{
    char text[] = "Hello";
    char* pc1 = text;
    char* pc2 = &text[0];
    pc1 = pc1 + 5;
}

void ex_10()
{
    int tab[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int* p1 = tab;
    int* p2 = &tab[4];
    printf("Val1 = %d\n", (p2 - p1));
    printf("Val2 = %d\n", *(++p2));
    printf("Val3 = %d\n", *(p2 - 2));
    printf("Val4 = %d\n", *(p2));
}

void pointer()
{
    printf("\033[1;32mExemple sur les pointeurs\n\033[0m");

    int val = 12;
    int* pi = &val;

    int tab[] = {1, 2, 3};
    void* pv = tab;  // stock l'adresse tab

    ex_10();

    // fwrite(tab, sizeof(int), 3, f);

    type_et_pointeur();

    exercice_pointeur();

    pointeur_inc();
}