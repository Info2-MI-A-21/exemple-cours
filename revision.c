#include <stdio.h>
#include <string.h>

void revision(){
    printf("Revision\n");

    char* txt = "aabb";
    double res;

    /*
      scanf : saisie
      sscanf : chaîne
      fscanf : lire fichier
    */

   /*
    fscanf : retourne nombre de valeur conv
           : EOF
   */

    int ret = sscanf(txt, "%lf", &res);
    if( ret == 1 ){
        printf("Res : %.2lf\n", res);
    }
    else{
        printf("Pas le bon format\n");
    }

    FILE* f = fopen("revision.txt", "w");
    fputs("a,1.234", f);
    fclose(f);

    f = fopen("revision.txt", "r");
    ret = fscanf(f,"a,%lf", &res);
    fclose(f);    
}