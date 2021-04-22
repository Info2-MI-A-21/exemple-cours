
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"

#define START_DAY 20
#define NBR_MEASURE 10
#define NBR_DAY 20
#define NBR_READ_MEASURES 5


typedef struct
{
    int x;
    double value;
} Measure;

typedef struct
{
    int day;
    Measure measure[NBR_MEASURE];
} Data;

void resetData(Data* d)
{
    d->day = 0;
    for(size_t i = 0; i<NBR_MEASURE; i++){
        d->measure[i].value = 0.0;
        d->measure[i].x = 0;
    }   
}

// on copie la valeur de retour
int func1(){
    int a = 12;
    return a;
}

Data readMeasure(int day, char* filename)
{
    int res = func1();

    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (day < START_DAY || day > START_DAY + NBR_DAY)
    {
        printf("Erreur avec le numéro du jour\n");
        exit(EXIT_FAILURE);
    }

    Data d = {0};
    int nbrData = day - START_DAY;
    fseek(f, sizeof(Data) * nbrData, SEEK_SET );
    if( fread(&d, sizeof(Data), 1, f) != 1 ){
        printf("Erreur en lecture\n");
        exit(EXIT_FAILURE);
    }
    fclose(f);
    return d;
}

void readMeasures(int day, char* filename, size_t nbrMeasure, Data tab[])
{
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (day < START_DAY || day > START_DAY + NBR_DAY)
    {
        printf("Erreur avec le numéro du jour\n");
        exit(EXIT_FAILURE);
    }

    int nbrData = day - START_DAY;
    fseek(f, sizeof(Data) * nbrData, SEEK_SET );

    if( fread(tab, sizeof(Data), nbrMeasure, f) != nbrMeasure ){
        printf("Erreur en lecture tableau\n");
        exit(EXIT_FAILURE);
    }
    fclose(f);
}

void ex_mesure()
{
    char* filename = "ex_file2.dat";
    srand(time(NULL));

    // Pour supprimer le fichier
    FILE* f1 = fopen(filename, "w");
    fclose(f1);

    // On simule une mesure par jour
    for (int i = 0; i < NBR_DAY; i++)
    {
        Data d = {0};
        d.day = START_DAY + i;
        for (int m = 0; m < NBR_MEASURE; m++)
        {
            d.measure[m].x = m;
            d.measure[m].value = (double)(rand()) / RAND_MAX * 100.0;
        }

        f1 = fopen(filename, "a");

        // Ne pas oublier le test d'ouverture
        if (f1 == NULL) exit(EXIT_FAILURE);

        if( fwrite(&d, sizeof(Data), 1, f1) != 1 )
            exit(EXIT_FAILURE);

        // on doit fermer le fichier
        fclose(f1);
    }

    // lecture
    FILE* f = fopen(filename, "r");
    if (f == NULL) exit(EXIT_FAILURE);

    // affiche la taille en byte
    int pos = ftell(f);
    fseek(f, 0, SEEK_END);
    printf("Size : %ld\n", ftell(f));
    fseek(f, 0, SEEK_SET);
    fclose(f);

    const int NumDayToRead = 30;

    Data res = readMeasure(NumDayToRead, filename);

    Data res_tab[NBR_READ_MEASURES];
    readMeasures(NumDayToRead, filename, NBR_READ_MEASURES, res_tab);

    printf("\nTest de la lecutre\n");
    // Test de la lecture
    if( NumDayToRead == res.day ){
        printf("\033[1;32mLecture d'un résultat ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture d'un résultat pas bon\n\033[0m");
    }

    if( res.measure[0].x == 0 ){
        printf("\033[1;32mLecture mesure 1 ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture mesure 1 pas bon\n\033[0m");
    }


    if( (NumDayToRead + 1) == res_tab[1].day ){
        printf("\033[1;32mLecture d'un résultat ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture d'un résultat pas bon\n\033[0m");
    }

    if( res_tab[1].measure[0].x == 0 ){
        printf("\033[1;32mLecture mesure tab 1 ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture mesure tab 1 pas bon\n\033[0m");
    }

    printf("End ex\n");
}