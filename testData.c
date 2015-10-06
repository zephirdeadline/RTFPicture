#include <stdlib.h>
#include <stdio.h>
#include "data.h"





int main()
{
	CharacterInfo *c = NULL;
	c = ArrayData();
	//printf("%d\n%d\n", CompareChar("aa", "aa"), CompareChar("aab", "aa"));
	//c = AddInfo(c, "TTTTT");
	//c = AddInfo(c, "PPPPP");
	//c = AddInfoStart(c, "lucas");

	//ModifInfo(c, "b", "hihi");
	//char *ca = Concat("sa", "lut");
	//printf("Resultat de la concatenation: %s\n", ca);


	//printf("Ily a %s elements\n", c->next->name);

	//c = RemoveInfo(c, "e");
	//char *res = Concat("aaa", "bbb");
	//printf("Ily a %s elements\n", res);
	//WriteFile(c);
	//ShowList(c);
	ShowList(c);
	printf("%s\n", c->name);
	//printf("%s\n", c->next->next->name);
	char *a = "Lucette";
	c = RemoveInfo(c, a);
	c = RemoveInfo(c, "Sacha");
	//WriteFile(c);


	//ShowList(c);
	// ShowList(c);
	// c = AddInfoStart(c, "toto");
	ShowList(c);
	//ShowList(c);
	//c = AddInfoStart(c, "toto");
	//ShowList(c);
	//ShowList(c);
	//printf(" \n   %s   \n", c->next->name);
	//ArrayData();
	//AddInfo("ii", "oo", "oo");
	//char*a;
	//*a = '1';
	//printf("egalité: %d\n", atoi(a));

      // RemoveFile ("Lucas");







	return 0;
}
