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

void create_meas_tab()
{
    FILE* f = fopen("meas_tab.txt", "w");
    fputs("num,val1,val2,val3\n", f);  // on écrit l'entête

    fprintf(f, "%d,%d,%d,%d\n", 1, 10, 20, 30);
    fprintf(f, "%d,%d,%d,%d\n", 2, 100, 0, -4);
    fprintf(f, "%d,%d,%d,%d\n", 3, 10, -5, 12);
    fclose(f);
}

void add_meas_tab()
{
    FILE* f = fopen("meas_tab.txt", "a");
    fprintf(f, "%d,%d,%d,%d\n", 4, 0, 1, 2);
    fclose(f);
}

void print_meas_tab()
{
    printf("\nFichier tab\n");
    FILE* f = fopen("meas_tab.txt", "r");
    int num, val1, val2, val3;

    char header[100];
    fgets(header, 100, f);  // read header

    int ret;
    do
    {
        ret = fscanf(f, "%d,%d,%d,%d\n", &num, &val1, &val2, &val3);

        if (ret != 4 && ret != EOF)
        {
            exit(EXIT_FAILURE);
        }

        printf("Valeur %d : %d / %d / %d\n", num, val1, val2, val3);
    } while (ret != EOF);
    // Test EOF et non 0

    fclose(f);
}

void create_meas_tab_fixe()
{
    FILE* f = fopen("meas_tab_fixe.txt", "w");
    const int size = 6;  // largeur peut changer chaque colonne
    fprintf(f, "%*s%*s%*s%*s\n", size, "num", size, "val1", size, "val2", size,
            "val3");  // on écrit l'entête

    fprintf(f, "%*d%*d%*d%*d\n", size, 1, size, 10, size, 20, size, 30);
    fprintf(f, "%*d%*d%*d%*d\n", size, 2, size, -45, size, 1234, size, -456);
    fclose(f);
}

void read_meas_tab_fixe()
{
    int line = 2;
    int val;
    FILE* f = fopen("meas_tab_fixe.txt", "r");
    fseek(f, line * (6 + 6 + 6 + 6 + 1), SEEK_SET);
    fseek(f, 6 + 6, SEEK_CUR);
    fscanf(f, "%d", &val);
    printf("Int lu : %d\n", val);
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

void fichier_binaire_char()
{
    FILE* fp = fopen("bin_c1.dat", "w");
    char buffer_out[] = {'1', '2', '3', 123};
    fwrite(buffer_out, sizeof(char), 4, fp);
    fclose(fp);

    fp = fopen("bin.txt", "w");
    fprintf(fp, "123");
    fclose(fp);
}

void fichier_binaire()
{
    fprintf(stdout, "Test lecture fichier binaire\n");
    // Pas de lecture car le pointeur est au bout
    FILE* fp = fopen("bin1.dat", "w+");
    int buffer_out[] = {1, 2, 3, 4, 5, 6};
    int buffer_in[4] = {0};

    fwrite(buffer_out, sizeof(int), 4, fp);

    // Mettre après pour montrer la position du pointeur
    long pos = ftell(fp);
    printf("Position : %ld\n", pos);

    fseek(fp, 0, SEEK_SET);

    pos = ftell(fp);
    printf("Position : %ld\n", pos);

    fread(buffer_in, sizeof(int), 4, fp);

    for (int i = 0; i < 4; i++) printf("Val %d : %d\n", i, buffer_in[i]);

    fclose(fp);
}

struct Data
{
    int p1;
    int p2;
    double value;
} data;

void fichier_struct()
{
    fprintf(stdout, "\nTest lecture fichier binaire\n");

    // Write
    FILE* fp = fopen("struct.dat", "w+");
    data.p1 = 12;
    data.p2 = 4;
    data.value = 3.45;
    size_t s = sizeof(data);
    fwrite(&data, sizeof(struct Data), 1, fp);
    fclose(fp);

    // Read
    struct Data d;
    fp = fopen("struct.dat", "r");
    fread(&d, sizeof(struct Data), 1, fp);
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

    create_meas_tab();
    add_meas_tab();
    print_meas_tab();

    create_meas_tab_fixe();
    read_meas_tab_fixe();

    fichier_binaire_char();

    fichier_binaire();

    fichier_struct();
}