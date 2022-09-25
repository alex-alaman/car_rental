#include <gtk/gtk.h>

int create_menu(int argc, char *argv[]);
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

void add_user_to_DB(GtkWidget *irelavant, gpointer data)
{
    FILE *file = fopen("client_DB.txt", "a");
    file_verification(file);
    const char *name = gtk_entry_get_text(GTK_ENTRY(nameEntry));
    const char *pass = gtk_entry_get_text(GTK_ENTRY(passEntry));
    const char *email = gtk_entry_get_text(GTK_ENTRY(emailEntry));
    const char *lastname = gtk_entry_get_text(GTK_ENTRY(lastnameEntry));
     int year = atoi(gtk_entry_get_text(GTK_ENTRY(passEntry)));
    fprintf(file, "%s,%s,%s,%s,%d\n", name, lastname, email, pass, year);
}

void print_data(GtkWidget *irelavant, gpointer widget)
{
    //g_print("%s\n", gtk_entry_get_text(GTK_ENTRY(emailEntry)));
    const char *nume = gtk_entry_get_text(GTK_ENTRY(emailEntry));
    //g_print("%s\n", gtk_entry_get_text(GTK_ENTRY(passEntry)));
    const char *pass = gtk_entry_get_text(GTK_ENTRY(passEntry));
    g_print("%s\n", nume);
    g_print("%s\n", pass);
}


void log_in_menu(GtkWidget *irelevant, gpointer widget)
{
    GtkWidget *log_in_menu_window;
    GtkWidget *log_in_menu_grid;
    GtkWidget *email;
    GtkWidget *pass;
    GtkWidget *check_email;
    GtkWidget *back;

    log_in_menu_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(log_in_menu_window, "destroy", G_CALLBACK(destroy), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(log_in_menu_window), 200);
    gtk_widget_hide(widget);

    email = gtk_label_new("Email ;");
    pass = gtk_label_new("Password : ");
    back = gtk_button_new_with_label("Inapoi");
    check_email = gtk_button_new_with_label("Log in");
    emailEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(emailEntry),"Email");
    passEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(passEntry),"Password");
    gtk_entry_set_visibility(GTK_ENTRY(passEntry),FALSE);

    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), log_in_menu_window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), widget);
    g_signal_connect(check_email, "clicked", G_CALLBACK(print_data), log_in_menu_window);

    
    log_in_menu_grid = gtk_grid_new();

    gtk_container_add(GTK_CONTAINER(log_in_menu_window), log_in_menu_grid);

    gtk_grid_attach(GTK_GRID(log_in_menu_grid), email, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), emailEntry, 1, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), pass, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), passEntry, 1, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), back, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), check_email, 1, 2, 1, 1);
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
    gtk_container_set_border_width(GTK_CONTAINER(sign_up_menu_window), 200);
    g_signal_connect(G_OBJECT(sign_up_menu_window), "destroy", G_CALLBACK(destroy), NULL);
    sign_up_menu_grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(sign_up_menu_window), sign_up_menu_grid);
    gtk_widget_hide(widget);

    emailEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(emailEntry),"Email");
    passEntry = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(passEntry),FALSE);
    nameEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(nameEntry),"Name");
    lastnameEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(lastnameEntry),"Last Name");
    yearEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(yearEntry),"Birth Year");
    gtk_entry_set_placeholder_text(GTK_ENTRY(passEntry),"Password");
    sign = gtk_button_new_with_label("Sign up");

    name = gtk_label_new("NUME : ");
    lastname = gtk_label_new("PRENUME : ");
    email = gtk_label_new("EMAIL : ");
    pass = gtk_label_new("PAROLA : ");
    year = gtk_label_new("AN NASTERE : ");
    back = gtk_button_new_with_label("Inapoi");

    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), sign_up_menu_window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), widget);
    g_signal_connect(sign, "clicked", G_CALLBACK(add_user_to_DB), NULL);

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
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), sign, 1,5,1,1);
    gtk_widget_show_all(sign_up_menu_window);
}
