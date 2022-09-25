#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 15
#define LINE_SIZE 55

/*masina -> marca, model, an, cp , combustibil*/
struct masina
{
    char marca[SIZE];
    char model[SIZE];
    char combustibil[SIZE];
    int an;
    int cp;
    int rent_price;
};

struct client
{
    char nume[SIZE];
    char prenume[SIZE];
    char email[SIZE];
    char pass[SIZE];
    int an_nastere;
};

struct renter
{
    char nume[SIZE];
    char prenume[SIZE];
    char email[SIZE];
    char pass[SIZE];
    int an_nastere;
};