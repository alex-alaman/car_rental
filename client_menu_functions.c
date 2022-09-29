#include <gtk/gtk.h>

GtkWidget *brandEntry, *modelEntry, *yearEntry, *h_powerEntry, *rent_priceEntry, *gasEntry;

void add_car()
{
    struct masina m;
    strcpy(m.brand, gtk_entry_get_text(GTK_ENTRY(brandEntry)));
    strcpy(m.model, gtk_entry_get_text(GTK_ENTRY(modelEntry)));
    strcpy(m.gas,gtk_entry_get_text(GTK_ENTRY(gasEntry)));
    m.year = atoi(gtk_entry_get_text(GTK_ENTRY(yearEntry)));
    m.h_power = atoi(gtk_entry_get_text(GTK_ENTRY(h_powerEntry)));
    m.rent_price = atoi(gtk_entry_get_text(GTK_ENTRY(rent_priceEntry)));
    m.renterID = client_poz;
    nr_cars += 1;
    add_car_to_array(m);
    add_car_to_DB(m);
    show_UI();
}   
