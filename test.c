#include <gtk/gtk.h>
  
void log_in(GtkWidget* widget, gpointer data)
{
    // printf equivalent in GTK+
    g_print("\nlog in");
}

void sign_up(GtkWidget* widget, gpointer data)
{
    // printf equivalent in GTK+
    g_print("\nsign up");
}
  
void destroy(GtkWidget* widget, gpointer data)
{
    gtk_main_quit();
}
  
int main(int argc, char* argv[])
{
    GtkWidget* window;
    GtkWidget* LogIn_button;
    GtkWidget* SignUp_button;
    GtkWidget* grid;
    gtk_init(&argc, &argv);
  
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    /* Let's set the border width of the window to 20.
    * You may play with the value and see the
    * difference. */
    gtk_container_set_border_width(GTK_CONTAINER(window), 200);
  
    LogIn_button = gtk_button_new_with_label("Log in");
    SignUp_button = gtk_button_new_with_label("Sign up");

  /* Here we construct the container that is going pack our buttons */
  grid = gtk_grid_new ();

  /* Pack the container in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);

  g_signal_connect(ATK_OBJECT(LogIn_button), "clicked", G_CALLBACK(log_in),NULL);
  g_signal_connect(ATK_OBJECT(SignUp_button), "clicked", G_CALLBACK(sign_up),NULL);

  gtk_grid_attach (GTK_GRID (grid), LogIn_button, 0, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), SignUp_button, 2, 0, 1, 1);

  gtk_widget_show_all(window);
  gtk_main();
  return 0;
}