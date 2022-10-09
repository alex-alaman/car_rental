#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.c"

#define SIZE 15
#define LINE_SIZE 55

client_t add_client_to_array(client_t client);

int nr_cars = 0, client_nr = 0, ClientID;

void add_a_car_to_rent_menu(int nr_masini);
void file_verification(FILE *file);

masina_t *masini;
client_t *clients;

void afisare_masina(masina_t m)
{
    printf("\nMarca: %s\n", m.brand);
    printf("Model: %s\n", m.model);
    printf("An fabricatie: %d\n", m.year);
    printf("Cai Putere: %d\n", m.h_power);
    printf("Combustibil: %s\n", m.gas);
    printf("Rent Price: %d\n", m.rent_price);
}

client_t add_clients_from_DB()
{
    FILE *file = fopen("client_DB.txt", "r");
    file_verification(file);
    char line[LINE_SIZE], *p;
    client_t client;
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
            case 6:
                client.client_ID = atoi(p);
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

masina_t update_cars_DB()
{
    FILE *file = fopen("cars_DB.txt", "w");
    file_verification(file);
    for (int i = 1; i <= nr_cars; i++)
        fprintf(file, "%s,%s,%s,%d,%d,%d,%d,%d,%d\n", masini[i].brand, masini[i].model, masini[i].gas, masini[i].year, masini[i].h_power, masini[i].rent_price, masini[i].ownerID, masini[i].carID, masini[i].renterID);
    fclose(file);
}

client_t update_clients_DB()
{
    FILE *file = fopen("client_DB.txt", "w");
    file_verification(file);
    for (int i = 1; i <= client_nr; i++)
        fprintf(file, "%s,%s,%s,%s,%d,%d\n", clients[i].name, clients[i].lastname, clients[i].email, clients[i].pass, clients[i].b_year, clients[i].client_ID);
    fflush(file);
    fclose(file);
}

client_t add_client_to_array(client_t client)
{
    clients = realloc(clients, (client_nr + 1) * sizeof(client));
    clients[client_nr] = client;
}

client_t add_client_to_DB(client_t client)
{
    FILE *file = fopen("client_DB.txt", "w");
    file_verification(file);
    fprintf(file, "%s,%s,%s,%s,%d,%d\n", client.name, client.lastname, client.email, client.pass, client.b_year, client.client_ID);
    fflush(file);
}

int rent_ongoing(rent_time day)
{
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);

    if(day.year < info->tm_year + 1900) return 0;
    else if(day.month < info->tm_mon + 1) return 0;
    else if(day.day < info->tm_mday) return 0;
    return 1;
}

void  update_rent_DB()
{
    FILE *file = fopen("rent_DB.txt", "w");
    file_verification(file);
    masina_t m;
    for(int i=1;i<=nr_cars;i++)
    {
        if(masini[i].renterID != -1)
        {
            m = masini[i];
            fprintf(file, "%d,%d,%d,%d,%d,%d,%d,%d\n", m.carID, clients[m.renterID].client_ID, m.rentStart.day, m.rentStart.month, m.rentStart.year,
            m.rentEnd.day,  m.rentEnd.month, m.rentEnd.year);
        }
    }
    fclose(file);
}

void add_rent_from_DB()
{
    FILE *file = fopen("rent_DB.txt", "r");
    file_verification(file);
    char line[LINE_SIZE], *p;
    masina_t m;
    int i = 1,ID;
    while (fgets(line, LINE_SIZE, file) != NULL)
    {
        p = strtok(line, ",");
        i = 1;
        while (p)
        {
            switch (i)
            {
            case 1:
                ID = atoi(p);
                break;
            case 2:
                m.renterID = atoi(p);
                break;
            case 3:
                m.rentStart.day = atoi(p);
                break;
            case 4:
                m.rentStart.month = atoi(p);
                break;
            case 5:
                m.rentStart.year = atoi(p);
                break;
            case 6:
                m.rentEnd.day = atoi(p);
                break;
            case 7:
                m.rentEnd.month = atoi(p);
                break;
            case 8:
                m.rentEnd.year = atoi(p);
                break;
            default:
                break;
            }
            i += 1;
            p = strtok(NULL, ",");
        }
        if(rent_ongoing(m.rentEnd)==1)
        {
            masini[ID].renterID = m.renterID;
            masini[ID].rentEnd = m.rentEnd;
            masini[ID].rentStart = m.rentStart;
        }
    }
    fclose(file);
}

masina_t add_car_to_array(masina_t m)
{
    masini = realloc(masini, (nr_cars + 1) * sizeof(m));
    masini[nr_cars] = m;
}

masina_t add_car_to_DB(masina_t m)
{
    FILE *file = fopen("cars_DB.txt", "a");
    file_verification(file);
    fprintf(file, "%s,%s,%s,%d,%d,%d,%d,%d,%d\n", m.brand, m.model, m.gas, m.year, m.h_power, m.rent_price, m.ownerID, m.carID,m.renterID);
    fflush(file);
}

masina_t add_cars_from_DB()
{
    FILE *file = fopen("cars_DB.txt", "r");
    file_verification(file);
    char line[LINE_SIZE], *p;
    masina_t m;
    int i = 1;
    while (fgets(line, LINE_SIZE, file) != NULL)
    {
        //g_print("%s", line);
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
                m.ownerID = atoi(p);
                break;
            case 8:
                m.carID = atoi(p);
                break;
            default:
                break;
            }
            i += 1;
            p = strtok(NULL, ",");
        }
        m.renterID = -1;
        nr_cars += 1;
       // afisare_masina(m);
        add_car_to_array(m);
    }
    fclose(file);
}

void file_verification(FILE *file)
{
    if (file == NULL)
    {
        printf("nu ai fisierul");
        exit(-1);
    }
}

int find_pass_email(const char email[SIZE])
{
    for (int i = 1; i <= client_nr; i++)
    {
        if (strcmp(clients[i].email, email) == 0)
            return clients[i].client_ID;
    }
    return -1;
}



