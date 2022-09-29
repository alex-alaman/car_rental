#include <gtk/gtk.h>
#include "main_menu_functions.c"
#include "client_menu_functions.c"
#include <string.h>

void main_menu()
{
    GtkWidget *window;
    GtkWidget *LogIn_button;
    GtkWidget *SignUp_button;
    GtkWidget *grid;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "MENU");

    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 200);

    LogIn_button = gtk_button_new_with_label("Log in");
    SignUp_button = gtk_button_new_with_label("Sign up");

    grid = gtk_grid_new();

    gtk_container_add(GTK_CONTAINER(window), grid);

    g_signal_connect(LogIn_button, "clicked", G_CALLBACK(log_in_menu), (gpointer)window);
    g_signal_connect(SignUp_button, "clicked", G_CALLBACK(sign_up_menu), (gpointer)window);

    gtk_grid_attach(GTK_GRID(grid), LogIn_button, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), SignUp_button, 2, 0, 1, 1);

    gtk_widget_show_all(window);
}

void log_in_menu(GtkWidget *irelevant, gpointer widget)
{
    GtkWidget *log_in_menu_window;
    GtkWidget *log_in_menu_grid;
    GtkWidget *email;
    GtkWidget *pass;
    GtkWidget *log_in_button;
    GtkWidget *back;

    log_in_menu_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(log_in_menu_window), "Log in");
    g_signal_connect(log_in_menu_window, "destroy", G_CALLBACK(destroy), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(log_in_menu_window), 200);
    gtk_widget_hide(widget);

    email = gtk_label_new("Email :");
    pass = gtk_label_new("Password : ");
    back = gtk_button_new_with_label("Inapoi");
    log_in_button = gtk_button_new_with_label("Log in");
    emailEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(emailEntry), "Email");
    passEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(passEntry), "Password");
    gtk_entry_set_visibility(GTK_ENTRY(passEntry), FALSE);

    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), log_in_menu_window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), widget);
    g_signal_connect(log_in_button, "clicked", G_CALLBACK(check_email), log_in_menu_window);

    log_in_menu_grid = gtk_grid_new();

    gtk_container_add(GTK_CONTAINER(log_in_menu_window), log_in_menu_grid);

    gtk_grid_attach(GTK_GRID(log_in_menu_grid), email, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), emailEntry, 1, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), pass, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), passEntry, 1, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), back, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), log_in_button, 1, 2, 1, 1);
    gtk_widget_show_all(log_in_menu_window);
}

void sign_up_menu(GtkWidget *irelevant, gpointer widget)
{
    GtkWidget *sign_up_menu_window;
    GtkWidget *sign_up_menu_grid;
    GtkWidget *name;
    GtkWidget *lastname;
    GtkWidget *email;
    GtkWidget *pass;
    GtkWidget *year;
    GtkWidget *back;
    GtkWidget *sign;

    sign_up_menu_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(sign_up_menu_window), "Sign up");
    gtk_container_set_border_width(GTK_CONTAINER(sign_up_menu_window), 200);
    // g_signal_connect(G_OBJECT(sign_up_menu_window), "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(sign_up_menu_window, "destroy", G_CALLBACK(destroy), NULL);
    sign_up_menu_grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(sign_up_menu_window), sign_up_menu_grid);
    gtk_widget_hide(widget);

    emailEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(emailEntry), "Email");
    passEntry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(passEntry), FALSE);
    nameEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(nameEntry), "Name");
    lastnameEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(lastnameEntry), "Last Name");
    yearEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(yearEntry), "Birth Year");
    gtk_entry_set_placeholder_text(GTK_ENTRY(passEntry), "Password");

    sign = gtk_button_new_with_label("Sign up");
    name = gtk_label_new("NUME : ");
    lastname = gtk_label_new("PRENUME : ");
    email = gtk_label_new("EMAIL : ");
    pass = gtk_label_new("PAROLA : ");
    year = gtk_label_new("AN NASTERE : ");
    back = gtk_button_new_with_label("Inapoi");

    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), sign_up_menu_window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), widget);
    g_signal_connect(sign, "clicked", G_CALLBACK(add_user), sign_up_menu_window);
    g_signal_connect(sign, "clicked", G_CALLBACK(hide_menu), sign_up_menu_window);
    // g_signal_connect(sign, "clicked", G_CALLBACK(log_in_menu), sign_up_menu_window);

    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), name, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), nameEntry, 1, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), lastname, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), lastnameEntry, 1, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), email, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), emailEntry, 1, 2, 2, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), pass, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), passEntry, 1, 3, 2, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), year, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), yearEntry, 1, 4, 2, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), back, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), sign, 1, 5, 1, 1);
    gtk_widget_show_all(sign_up_menu_window);
}

void rent_car_menu(GtkWidget *irelevant, gpointer lastWindow)
{
    gtk_widget_hide(lastWindow);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *error = gtk_label_new("No cars to rent");
    GtkWidget *message = gtk_label_new("Would you like to see all cars available or a detailed search?");
    GtkWidget *ShowCars = gtk_button_new_with_label("All cars");
    GtkWidget *SearchCars = gtk_button_new_with_label("Detailed search");
    GtkWidget *back = gtk_button_new_with_label("Back");

    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), lastWindow);

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

void add_car_to_rent_menu(GtkWidget* irelevant, gpointer lastWindow)
{
    gtk_widget_hide(lastWindow);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *brand = gtk_label_new("Brand: ");
    GtkWidget *model = gtk_label_new("Model: ");
    GtkWidget *year = gtk_label_new("Year: ");
    GtkWidget *h_power = gtk_label_new("Horse Power: ");
    GtkWidget *rent_price = gtk_label_new("Rent Price: ");
    GtkWidget *gas = gtk_label_new("Gas: ");
    GtkWidget *back = gtk_button_new_with_label("Back");
    GtkWidget *add = gtk_button_new_with_label("Add car");

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
    g_signal_connect(add, "clicked", G_CALLBACK(hide_menu), window);
    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), lastWindow);

    gtk_container_add(GTK_CONTAINER(window), grid);

    gtk_window_set_title(GTK_WINDOW(window), "Add Car to Rent Menu");
    gtk_container_set_border_width(GTK_CONTAINER(window), 100);
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

    //g_print("\nAdd a car");
}

void show_UI()
{
    GtkWidget *UIwindow;
    GtkWidget *UIgrid;
    GtkWidget *Message;
    GtkWidget *RentCar;
    GtkWidget *AddCarToRent;
    g_print("\nclient poz:%d", client_poz);
    UIwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(UIwindow, "destroy", G_CALLBACK(destroy), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(UIwindow), 200);
    gtk_window_set_title(GTK_WINDOW(UIwindow), "Account");

    UIgrid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(UIwindow), UIgrid);
    RentCar = gtk_button_new_with_label("Rent a car");
    g_signal_connect(RentCar, "clicked", G_CALLBACK(rent_car_menu), UIwindow);
    AddCarToRent = gtk_button_new_with_label("Add a car to rent");
    g_signal_connect(AddCarToRent, "clicked", G_CALLBACK(add_car_to_rent_menu), UIwindow);
    char message[100] = "Hello there ";
    strcat(message, clients[client_poz].name);
    Message = gtk_label_new(message);

    gtk_grid_attach(GTK_GRID(UIgrid), Message, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(UIgrid), RentCar, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(UIgrid), AddCarToRent, 1, 1, 1, 1);

    gtk_widget_show_all(UIwindow);
    g_print("\nsuntem la UI");
}