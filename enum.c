#include <stdio.h>
#include <stdbool.h>

typedef enum {
    POMME, // valeur entière 0
    POIRE // 1
} Fruit;

typedef enum {
    COULEUR_ROUGE,     // 0
    COULEUR_VERT = 5,  // 5
    COULEUR_BLEU       // 6
} Couleur;

void test_enum(){
    printf("\nTest enum\n");

    Fruit fruit;    
    Fruit fruit1;

    fruit1 = POIRE;
    fruit = POMME;

    if( fruit == POMME ){
        printf("C'est une pomme\n");
    }

    //if( fruit1 == POIRE )
    if( fruit1 == 1 ){
        printf("C'est une poire\n");
    }

    Couleur couleur = COULEUR_ROUGE;

    switch (couleur)
    {
    case COULEUR_ROUGE:
        printf("C'est rouge\n");
        break;

    case COULEUR_VERT:
        printf("C'est rouge\n");
        break;
    
    default:
        break;
    }
}
