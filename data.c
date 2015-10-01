#include <stdlib.h>
#include <stdio.h>
#include "data.h"


int Convert(int a)
{
	int b;
		switch(a)
		{
			case 49:
				b = 1;
				break;
			case 50:
				b = 2;
				break;
			case 51:
				b = 3;
				break;
			case 52:
				b = 4;
				break;
			case 53:
				b = 5;
				break;
			case 54:
				b = 6;
				break;
			case 55:
				b = 7;
				break;
			case 56:
				b = 8;
				break;
			case 57:
				b = 9;
				break;
			//default:
			//	b = 0;
			//	break;
		}
		
		return b;
	
}

void AddInfo(char *name, char *image, char *caracter)
{
	CharacterInfo new;
	new.name = name;
	new.caracter = caracter;
	new.image = image;
	ConfigFile('+');
	//...
	printf("Ajout effectué avec bonté!\n");
	
}

void ModifInfo()
{

}

void RemoveInfo()
{
	ConfigFile('-');
}

void ConfigFile(char option)
{
	FILE *file = NULL;
	file = fopen("RTFP.config", "r+");
	if(file != NULL)
	{
		int nbC = 0;
		printf("Ouverture du fichier avec succé\n");
		if(option == '+')
		{
			fscanf(file, "%d", &nbC);
			fseek(file, 0, SEEK_SET);
			fprintf(file, "%d", ++nbC);
		}
		else
		{
			fscanf(file, "%d", &nbC);
			fseek(file, 0, SEEK_SET);
			fprintf(file, "%d", --nbC);

		}
		fclose(file);
	}
}

int CounterData()
{
	int a = 0;
	FILE *file = NULL;
	file = fopen("RTFP.config", "r+");
	if(file != NULL)
	{
		fscanf(file, "%d", &a);
	}
	return a;
	fclose(file);

}

CharacterInfo* ArrayData(CharacterInfo *C)
{
	CharacterInfo *ArrayInfo = malloc(CounterData() * sizeof(CharacterInfo));
	if(ArrayInfo != NULL)
	{
		printf("Allocation reussie\n");
		return ArrayInfo;
	}
	else
	{
		printf("Echec allocation");
		 return NULL;
	}
	free(ArrayInfo);
}
