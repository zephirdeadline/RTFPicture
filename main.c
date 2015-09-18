#include <stdlib.h>
#include <gtk/gtk.h>

int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);
	gint width = 600, height = 400;	
	GtkWidget * MainWindow = NULL, *DataWindow = NULL, *button = NULL;

	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	DataWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	button = gtk_button_new_with_label("Import");
	g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_window_set_position(GTK_WINDOW(MainWindow), GTK_WIN_POS_CENTER);
	gtk_window_set_position(GTK_WINDOW(DataWindow), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(DataWindow), "RTFPicture Data");
	gtk_window_set_title(GTK_WINDOW(MainWindow), "RTFPicture");
	gtk_window_resize(GTK_WINDOW(MainWindow), width, height);
	gtk_window_resize(GTK_WINDOW(DataWindow), width/2, height);
	gtk_button_resize(GKT_WIDGET(button), 50,20);
	gtk_window_move(GTK_WINDOW(DataWindow), 3*width, height);//redefinir une position universelle svp
	gtk_container_add(GTK_CONTAINER(MainWindow), button);
	gtk_widget_show_all(DataWindow);
	gtk_widget_show_all(MainWindow);
	gtk_main();
	return 0;
}
