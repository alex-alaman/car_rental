#include <gtk/gtk.h>

void main_menu();
int create_menu(int argc, char *argv[]);
void log_in_menu(GtkWidget *irelevant, gpointer widget);
void sign_up_menu(GtkWidget *irelevant, gpointer widget);
void show_UI();
void error();
void add_car(GtkWidget *irelevant, gpointer last_window);

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

void show_sign_up_error(gpointer last_window)
{
    gtk_widget_hide(last_window);

    GtkWidget *error = gtk_label_new("This email already exists. Would you like to try again or log in?");
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *TryAgain = gtk_button_new_with_label("Try again");
    GtkWidget *LogIn = gtk_button_new_with_label("Log in");

    gtk_window_set_title(GTK_WINDOW(window), "Sign up ERROR");
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);
    gtk_container_set_border_width(GTK_CONTAINER(window), 100);
    gtk_container_add(GTK_CONTAINER(window), grid);

    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(LogIn, "clicked", G_CALLBACK(log_in_menu), window);
    g_signal_connect(TryAgain, "clicked", G_CALLBACK(sign_up_menu), window);

    gtk_grid_attach(GTK_GRID(grid), error, 0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), TryAgain, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), LogIn, 1, 1, 1, 1);

    gtk_widget_show_all(window);
}

void show_log_in_error()
{

    GtkWidget *error = gtk_label_new("Email or password wrong");
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *grid = gtk_grid_new();
    GtkWidget *TryAgain = gtk_button_new_with_label("Try again");
    GtkWidget *SignUp = gtk_button_new_with_label("Sign Up");

    //gtk_window_set_focus(GTK_WINDOW(window), GTK_WINDOW(window));

    gtk_window_set_title(GTK_WINDOW(window), "Log in ERROR");
    gtk_container_set_border_width(GTK_CONTAINER(window), 50);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 8);
    gtk_container_add(GTK_CONTAINER(window), grid);

    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect(SignUp, "clicked", G_CALLBACK(sign_up_menu), window);
    g_signal_connect(TryAgain, "clicked", G_CALLBACK(log_in_menu), window);

    gtk_grid_attach(GTK_GRID(grid), error, 0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), TryAgain, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), SignUp, 1, 1, 1, 1);

    gtk_widget_show_all(window);
}

int valid_data(client_t c)
{
    if (c.name == "")
        return 0;
    if (c.lastname == "")
        return 0;
    if (c.email == "")
        return 0;
    if (c.pass == "")
        return 0;
    if (c.b_year == 0)
        return 0;
    return 1;
}

void add_user(GtkWidget *irelevant, gpointer last_window)
{
    client_t client;

    strcpy(client.name, gtk_entry_get_text(GTK_ENTRY(nameEntry)));
    strcpy(client.pass, gtk_entry_get_text(GTK_ENTRY(passEntry)));
    strcpy(client.email, gtk_entry_get_text(GTK_ENTRY(emailEntry)));
    strcpy(client.lastname, gtk_entry_get_text(GTK_ENTRY(lastnameEntry)));
    client.b_year = atoi(gtk_entry_get_text(GTK_ENTRY(yearEntry)));
    client.client_ID = client_nr + 1;
    if (valid_data(client))
    {
        if (find_pass_email(client.email) == -1)
        {
            gtk_widget_hide(last_window);
            client_nr += 1;
            add_client_to_array(client);
            add_client_to_DB(client);
            // g_print("\n%d", client_nr);
            // log_in_menu(irelevant, window);
            main_menu();
        }
        else
        {
            gtk_widget_hide(last_window);
            show_sign_up_error(last_window);
        }
    }
    else
        error();
}

void check_email(GtkWidget *irelevant, gpointer window)
{
    gtk_widget_hide(window);
    FILE *file = fopen("client_DB.txt", "r");

    const char *email = gtk_entry_get_text(GTK_ENTRY(emailEntry));
    const char *pass = gtk_entry_get_text(GTK_ENTRY(passEntry));

    if (strcmp(pass, "") == 0 || strcmp(email, "") == 0)
    {
        show_log_in_error();
    }
    else
    {
        client_poz = find_pass_email(email);
        char *passFound = clients[client_poz].pass;

        if (strcmp(pass, passFound) == 0)
        {
            hide_menu(irelevant, window);
            //g_print("\nLogin OK");
            show_UI();
        }
        else
            show_log_in_error(window);
    }
    // error types
    /*if (passFound == "")
        g_print("\nEmail Not Found");
    else
        g_print("\nWrong Password");*/
}

gboolean on_key_press_logIN(GtkWidget *irelevant, GdkEventKey *event, gpointer last_window)
{
    if (event->keyval == GDK_KEY_Return)
    {
        check_email(irelevant, last_window);
    }
    return FALSE;
}
gboolean on_key_press_signUP(GtkWidget *irelevant, GdkEventKey *event, gpointer last_window)
{
    if (event->keyval == GDK_KEY_Return)
    {
        add_user(irelevant, last_window);
    }
    return FALSE;
}

gboolean on_key_press_addCar(GtkWidget *irelevant, GdkEventKey *event, gpointer last_window)
{
    if (event->keyval == GDK_KEY_Return)
    {
        add_car(irelevant, last_window);
    }
    return FALSE;
}
