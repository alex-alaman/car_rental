#include <stdio.h>
#include "functii.c"
#include "menu.c"

int create_menu(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    main_menu();
    gtk_main();
    return 0;  
}

int main(int argc, char* argv[]){
    add_cars_from_DB();
    add_clients_from_DB();
    create_menu(argc, argv);
    showCarRenters();
    free(masini);
    free(clients);
    return 0;
}