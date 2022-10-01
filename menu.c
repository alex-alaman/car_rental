#include <gtk/gtk.h>
#include "main_menu_functions.c"
#include "client_menu_functions.c"
#include <string.h>
#include <gdk/gdkkeysyms.h>

void main_menu()
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *LogIn_button = gtk_button_new_with_label("Log in");
    GtkWidget *SignUp_button = gtk_button_new_with_label("Sign up");
    GtkWidget *grid = gtk_grid_new();

    gtk_window_set_title(GTK_WINDOW(window), "MENU");
    gtk_container_set_border_width(GTK_CONTAINER(window), 200);
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);

    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(LogIn_button, "clicked", G_CALLBACK(log_in_menu), (gpointer)window);
    g_signal_connect(SignUp_button, "clicked", G_CALLBACK(sign_up_menu), (gpointer)window);

    gtk_grid_attach(GTK_GRID(grid), LogIn_button, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), SignUp_button, 2, 0, 1, 1);

    gtk_widget_show_all(window);
}

void log_in_menu(GtkWidget *irelevant, gpointer last_window)
{
    gtk_widget_hide(last_window);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *email = gtk_label_new("Email :");
    GtkWidget *pass = gtk_label_new("Password : ");
    GtkWidget *log_in_button = gtk_button_new_with_label("Log in");
    GtkWidget *back = gtk_button_new_with_label("Inapoi");

    gtk_window_set_title(GTK_WINDOW(window), "Log in");
    gtk_container_set_border_width(GTK_CONTAINER(window), 200);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);
    gtk_container_add(GTK_CONTAINER(window), grid);

    emailEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(emailEntry), "Email");
    passEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(passEntry), "Password");
    gtk_entry_set_visibility(GTK_ENTRY(passEntry), FALSE);

    g_signal_connect (window, "key_press_event", G_CALLBACK (on_key_press_logIN), window);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), last_window);
    g_signal_connect(log_in_button, "clicked", G_CALLBACK(check_email), window);


    gtk_grid_attach(GTK_GRID(grid), email, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), emailEntry, 1, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), pass, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), passEntry, 1, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), back, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), log_in_button, 1, 2, 1, 1);

    gtk_widget_show_all(window);
}

void sign_up_menu(GtkWidget *irelevant, gpointer last_window)
{
    gtk_widget_hide(last_window);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *name = gtk_label_new("NUME : ");
    GtkWidget *lastname = gtk_label_new("PRENUME : ");
    GtkWidget *email = gtk_label_new("EMAIL : ");
    GtkWidget *pass = gtk_label_new("PAROLA : ");
    GtkWidget *year = gtk_label_new("AN NASTERE : ");
    GtkWidget *back = gtk_button_new_with_label("Inapoi");
    GtkWidget *sign = gtk_button_new_with_label("Sign up");

    gtk_window_set_title(GTK_WINDOW(window), "Sign up");
    gtk_container_set_border_width(GTK_CONTAINER(window), 200);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);
    gtk_container_add(GTK_CONTAINER(window), grid);

    emailEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(emailEntry), "Email");
    passEntry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(passEntry), FALSE);
    gtk_entry_set_placeholder_text(GTK_ENTRY(passEntry), "Password");
    nameEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(nameEntry), "Name");
    lastnameEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(lastnameEntry), "Last Name");
    yearEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(yearEntry), "Birth Year");

    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), last_window);
    g_signal_connect(sign, "clicked", G_CALLBACK(add_user), window);
    g_signal_connect (window, "key_press_event", G_CALLBACK (on_key_press_signUP), window);

    gtk_grid_attach(GTK_GRID(grid), name, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), nameEntry, 1, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), lastname, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), lastnameEntry, 1, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), email, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), emailEntry, 1, 2, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), pass, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), passEntry, 1, 3, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), year, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), yearEntry, 1, 4, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), back, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), sign, 1, 5, 1, 1);

    gtk_widget_show_all(window);
}

void rent_car_menu(GtkWidget *irelevant, gpointer lastWindow)
{
    gtk_widget_hide(lastWindow);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *error = gtk_label_new("No cars to rent");
    GtkWidget *message = gtk_label_new("Would you like to see all cars available or a detailed search?");
    GtkWidget *ShowCars = gtk_button_new_with_label("All cars");
    GtkWidget *SearchCars = gtk_button_new_with_label("Detailed search");
    GtkWidget *back = gtk_button_new_with_label("Back");

    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), lastWindow);

    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);
    gtk_window_set_title(GTK_WINDOW(window), "Rent Car Menu");
    gtk_container_set_border_width(GTK_CONTAINER(window), 100);

    if (nr_cars == 0)
    {
        g_print("\nNo cars for rent");
        gtk_container_add(GTK_CONTAINER(window), error);
    }
    else
    {
        gtk_container_add(GTK_CONTAINER(window), grid);
        gtk_grid_attach(GTK_GRID(grid), message, 0, 0, 4, 1);
        gtk_grid_attach(GTK_GRID(grid), ShowCars, 1, 1, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), SearchCars, 2, 1, 1, 1);
        gtk_grid_attach(GTK_GRID(grid), back, 3, 1, 1, 1);
    }
    gtk_widget_show_all(window);
}

void add_car_to_rent_menu(GtkWidget *irelevant, gpointer lastWindow)
{
    gtk_widget_hide(lastWindow);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *brand = gtk_label_new("Brand: ");
    GtkWidget *model = gtk_label_new("Model: ");
    GtkWidget *year = gtk_label_new("Year: ");
    GtkWidget *h_power = gtk_label_new("Horse Power: ");
    GtkWidget *rent_price = gtk_label_new("Rent Price: ");
    GtkWidget *gas = gtk_label_new("Gas: ");
    GtkWidget *back = gtk_button_new_with_label("Back");
    GtkWidget *add = gtk_button_new_with_label("Add car");

    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);
    gtk_window_set_title(GTK_WINDOW(window), "Add Car to Rent Menu");
    gtk_container_set_border_width(GTK_CONTAINER(window), 100);
    gtk_container_add(GTK_CONTAINER(window), grid);

    brandEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(brandEntry), "Brand");
    modelEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(modelEntry), "Model");
    yearEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(yearEntry), "Year");
    h_powerEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(h_powerEntry), "Horse Power");
    rent_priceEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(rent_priceEntry), "Rent Price");
    gasEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(gasEntry), "Gas Type");

    g_signal_connect(add, "clicked", G_CALLBACK(add_car), window);
    g_signal_connect (window, "key_press_event", G_CALLBACK (on_key_press_addCar), window);
    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), lastWindow);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    gtk_grid_attach(GTK_GRID(grid), brand, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), brandEntry, 1, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), model, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), modelEntry, 1, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), year, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), yearEntry, 1, 2, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), h_power, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), h_powerEntry, 1, 3, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), rent_price, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), rent_priceEntry, 1, 4, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), gas, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gasEntry, 1, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), back, 0, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), add, 1, 6, 1, 1);

    gtk_widget_show_all(window);

    // g_print("\nAdd a car");
}

void show_UI()
{
    char message[100] = "Hello there ";
    strcat(message, clients[client_poz].name);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *Message = gtk_label_new(message);
    GtkWidget *RentCar = gtk_button_new_with_label("Rent a car");
    GtkWidget *AddCarToRent = gtk_button_new_with_label("Add a car to rent");
    GtkWidget *LogOut = gtk_button_new_with_label("Log Out");

    gtk_container_set_border_width(GTK_CONTAINER(window), 200);
    gtk_window_set_title(GTK_WINDOW(window), "Account");
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);
    gtk_widget_show_all(window);

    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(RentCar, "clicked", G_CALLBACK(rent_car_menu), window);
    g_signal_connect(LogOut, "clicked", G_CALLBACK(main_menu), window);
    g_signal_connect(LogOut, "clicked", G_CALLBACK(hide_menu), window);
    g_signal_connect(AddCarToRent, "clicked", G_CALLBACK(add_car_to_rent_menu), window);

    gtk_container_add(GTK_CONTAINER(window), grid);

    gtk_grid_attach(GTK_GRID(grid), Message, 0, 0, 3, 1);
    gtk_grid_attach(GTK_GRID(grid), RentCar, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), AddCarToRent, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), LogOut, 2, 1, 1, 1);

    gtk_widget_show_all(window);

    // g_print("\nsuntem la UI");
    // g_print("\nclient poz:%d", client_poz);
}