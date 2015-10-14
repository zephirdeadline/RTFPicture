#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "funcInter.h"

int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);
	//gint width = 600, height = 400;
	GtkWidget * MainWindow = NULL, *DataWindow = NULL,
                  *buttonLoadImage = NULL,
                  *buttonSupprData = NULL,
                  *buttonLoadData = NULL,
                  *buttonSaveData = NULL,
                  *buttonSaveBatch = NULL,
                  *newName = NULL,
                  *zone = NULL, *image = NULL;

	image = gtk_image_new_from_file("tutu.bmp");
	MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	DataWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	zone = gtk_fixed_new();
        newName = gtk_text_view_new();
        gtk_entry_set_text(GTK_ENTRY(newName), "mouhahahah");
 	buttonLoadImage = gtk_button_new_with_label("Import");
        buttonSupprData = gtk_button_new_with_label("Supprimer");
        buttonLoadData = gtk_button_new_with_label("Recharger");
        buttonSaveData = gtk_button_new_with_label("Sauvegarder");
        buttonSaveBatch = gtk_button_new_with_label("Sauvergarder tous");


//	gtk_window_set_position(GTK_WINDOW(MainWindow), GTK_WIN_POS_CENTER);
//	gtk_window_set_position(GTK_WINDOW(DataWindow), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(DataWindow), "RTFPicture Data");
	gtk_window_set_title(GTK_WINDOW(MainWindow), "RTFPicture");
//	gtk_window_resize(GTK_WINDOW(MainWindow), width, height);
//	gtk_window_resize(GTK_WINDOW(DataWindow), width/2, height);
//	gtk_window_move(GTK_WINDOW(DataWindow), 3*width, height);//redefinir une position universelle svp
	gtk_fixed_put(GTK_FIXED(zone), buttonLoadImage, 100, 100);
        gtk_fixed_put(GTK_FIXED(zone), buttonSupprData, 100, 150);
        gtk_fixed_put(GTK_FIXED(zone), buttonLoadData, 100, 200);
        gtk_fixed_put(GTK_FIXED(zone), buttonSaveData, 100, 250);
        gtk_fixed_put(GTK_FIXED(zone), buttonSaveBatch, 100, 300);
        gtk_fixed_put(GTK_FIXED(zone), newName, 100, 350);
	gtk_fixed_put(GTK_FIXED(zone), image, 0, 0);
	gtk_container_add(GTK_CONTAINER(MainWindow), zone);
       // gtk_box_pack_start(GTK_BOX(MainWindow), newName, TRUE, TRUE, 0);
/*
	g_signal_connect(G_OBJECT(MainWindow), "delete-event",
            G_CALLBACK(gtk_main_quit), NULL);
        g_signal_connect(G_OBJECT(buttonLoadImage), "clicked",
            GTK_SIGNAL_FUNC(), (gpointer)"");
        g_signal_connect(G_OBJECT(buttonSupprData), "clicked",
            GTK_SIGNAL_FUNC(), (gpointer)"");
        g_signal_connect(G_OBJECT(buttonLoadData), "clicked",
            GTK_SIGNAL_FUNC(), (gpointer)"");
        g_signal_connect(G_OBJECT(buttonSaveData), "clicked",
            GTK_SIGNAL_FUNC(), (gpointer)"");
        g_signal_connect(G_OBJECT(buttonSaveBatch), "clicked",
            GTK_SIGNAL_FUNC(), (gpointer)"");
*/
        gtk_widget_show_all(DataWindow);
	gtk_widget_show_all(MainWindow);
	printf("affichage ok!\n");
	gtk_main();
	return 0;
}
