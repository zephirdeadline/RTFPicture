#include <stdio.h>
#include <stdlib.h>
#include "funcInter.h"
#include <gtk/gtk.h>
void logConsole(GtkWidget *w, gpointer str)
{
  printf("%s\n", (char*)str);
}

void logOk()
{
  printf("Operation reussie!!\n");
}
