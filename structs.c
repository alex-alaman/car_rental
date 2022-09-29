#include <stdio.h>
#define SIZE 15
#define LINE_SIZE 55

//GtkWidget *brandEntry, *modelEntry, *yearEntry, *h_powerEntry, *rent_priceEntry;
struct masina
{
    char brand[SIZE];
    char model[SIZE];
    char gas[SIZE];
    int renterID;
    int year;
    int h_power;
    int rent_price;
};

struct Client
{
    char name[SIZE];
    char lastname[SIZE];
    char email[SIZE];
    char pass[SIZE];
    int b_year;
};