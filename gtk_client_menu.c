void show_UI(){
    GtkWidget *UIwindow;
    GtkWidget *UIgrid;
    GtkWidget *Message;
    GtkWidget *RentCar;
    GtkWidget *AddCarToRent;

    UIwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width(GTK_CONTAINER(UIwindow), 200);
    gtk_window_set_title(GTK_WINDOW(UIwindow), "Account");
    
    UIgrid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(UIwindow), UIgrid);
    RentCar = gtk_button_new_with_label("Rent a car");
    AddCarToRent = gtk_button_new_with_label("Add a car to rent");
    Message = gtk_label_new("Hello There");

    gtk_grid_attach(GTK_GRID(UIgrid), Message, 0,0,1,1);
    gtk_grid_attach(GTK_GRID(UIgrid), RentCar, 0,1,1,1);
    gtk_grid_attach(GTK_GRID(UIgrid), AddCarToRent, 1,1,1,1);


    gtk_widget_show_all(UIwindow);
    g_print("\nsuntem la UI");
}