#include <gtk/gtk.h>
int create_menu(int argc, char *argv[]);

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


void log_in_menu(GtkWidget *irelevant, gpointer widget)
{
    GtkWidget *log_in_menu_window;
    GtkWidget *log_in_menu_grid;
    GtkWidget *mail;
    GtkWidget *pass;
    GtkWidget *back;

    log_in_menu_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(log_in_menu_window, "destroy", G_CALLBACK(destroy), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(log_in_menu_window), 200);
    gtk_widget_hide(widget);

    mail = gtk_label_new("EMAIL : ");
    pass = gtk_label_new("PAROLA : ");
    back = gtk_button_new_with_label("Inapoi");

    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), log_in_menu_window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), widget);
    log_in_menu_grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(log_in_menu_window), log_in_menu_grid);

    gtk_grid_attach(GTK_GRID(log_in_menu_grid), mail, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), pass, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(log_in_menu_grid), back, 0, 2, 1, 1);
    gtk_widget_show_all(log_in_menu_window);
}
void sign_up_menu(GtkWidget *irelevant, gpointer widget)
{
    GtkWidget *sign_up_menu_window;
    GtkWidget *sign_up_menu_grid;
    GtkWidget *nume;
    GtkWidget *prenume;
    GtkWidget *mail;
    GtkWidget *pass;
    GtkWidget *an_nastere;
    GtkWidget *back;

    sign_up_menu_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width(GTK_CONTAINER(sign_up_menu_window), 200);
    g_signal_connect(G_OBJECT(sign_up_menu_window), "destroy", G_CALLBACK(destroy), NULL);
    sign_up_menu_grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(sign_up_menu_window), sign_up_menu_grid);
    gtk_widget_hide(widget);

    nume = gtk_label_new("NUME : ");
    prenume = gtk_label_new("PRENUME : ");
    mail = gtk_label_new("EMAIL : ");
    pass = gtk_label_new("PAROLA : ");
    an_nastere = gtk_label_new("AN NASTERE : ");
    back = gtk_button_new_with_label("Inapoi");

    g_signal_connect(back, "clicked", G_CALLBACK(hide_menu), sign_up_menu_window);
    g_signal_connect(back, "clicked", G_CALLBACK(show_menu), widget);

    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), nume, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), prenume, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), mail, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), pass, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), an_nastere, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(sign_up_menu_grid), back, 0, 5, 1, 1);
    gtk_widget_show_all(sign_up_menu_window);
}

int create_menu(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *LogIn_button;
    GtkWidget *SignUp_button;
    GtkWidget *grid;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

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
    gtk_main();
    return 0;
}