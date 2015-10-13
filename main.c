#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "funcInter.h"

int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);
	//gint width = 600, height = 400;	
	GtkWidget * MainWindow = NULL, *DataWindow = NULL, *button = NULL, *zone = NULL, *image = NULL;

	image = gtk_image_new_from_file("tutu.bmp");
	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	DataWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	zone = gtk_fixed_new();
 	button = gtk_button_new_with_label("Import");
		
//	gtk_window_set_position(GTK_WINDOW(MainWindow), GTK_WIN_POS_CENTER);
//	gtk_window_set_position(GTK_WINDOW(DataWindow), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(DataWindow), "RTFPicture Data");
	gtk_window_set_title(GTK_WINDOW(MainWindow), "RTFPicture");
//	gtk_window_resize(GTK_WINDOW(MainWindow), width, height);
//	gtk_window_resize(GTK_WINDOW(DataWindow), width/2, height);
//	gtk_window_move(GTK_WINDOW(DataWindow), 3*width, height);//redefinir une position universelle svp
	gtk_fixed_put(GTK_FIXED(zone), button, 100, 100);
	gtk_fixed_put(GTK_FIXED(zone), image, 0, 0);
	gtk_container_add(GTK_CONTAINER(MainWindow), zone);

	g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
  //test de cliquer sur bouton avec la fonction "logConsole(char *str) qui affiche str dans la console	
	gtk_widget_show_all(DataWindow);
	gtk_widget_show_all(MainWindow);
	printf("affichage ok!\n");
	gtk_main();
	return 0;
}
