#include <stdlib.h>
#include <stdio.h>
#include "data.h"

int main()
{
	CharacterInfo *c = NULL;
	c = ArrayRec(CounterData());
	//c = AddInfo(c, "Anais");
	//c = AddInfo(c, "Kris");
	//ModifInfo(c, "b", "hihi");
	printf("Il y a %d elements\n", CountList(c));
	//c = RemoveInfo(c, "Anais");
	//printf("Ily a %s elements\n", c->next->name);

	ShowList(c);

	//ArrayData();
	//AddInfo("ii", "oo", "oo");
	//char*a;
	//*a = '1';
	//printf("egalité: %d\n", atoi(a));
	return 0;
}
