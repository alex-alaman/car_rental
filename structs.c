#include <stdio.h>
#define SIZE 15
#define LINE_SIZE 55

// GtkWidget *brandEntry, *modelEntry, *yearEntry, *h_powerEntry, *rent_priceEntry;
typedef struct masina_t
{
    char brand[SIZE];
    char model[SIZE];
    char gas[SIZE];
    int renterID;
    int year;
    int h_power;
    int rent_price;
} masina_t;

typedef struct client_t
{
    char name[SIZE];
    char lastname[SIZE];
    char email[SIZE];
    char pass[SIZE];
    int b_year;
} client_t;