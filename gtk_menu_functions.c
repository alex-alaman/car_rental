#include <gtk/gtk.h>
#include "gtk_client_menu.c"

int create_menu(int argc, char *argv[]);
void log_in_menu(GtkWidget *irelevant, gpointer widget);
void sign_up_menu(GtkWidget *irelevant, gpointer widget);
GtkWidget *emailEntry, *passEntry, *nameEntry, *lastnameEntry, *yearEntry;

void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

void show_menu(GtkWidget *irelavant, gpointer widget)
{
    gtk_widget_show(widget);
}

void hide_menu(GtkWidget *irelavant, gpointer widget)
{
    gtk_widget_hide(widget);
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
    gtk_window_set_title (GTK_WINDOW (errorWindow), "Sign up ERROR");
    errorGrid = gtk_grid_new();
    gtk_container_set_border_width(GTK_CONTAINER(errorWindow), 50);
    gtk_container_add(GTK_CONTAINER(errorWindow), errorGrid);

    error = gtk_label_new("This email already exists. Would you like to try again or sign in?");
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
    gtk_window_set_title (GTK_WINDOW (errorWindow), "Log in ERROR");
    errorGrid = gtk_grid_new();
    gtk_container_set_border_width(GTK_CONTAINER(errorWindow), 50);
    gtk_container_add(GTK_CONTAINER(errorWindow), errorGrid);

    error = gtk_label_new("Email or password wrong");
    //i choose this type of error instead of case sensitive error like email is wrong
    TryAgain = gtk_button_new_with_label("Try again");
    SignUp = gtk_button_new_with_label("Sign Up");

    g_signal_connect(SignUp, "clicked", G_CALLBACK(sign_up_menu), errorWindow);
    g_signal_connect(TryAgain, "clicked", G_CALLBACK(log_in_menu), errorWindow);

    gtk_grid_attach(GTK_GRID(errorGrid), error, 0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(errorGrid), TryAgain, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(errorGrid), SignUp, 1, 1, 1, 1);

    gtk_widget_show_all(errorWindow);
}

void add_user_to_DB(GtkWidget *irelevant, gpointer window)
{
    FILE *file = fopen("client_DB.txt", "a");
    const char *name = gtk_entry_get_text(GTK_ENTRY(nameEntry));
    const char *pass = gtk_entry_get_text(GTK_ENTRY(passEntry));
    const char *email = gtk_entry_get_text(GTK_ENTRY(emailEntry));
    const char *lastname = gtk_entry_get_text(GTK_ENTRY(lastnameEntry));
    const int year = atoi(gtk_entry_get_text(GTK_ENTRY(yearEntry)));
    if (find_pass_email(fopen("client_DB.txt", "r"), email) == "")
    {
        fprintf(file, "%s,%s,%s,%s,%d\n", email, pass, name, lastname, year);
        log_in_menu(irelevant, window);
        fflush(file); // force-put the data in the file
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
    const char *passFound = find_pass_email(file, email);
    if (strcmp(pass, passFound) == 0)
    {
        hide_menu(irelevant, window);
        g_print("\nLogin OK");
        show_UI();
    }
    else
    {
        show_log_in_error(window);
        //error types 
        /*if (passFound == "")
            g_print("\nEmail Not Found");
        else
            g_print("\nWrong Password");*/
    }
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
    gtk_window_set_title (GTK_WINDOW (log_in_menu_window), "Log in");
    g_signal_connect(log_in_menu_window, "destroy", G_CALLBACK(destroy), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(log_in_menu_window), 200);
    gtk_widget_hide(widget);

    email = gtk_label_new("Email ;");
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
    gtk_window_set_title (GTK_WINDOW (sign_up_menu_window), "Sign up");
    gtk_container_set_border_width(GTK_CONTAINER(sign_up_menu_window), 200);
    g_signal_connect(G_OBJECT(sign_up_menu_window), "destroy", G_CALLBACK(destroy), NULL);
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
    g_signal_connect(sign, "clicked", G_CALLBACK(add_user_to_DB), sign_up_menu_window);
    g_signal_connect(sign, "clicked", G_CALLBACK(hide_menu), sign_up_menu_window);
    //g_signal_connect(sign, "clicked", G_CALLBACK(log_in_menu), sign_up_menu_window);

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
