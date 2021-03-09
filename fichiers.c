#include "stdio.h"
#include "stdlib.h"

void files_fgetc()
{
    FILE* fp = fopen("f1.txt", "r");

    // ON DOIT TOUJOURS CONTROLLER L OUVERTURE
    if (fp == NULL) 
        exit(EXIT_FAILURE);

    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    };

    // ici le curseur est sur la fin du fichier EOF
    c = 'a';
    long pos = ftell(fp);
    c = fgetc(fp);  // on voit que c donne toujours EOF
    pos = ftell(fp);  // la position ne change plus

    fclose(fp);
}

void read_fgets()
{
    FILE* fp = fopen("f1.txt", "r");
    
    // ON DOIT TOUJOURS CONTROLLER L OUVERTURE
    if (fp == NULL) 
        exit(EXIT_FAILURE);

    long int p = ftell(fp);
    char txt[30];
    char* c = fgets(txt, 29, fp);  // 1ere ligne
    p = ftell(fp);
    c = fgets(txt, 29, fp);  // 2ème ligne
    p = ftell(fp);
    c = fgets(txt, 29, fp);  // c == NULL car tout est lu
    p = ftell(fp);  // la position ne change pas
    fclose(fp);
}

#define SMALL_BUFF 5
void read_fgets_small_buff()
{
    FILE* fp = fopen("f1.txt", "r");
    
    // ON DOIT TOUJOURS CONTROLLER L OUVERTURE
    if (fp == NULL) 
        exit(EXIT_FAILURE);

    long int p = ftell(fp);
    char txt[SMALL_BUFF];

    char* c = fgets(txt, SMALL_BUFF, fp);  // txt == Hell
    c = fgets(txt, SMALL_BUFF, fp);  // o\n  Attention fgets s'arrête sur le \n
    c = fgets(txt, SMALL_BUFF, fp);  // foo
    fclose(fp);
}

void files_fscanf()
{
    FILE* fp = fopen("meas.txt", "r");
    int i1, i2;

    int ret = fscanf(fp, "%d,%d", &i1, &i2);
    ret = fscanf(fp, "%d,%d", &i1, &i2);
    ret = fscanf(fp, "%d,%d", &i1, &i2);  // ret = 0 car il y a une lettre au début de la ligne
    ret = fscanf(fp, "%d,%d", &i1, &i2);  // idem, toujours 0 tant que la lettre n'est pas lue

    char c1;
    ret = fscanf(fp, "%c,%d", &c1, &i2);
    ret = fscanf(fp, "%c,%d", &c1, &i2);  // ret == -1 car c'est la fin du fichier
    fclose(fp);
}

void write_putc()
{
    FILE* fp = fopen("putc.txt", "w");

    // ON DOIT TOUJOURS CONTROLLER L OUVERTURE
    if (fp == NULL) 
        exit(EXIT_FAILURE);

    fputc('a', fp);
    fputc('b', fp);
    fputs("cd", fp);  // la ligne est écrite sans le \n

    fprintf(fp, "\n\nMes valeurs : %-8d%10.2lf\n", 12345, 4.56);
    fprintf(fp, "Mes valeurs : %-8d%10.2lf", 87, 781.3);

    fclose(fp);
}

void exemple_fseek()
{
    FILE* f = fopen("fseek.txt", "r");
    long pos = ftell(f);
    fseek(f, 0, SEEK_SET);
    fseek(f, 4, SEEK_SET);
    pos = ftell(f);
    char c = fgetc(f);
    fseek(f, 2, SEEK_CUR);
    c = fgetc(f);
    fseek(f, -5, SEEK_CUR);
    pos = ftell(f);
    c = fgetc(f);
    fclose(f);
}

void create_files()
{
    // Création des fichiers de test
    FILE* f = fopen("f1.txt", "w");
    fputs("Hello\nfoo", f);
    fclose(f);

    f = fopen("meas.txt", "w");
    fputs("1,2\n3,4\nA,8", f);
    fclose(f);

    FILE* fp = fopen("fseek.txt", "w");
    fputs("ABCD\nEFGH", fp);
    fclose(fp);
}

void fichier()
{
    create_files();
    files_fgetc();
    read_fgets();
    read_fgets_small_buff();
    files_fscanf();
    write_putc();
    exemple_fseek();
}