#include <stdio.h>
#include "functii.c"
#include "menu.c"


int main(int argc, char* argv[]){
    int choice, nr_masini = 0;
    create_menu(argc, argv);
    printf("\n0.Stop\n1.Rent a car\n2.Add a car to rent\n");
    scanf("%d", &choice);
    while (choice!=0)
    {
        switch (choice)
        {
        case 1:
            rent_car_menu();
            break;
        case 2:
            add_car_to_rent_menu();
            break;
        default:
            break;
        }
       /* if(choice == 1)
            rent_car_menu();
        else{
            add_car_to_rent_menu();
        } */
        printf("\n0.Stop\n1.Rent a car\n2.Add a car to rent\n");
        scanf("%d", &choice);
    }
}