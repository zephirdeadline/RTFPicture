#include <stdlib.h>
#include <stdio.h>
#include "data.h"





int main()
{
	CharacterInfo *c = NULL;
	c = ArrayData();
	//c = AddInfoStart(c, "Anais");
	//c = AddInfoStart(c, "paul");
	//c = AddInfoStart(c, "lucas");
	//ModifInfo(c, "b", "hihi");
	printf("Il y a %d elements\n", CountList(c));

	//c = RemoveInfo(c, "Anais");
	//printf("Ily a %s elements\n", c->next->name);

	//c = RemoveInfo(c, "e");
	//char *res = Concat("aaa", "bbb");
	//printf("Ily a %s elements\n", res);


	ShowList(c);
	//ShowList(c);
	printf(" \n   %s   \n", c->next->name);
	//ArrayData();
	//AddInfo("ii", "oo", "oo");
	//char*a;
	//*a = '1';
	//printf("egalité: %d\n", atoi(a));
	return 0;
}
