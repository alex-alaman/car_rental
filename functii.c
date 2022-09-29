#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.c"

#define SIZE 15
#define LINE_SIZE 55

void add_client_to_array(struct Client client);

int nr_cars = 0, client_nr = 0, client_poz;

void add_a_car_to_rent_menu(int nr_masini);
void file_verification(FILE *file);

struct masina *masini;
struct Client *clients;

/* void afisare_masina(struct masina m)
{
    printf("\nMarca: %s\n", m.marca);
    printf("Model: %s\n", m.model);
    printf("Combustibil: %s\n", m.combustibil);
    printf("An fabricatie: %d\n", m.an);
    printf("Cai Putere: %d\n", m.cp);
    printf("Rent Price: %d\n", m.rent_price);
} */

void add_clients_from_DB()
{
    FILE *file = fopen("client_DB.txt", "r");
    file_verification(file);
    char line[LINE_SIZE], *p;
    struct Client client;
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
                strcpy(client.name, p);
                break;
            case 2:
                strcpy(client.lastname, p);
                break;
            case 3:
                strcpy(client.email, p);
                break;
            case 4:
                strcpy(client.pass, p);
                break;
            case 5:
                client.b_year = atoi(p);
                break;
            default:
                break;
            }
            i += 1;
            p = strtok(NULL, ",");
        }
        client_nr += 1;
        add_client_to_array(client);
    }
    fclose(file);
}

void update_cars_DB()
{
    FILE *file = fopen("cars_DB.txt", "w");
    file_verification(file);
    for (int i = 1; i <= nr_cars; i++)
        fprintf(file, "%s,%s,%s,%d,%d,%d\n", masini[i].brand, masini[i].model, masini[i].gas, masini[i].year, masini[i].h_power, masini[i].rent_price);
    fclose(file);
}

void update_clients_DB()
{
    FILE *file = fopen("client_DB.txt", "w");
    file_verification(file);
    for (int i = 1; i <= client_nr; i++)
        fprintf(file, "%s,%s,%s,%s,%d\n", clients[i].name, clients[i].lastname, clients[i].email, clients[i].pass, clients[i].b_year);
    fclose(file);
}

void add_client_to_array(struct Client client)
{
    clients = realloc(clients, (client_nr + 1) * sizeof(client));
    clients[client_nr] = client;
}

void add_client_to_DB(struct Client client)
{
    FILE *file = fopen("client_DB.txt", "a");
    file_verification(file);
    fprintf(file, "%s,%s,%s,%s,%d\n", client.name, client.lastname, client.email, client.pass, client.b_year);
    fflush(file);
}

void add_car_to_array(struct masina m)
{
    masini = realloc(masini, (nr_cars + 1) * sizeof(m));
    masini[nr_cars] = m;
}

void add_car_to_DB(struct masina m)
{
    FILE *file = fopen("cars_DB.txt", "a");
    file_verification(file);
    fprintf(file, "%s,%s,%s,%d,%d,%d,%d\n", m.brand, m.model, m.gas, m.year, m.h_power, m.rent_price, m.renterID);
    fflush(file);
}

void add_cars_from_DB()
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
                strcpy(m.brand, p);
                break;
            case 2:
                strcpy(m.model, p);
                break;
            case 3:
                strcpy(m.gas, p);
                break;
            case 4:
                m.year = atoi(p);
                break;
            case 5:
                m.h_power = atoi(p);
                break;
            case 6:
                m.rent_price = atoi(p);
                break;
            case 7:
                strcpy(m.renterID, p);
                break;
            default:
                break;
            }
            i += 1;
            p = strtok(NULL, ",");
        }
        nr_cars += 1;
        add_car_to_array(m);
    }
    fclose(file);
}

void file_verification(FILE *file)
{
    if (file == NULL)
    {
        printf("nu ai fisier");
        exit(-1);
    }
}

int find_pass_email(const char email[SIZE])
{
    for (int i = 1; i <= client_nr; i++)
    {
        if (strcmp(clients[i].email, email) == 0)
            return i;
    }
    return -1;
}

/* void afisare_masini(int nr_masini)
{
    for(int i=1;i<=nr_masini;i++)
        afisare_masina(masini[i]);
} */

void cautare_detaliata(int nr_masini)
{
    printf("cautare detaliata");
}