#include <stdlib.h>
#include <gtk/gtk.h>

int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);
	
	GtkWidget * MainWindow = NULL;

	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_window_set_title(GTK_WINDOW(MainWindow), "RTFPicture");
	

	gtk_widget_show(MainWindow);
	gtk_main();
	return 0;
}
