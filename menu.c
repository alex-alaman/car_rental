#include <gtk/gtk.h>
#include "gtk_menu_functions.c"

int create_menu(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *LogIn_button;
    GtkWidget *SignUp_button;
    GtkWidget *grid;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "MENU");

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