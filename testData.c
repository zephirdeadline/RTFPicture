#include <stdlib.h>
#include <stdio.h>
#include "data.h"





int main()
{
	CharacterInfo *c = NULL;
	c = ArrayData();
	ShowList(c);
	printf("%s\n", c->name);
	c = RemoveInfo(c, "Sacha");
	ShowList(c);
	//c = AddInfoStart(c, "toto");
	//ShowList(c);
	return 0;
}
