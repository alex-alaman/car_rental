#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>

/*-- Declare the GTK Widgets used in the program --*/

/*-- This function allows the program to exit properly when the window is closed --*/
gint destroyapp(GtkWidget *widget, gpointer gdata)
{
  gtk_main_quit();
  return (FALSE);
}

static void calendar_day_selected_double_click(GtkWidget *widget,
                                               gpointer calendar)
{
  guint day, month, year;

  gtk_calendar_get_date(GTK_CALENDAR(calendar), &year, &month, &day);
  /* --WHY do I have to switch the year and the day??-- */

  printf("%d/%d/%d\n", day, month + 1, year);

  gtk_main_quit();
}

int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *calendar;
  gtk_init(&argc, &argv);
  calendar = gtk_calendar_new();

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(calendar, "day-selected-double-click", G_CALLBACK(calendar_day_selected_double_click), calendar);

  g_signal_connect(window, "delete_event", G_CALLBACK(destroyapp), NULL);

  gtk_container_add(GTK_CONTAINER(window), calendar);

  /*-- Display the widgets --*/
  gtk_widget_show(calendar);
  gtk_widget_show(window);

  /*-- Start the GTK event loop --*/
  gtk_main();

  /*-- Return 0 if exit is successful --*/
  return 0;
}