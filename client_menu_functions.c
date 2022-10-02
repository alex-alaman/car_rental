#include <gtk/gtk.h>

GtkWidget *brandEntry, *modelEntry, *yearEntry, *h_powerEntry, *rent_priceEntry, *gasEntry;
GtkWidget *yearEntry_min, *h_powerEntry_min, *rent_priceEntry_min;
GtkWidget *yearEntry_max, *h_powerEntry_max, *rent_priceEntry_max;

void add_car_search_list(masina_t m);
void carChoose_menu();

masina_t *searchList;
int nr_cars_in_list;

int carNumber = 1;

void increment()
{
    carNumber += 1;
    carChoose_menu();
}

void decrement()
{
    carNumber -= 1;
    carChoose_menu();
}

void setCarRenter()
{
    masini[searchList[carNumber].carID].renterID = clients[client_poz].client_ID;
    update_cars_DB();
}

void showCarRenters(){
    for(int i=1;i<=nr_cars;i++)
        if(masini[i].renterID == -1)
            printf("\nmasina %s %s nu are renter", masini[i].brand, masini[i].model);
        else
         printf("\nmasina %s %s il are pe %s", masini[i].brand, masini[i].model, clients[masini[i].renterID].name);
}

void showCars()
{
    nr_cars_in_list = 0;
    for (int i = 1; i <= nr_cars; i++)
        if (masini[i].ownerID != clients[client_poz].client_ID && masini[i].renterID == -1)
        {
          //  g_print("\ncars nr: %d", nr_cars_in_list);
            nr_cars_in_list += 1;
            add_car_search_list(masini[i]);
        }
   // g_print("We found %d cars basen on your details", nr_cars_in_list);
    carChoose_menu();
}

void error()
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *message = gtk_label_new("Please provide every info to proceed");
    gtk_window_set_title(GTK_WINDOW(window), "ERROR");
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);
    gtk_container_add(GTK_CONTAINER(window), message);

    gtk_widget_show_all(window);
}

int valid(masina_t m)
{
    if (m.brand == "")
        return 0;
    if (m.model == "")
        return 0;
    if (m.gas == "")
        return 0;
    if (m.year == 0)
        return 0;
    if (m.h_power == 0)
        return 0;
    if (m.rent_price == 0)
        return 0;
    return 1;
}

void add_car(GtkWidget *irelevant, gpointer last_window)
{
    masina_t m;

    strcpy(m.brand, gtk_entry_get_text(GTK_ENTRY(brandEntry)));
    strcpy(m.model, gtk_entry_get_text(GTK_ENTRY(modelEntry)));
    strcpy(m.gas, gtk_entry_get_text(GTK_ENTRY(gasEntry)));
    m.year = atoi(gtk_entry_get_text(GTK_ENTRY(yearEntry)));
    m.h_power = atoi(gtk_entry_get_text(GTK_ENTRY(h_powerEntry)));
    m.rent_price = atoi(gtk_entry_get_text(GTK_ENTRY(rent_priceEntry)));
    m.ownerID = client_poz;
    m.carID = nr_cars + 1;
    m.renterID = -1;
    if (valid(m))
    {
        nr_cars += 1;

        gtk_widget_hide(last_window);
        add_car_to_array(m);
        add_car_to_DB(m);
        show_UI();
    }
    else
        error();
}

void add_car_search_list(masina_t m)
{
    searchList = realloc(searchList, (nr_cars_in_list + 1) * sizeof(m));
    searchList[nr_cars_in_list] = m;
}

void searchCars()
{
    nr_cars_in_list = 0;
    masina_t min, max;
    strcpy(min.brand, gtk_entry_get_text(GTK_ENTRY(brandEntry)));
    strcpy(min.model, gtk_entry_get_text(GTK_ENTRY(modelEntry)));
    strcpy(min.gas, gtk_entry_get_text(GTK_ENTRY(gasEntry)));
    min.year = atoi(gtk_entry_get_text(GTK_ENTRY(yearEntry_min)));
    min.h_power = atoi(gtk_entry_get_text(GTK_ENTRY(h_powerEntry_min)));
    min.rent_price = atoi(gtk_entry_get_text(GTK_ENTRY(rent_priceEntry_min)));

    strcpy(max.brand, gtk_entry_get_text(GTK_ENTRY(brandEntry)));
    strcpy(max.model, gtk_entry_get_text(GTK_ENTRY(modelEntry)));
    strcpy(max.gas, gtk_entry_get_text(GTK_ENTRY(gasEntry)));
    max.year = atoi(gtk_entry_get_text(GTK_ENTRY(yearEntry_max)));
    max.h_power = atoi(gtk_entry_get_text(GTK_ENTRY(h_powerEntry_max)));
    max.rent_price = atoi(gtk_entry_get_text(GTK_ENTRY(rent_priceEntry_max)));

    for (int i = 1; i <= nr_cars; i++)
    {
        if (masini[i].ownerID != clients[client_poz].client_ID && masini[i].ownerID == 0)
            if (strcmp(masini[i].brand, min.brand) == 0 || strcmp(min.brand, "") == 0)
                if (strcmp(masini[i].model, min.model) == 0 || strcmp(min.model, "") == 0)
                    if (strcmp(masini[i].gas, min.gas) == 0 || strcmp(min.gas, "") == 0)
                        if (min.rent_price <= masini[i].rent_price && masini[i].rent_price <= max.rent_price || masini[i].rent_price >= min.rent_price && max.rent_price == 0)
                            if (min.h_power <= masini[i].h_power && masini[i].h_power <= max.h_power || masini[i].h_power >= min.h_power && max.h_power == 0)
                                if (min.year <= masini[i].year && masini[i].year <= max.year || masini[i].year >= min.year && max.year == 0)
                                {
                                    nr_cars_in_list += 1;
                                    add_car_search_list(masini[i]);
                                }
    }
    carChoose_menu();
}
