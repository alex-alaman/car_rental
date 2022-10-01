#include <gtk/gtk.h>

GtkWidget *brandEntry, *modelEntry, *yearEntry, *h_powerEntry, *rent_priceEntry, *gasEntry;

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
    if(m.brand == "") return 0;
    if(m.model == "") return 0;
    if(m.gas == "") return 0;
    if(m.year == 0) return 0;
    if(m.h_power == 0) return 0;
    if(m.rent_price == 0) return 0;
    return 1;
}

void add_car(GtkWidget *irelevant ,gpointer last_window)
{
    masina_t m;

    strcpy(m.brand, gtk_entry_get_text(GTK_ENTRY(brandEntry)));
    strcpy(m.model, gtk_entry_get_text(GTK_ENTRY(modelEntry)));
    strcpy(m.gas, gtk_entry_get_text(GTK_ENTRY(gasEntry)));
    m.year = atoi(gtk_entry_get_text(GTK_ENTRY(yearEntry)));
    m.h_power = atoi(gtk_entry_get_text(GTK_ENTRY(h_powerEntry)));
    m.rent_price = atoi(gtk_entry_get_text(GTK_ENTRY(rent_priceEntry)));
    m.renterID = client_poz;

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
