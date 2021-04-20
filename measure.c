
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

Data readMeasure(int day, char* filename)
{
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (day < START_DAY)
    {
        exit(EXIT_FAILURE);
    }

    Data res = {0};
    int sizeStruct = sizeof(Data);
    int offset = (day - START_DAY) * sizeStruct;
    fseek(f, offset, SEEK_SET);
    fread(&res, sizeStruct, 1, f);
    fclose(f);
    return res;
}

void readMeasures(int day, char* filename, size_t nbrMeasure, Data tab[])
{
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (day < START_DAY)
    {
        exit(EXIT_FAILURE);
    }

    int sizeStruct = sizeof(Data);
    int offset = (day - START_DAY) * sizeStruct;
    fseek(f, offset, SEEK_SET);
    fread(tab, sizeStruct, nbrMeasure, f);
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

        FILE* f = fopen(filename, "a");

        // Ne pas oublier le test d'ouverture
        if (f == NULL) exit(EXIT_FAILURE);

        fwrite(&d, sizeof(Data), 1, f);

        fclose(f);
    }

    // lecture
    FILE* f = fopen(filename, "r");
    if (f == NULL) exit(EXIT_FAILURE);

    // affiche la taille
    int pos = ftell(f);
    fseek(f, 0, SEEK_END);
    printf("Size : %ld", ftell(f));
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