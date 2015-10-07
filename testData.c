#include <stdlib.h>
#include <stdio.h>
#include "data.h"





int main()
{
	CharacterInfo *c = NULL;
	c = ArrayData();
	char *a = "Sara", *b = "Paul", *e = "Tom", *d = NULL;
	char **tab = malloc(4 * sizeof(a));
	tab[0] = a;
	tab[1] = b;
	tab[2] = e;
	tab[3] = d;
	ShowList(c);
	//printf("%s\n", c->name);
	//c = RemoveInfo(c, "Sacha");
	c = AddBatch(c, tab);
	ShowList(c);
	//c = AddInfoStart(c, "toto");
	//ShowList(c);
	return 0;
}
