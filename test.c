/* #include <gtk/gtk.h>

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *dreapta;
  GtkWidget *grid;
  GtkWidget *settings;
  GtkWidget *accounts;
  GtkWidget *loans;
  GtkWidget *cash;
  GtkWidget *debts;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
  gtk_window_set_title(GTK_WINDOW(window), "GtkVBox");
  gtk_container_set_border_width(GTK_CONTAINER(window), 5);
  grid = gtk_grid_new();
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
  gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
  gtk_widget_set_hexpand(window, TRUE);
  gtk_widget_set_vexpand(window, TRUE);
  vbox = gtk_box_new(TRUE, 1);
  gtk_container_add(GTK_CONTAINER(window), grid);

  settings = gtk_button_new_with_label("Settings");
  accounts = gtk_button_new_with_label("Accounts");
  loans = gtk_button_new_with_label("Loans");
  cash = gtk_button_new_with_label("Cash");
  debts = gtk_button_new_with_label("Debts");
  dreapta= gtk_label_new("aici e restul");

  gtk_box_pack_start(GTK_BOX(vbox), settings, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), accounts, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), loans, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), cash, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), debts, TRUE, TRUE, 0);

  gtk_grid_attach(GTK_GRID(grid), vbox,0,0,1,6);
  gtk_grid_attach(GTK_GRID(grid), dreapta,1,0,3,6);


  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
} */

/* #include <stdio.h>
#include <time.h>
int main()
{
  time_t rawtime;
  struct tm *info;
  time(&rawtime);
  info = localtime(&rawtime);
  printf("day : %d \n",info->tm_mday);
  printf("month: %d \n", info->tm_mon);
  printf("year: %d\n",1900 + info->tm_year);
  printf("Current local time and date: %s", asctime(info));
  return (0);
} */
/* #include <stdio.h>
#include <string.h>

int main()
{
  char c[20] = "";
  if (strcmp(c, "")==0)
    printf("da");
  else
    printf("nu");
} */

#include <gtk/gtk.h>

/* void buttonFunction(GtkWidget * widget, gpointer data, int & n){
    n = 1;
}
 */

void buttonFunction (GtkButton *button, gpointer user_data) /* No extra parameter here ! */
{
    /* you cast to the type of what you passed as last argument of g_signal_connect */ 
    int *pn = user_data; 
    *pn = 1;
    g_print("%d", 1 + *pn);
}

int main (int argc, char **argv)
{
    int n = 0;
    GtkWidget *window;
    GtkWidget *button; 

    gtk_init (&argc,&argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    button = gtk_button_new_with_label ("Osss");

    gtk_container_add (GTK_CONTAINER(window), button);
    gtk_widget_show_all (window);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Here's the magic: you pass a pointer to the variable you'd like to modify
     * in the callback, be it a simple variable or a struct */
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(buttonFunction), &n);

    gtk_main();

    return 0;
}

