#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nb = 0;
	FILE *file = NULL;
	file = fopen("test.txt", "r+");
	fscanf(file, "%d", &nb);
	fseek(file, 0, SEEK_SET);
	fprintf(file, "%d", --nb);
	printf("%d", nb);
	
	return 0;
}
