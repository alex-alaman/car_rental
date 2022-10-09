#include <stdio.h>
#include <time.h>
#define SIZE 15
#define LINE_SIZE 55

// GtkWidget *brandEntry, *modelEntry, *yearEntry, *h_powerEntry, *rent_priceEntry;

typedef struct rent_time
{
    int day;
    int month;
    int year;
} rent_time;

typedef struct masina_t
{
    char brand[SIZE];
    char model[SIZE];
    char gas[SIZE];
    int ownerID;
    int renterID;
    int carID; // car poz
    int year;
    int h_power;
    int rent_price;
    rent_time rentStart;
    rent_time rentEnd;
} masina_t;

typedef struct client_t
{
    char name[SIZE];
    char lastname[SIZE];
    char email[SIZE];
    char pass[SIZE];
    int b_year;
    int client_ID;
} client_t;