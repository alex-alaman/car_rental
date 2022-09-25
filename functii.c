#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.c"
#define SIZE 15
#define LINE_SIZE 55

void add_a_car_to_rent_menu(int nr_masini);
void file_verification(FILE *file);

struct masina *masini;

void afisare_masina(struct masina m)
{
    printf("\nMarca: %s\n", m.marca);
    printf("Model: %s\n", m.model);
    printf("Combustibil: %s\n", m.combustibil);
    printf("An fabricatie: %d\n", m.an);
    printf("Cai Putere: %d\n", m.cp);
    printf("Rent Price: %d\n", m.rent_price);
}

void add_car_to_array(struct masina m, int nr_masini)
{
    masini = realloc(masini, (nr_masini + 1) * sizeof(m));
    masini[nr_masini] = m;
    // memcpy(&masini[nr_masini], &m, sizeof(m));
}

void add_car_to_DB(FILE *file, struct masina m)
{
    fprintf(file, "%s,%s,%s,%d,%d,%d\n", m.marca, m.model, m.combustibil, m.an, m.cp, m.rent_price);
}

int add_cars_from_DB(int nr_masini)
{
    FILE *file = fopen("cars_DB.txt", "r");
    file_verification(file);
    char line[LINE_SIZE], *p;
    struct masina m;
    int i = 1;
    while (fgets(line, LINE_SIZE, file) != NULL)
    {
        p = strtok(line, ",");
        i = 1;
        while (p)
        {
            switch (i)
            {
            case 1:
                strcpy(m.marca, p);
                break;
            case 2:
                strcpy(m.model, p);
                break;
            case 3:
                strcpy(m.combustibil, p);
                break;
            case 4:
                m.an = atoi(p);
                break;
            case 5:
                m.cp = atoi(p);
                break;
            case 6:
                m.rent_price = atoi(p);
                break;
            default:
                break;
            }
            i += 1;
            p = strtok(NULL, ",");
        }
        nr_masini += 1;
        add_car_to_array(m, nr_masini);
    }
    return nr_masini;
}

void file_verification(FILE *file)
{
    if (file == NULL)
    {
        printf("nu ai fisier");
        exit(-1);
    }
}

void afisare_masini(int nr_masini)
{
    for(int i=1;i<=nr_masini;i++)
        afisare_masina(masini[i]);
}

void cautare_detaliata(int nr_masini)
{
    printf("cautare detaliata");
}

void rent_car_menu()
{
    FILE *file = fopen("cars_DB.txt", "r");
    file_verification(file);
    char line[LINE_SIZE];
    if (fgets(line, LINE_SIZE, file) == NULL) // daca nu exista nicio masina in baza de date
    {
        printf("NU este nicio masina disponibila pentru inchiriere!\n");
        exit(-1);
    }
    fclose(file);
    int nr_masini = add_cars_from_DB(0);
    printf("\nSunt disponibile %d masini de inchiriat\n", nr_masini);
    printf("\n1.Afisare lista masini\n2.Cautare Detaliata");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        afisare_masini(nr_masini);
        break;
    case 2:
        cautare_detaliata(nr_masini);
        break;
    default:
        break;
    }
}

void add_car_to_rent_menu()
{
    FILE *file = fopen("cars_DB.txt", "a");
    file_verification(file);
    struct masina m;
    printf("Marca: ");
    scanf("%s", m.marca);
    printf("Model: ");
    scanf("%s", m.model);
    printf("Combustibil: ");
    scanf("%s", m.combustibil);
    printf("An fabricatie: ");
    scanf("%d", &m.an);
    printf("Cai Putere:");
    scanf("%d", &m.cp);
    printf("Rent Price:");
    scanf("%d", &m.rent_price);
    add_car_to_DB(file, m);
    fclose(file);
}