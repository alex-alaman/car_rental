#include <gtk/gtk.h>

void main_menu();
int create_menu(int argc, char *argv[]);
void log_in_menu(GtkWidget *irelevant, gpointer widget);
void sign_up_menu(GtkWidget *irelevant, gpointer widget);
void show_UI();


GtkWidget *emailEntry, *passEntry, *nameEntry, *lastnameEntry, *yearEntry;


void show_menu(GtkWidget *irelavant, gpointer widget)
{
    gtk_widget_show(widget);
}

void hide_menu(GtkWidget *irelavant, gpointer widget)
{
    gtk_widget_hide(widget);
}

void destroy()
{
    gtk_main_quit();
}

void update_DBs()
{
    g_print("\nUPDATE\n");
    update_clients_DB();
    update_cars_DB();
}

void show_sign_up_error(gpointer window)
{
    GtkWidget *error;
    GtkWidget *errorWindow;
    GtkWidget *errorGrid;
    GtkWidget *TryAgain;
    GtkWidget *LogIn;
    hide_menu(error, window);
    errorWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(errorWindow, "destroy", G_CALLBACK(destroy), NULL);
    gtk_window_set_title(GTK_WINDOW(errorWindow), "Sign up ERROR");
    errorGrid = gtk_grid_new();
    gtk_container_set_border_width(GTK_CONTAINER(errorWindow), 100);
    gtk_container_add(GTK_CONTAINER(errorWindow), errorGrid);

    error = gtk_label_new("This email already exists. Would you like to try again or log in?");
    TryAgain = gtk_button_new_with_label("Try again");
    LogIn = gtk_button_new_with_label("Log in");

    g_signal_connect(LogIn, "clicked", G_CALLBACK(log_in_menu), errorWindow);
    g_signal_connect(TryAgain, "clicked", G_CALLBACK(sign_up_menu), errorWindow);

    gtk_grid_attach(GTK_GRID(errorGrid), error, 0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(errorGrid), TryAgain, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(errorGrid), LogIn, 1, 1, 1, 1);

    gtk_widget_show_all(errorWindow);
}

void show_log_in_error(gpointer window)
{
    GtkWidget *error;
    GtkWidget *errorWindow;
    GtkWidget *errorGrid;
    GtkWidget *TryAgain;
    GtkWidget *SignUp;
    hide_menu(error, window);
    errorWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(errorWindow, "destroy", G_CALLBACK(destroy), NULL);
    gtk_window_set_title(GTK_WINDOW(errorWindow), "Log in ERROR");
    errorGrid = gtk_grid_new();
    gtk_container_set_border_width(GTK_CONTAINER(errorWindow), 50);
    gtk_container_add(GTK_CONTAINER(errorWindow), errorGrid);

    error = gtk_label_new("Email or password wrong");
    // i choose this type of error instead of case sensitive error like email is wrong
    TryAgain = gtk_button_new_with_label("Try again");
    SignUp = gtk_button_new_with_label("Sign Up");

    g_signal_connect(SignUp, "clicked", G_CALLBACK(sign_up_menu), errorWindow);
    g_signal_connect(TryAgain, "clicked", G_CALLBACK(log_in_menu), errorWindow);

    gtk_grid_attach(GTK_GRID(errorGrid), error, 0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(errorGrid), TryAgain, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(errorGrid), SignUp, 1, 1, 1, 1);

    gtk_widget_show_all(errorWindow);
}

void add_user(GtkWidget *irelevant, gpointer window)
{
    struct Client client;
    strcpy(client.name, gtk_entry_get_text(GTK_ENTRY(nameEntry)));
    strcpy(client.pass, gtk_entry_get_text(GTK_ENTRY(passEntry)));
    strcpy(client.email, gtk_entry_get_text(GTK_ENTRY(emailEntry)));
    strcpy(client.lastname, gtk_entry_get_text(GTK_ENTRY(lastnameEntry)));
    client.b_year = atoi(gtk_entry_get_text(GTK_ENTRY(yearEntry)));
    if (find_pass_email(client.email) == -1)
    {
        client_nr += 1;
        add_client_to_array(client);
        add_client_to_DB(client);
        //g_print("\n%d", client_nr);
        //log_in_menu(irelevant, window);
        main_menu();
    }
    else
    {
        // g_print("email NOT OK");
        show_sign_up_error(window);
    }
}

void check_email(GtkWidget *irelevant, gpointer window)
{
    FILE *file = fopen("client_DB.txt", "r");
    const char *email = gtk_entry_get_text(GTK_ENTRY(emailEntry));
    const char *pass = gtk_entry_get_text(GTK_ENTRY(passEntry));
    client_poz = find_pass_email(email);
    char *passFound = clients[client_poz].pass;
    if (strcmp(pass, passFound) == 0)
    {
        hide_menu(irelevant, window);
        g_print("\nLogin OK");
        show_UI();
    }
    else
    {
        show_log_in_error(window);
        // error types
        /*if (passFound == "")
            g_print("\nEmail Not Found");
        else
            g_print("\nWrong Password");*/
    }
}


