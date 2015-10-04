#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"



/*--------Converti une valeur ascii en int----------
---------------------De 0 a 9--------------------*/


/* ne sert a rien pour le moment
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
*/


/*------------------Concatenation-----------------
-------------------------------------------------*/


char* Concat(char *a, char *b)
{
	char c[50] = "";
	/*
	for(int i = 0; i<strlen(a)-1; i++)
	{
		c[i] = *(a+i);
	}
	for(int i = strlen(a)-1 ; i<strlen(b); i++)
	{
		c[i]=*(b+i);
	}*/
	strcat(c, a);
	return strcat(c, b);
	//strcat(c, b);
	//printf("La concatenation donne: %s\n", c);
	//return strcat(c, b);
}


/*--------Ajout d'un element au chargement---------
-------------------------------------------------*/


CharacterInfo* AddInfoStart(CharacterInfo *c, char *name)
{

	CharacterInfo *new = malloc(sizeof(CharacterInfo)); //*temp = malloc(sizeof(CharacterInfo));
	//temp = c;
	new->next = c;
	
	//char *test = Concat(name, "-Caracter");
	//printf("variable test %s\n\n", test);
	new->name = name;
	new->caracter ="Caracter"; //Concat(name, "-Caracter");//strcat(name, "Caracter");
	new->image = "Image";//Concat(name, "-Image");//strcat(name, "Image");
	//printf("attibution: %s\n", new->image);
	
	
	printf("Ajout effectué avec bonté! %s\n", new->image);
	return new;
}


/*----------------Ajout d'un element---------------
-------------------------------------------------*/


CharacterInfo* AddInfo(CharacterInfo *c, char *name)
{

	CharacterInfo *new = malloc(sizeof(CharacterInfo)); //*temp = malloc(sizeof(CharacterInfo));
	//temp = c;
	new->next = c;
	
	//char *test = Concat(name, "-Caracter");
	//printf("variable test %s\n\n", test);
	new->name = name;
	new->caracter ="Caracter"; //Concat(name, "-Caracter");//strcat(name, "Caracter");
	new->image = "Image";//Concat(name, "-Image");//strcat(name, "Image");
	//printf("attibution: %s\n", new->image);
	ConfigFile('+');
	FILE *file = NULL;
	file = fopen("RTFP.data", "r+");
	if(file != NULL)
	{
		fseek(file, 0, SEEK_END);
		fputs(name, file);
		fputc('\n', file);

		fclose(file);
	}	
	//...
	printf("Ajout effectué avec bonté! %s\n", new->image);
	return new;
}


/*----------Modification d'un element-------------
-------------------------------------------------*/


void ModifInfo(CharacterInfo *c, char *name, char *newName){
	while(c->name != name)
	{
			c = c->next;
	}
	c->name = newName;
}

/*----------Suppression d'un element---------------
-------------------------------------------------*/

CharacterInfo* RemoveInfo(CharacterInfo *c, char *name)
{ //attention si 0 ou 1 element !! Attention de 10 puis suppr = 90!
	CharacterInfo *a = c;
	
	ConfigFile('-');
	if(c->name == name)
	{
		CharacterInfo *b = c;
		c = c->next;
		free(b);
		return c;
	}
	else
	{
		while(c->next->name != name)
		{
			c = c->next;
		}
		c->next = c->next->next;
		free(c->next);
		return a;
	}
}


/*-----------Modification fichier config-----------
-------------------------------------------------*/


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
			
			fprintf(file, "%d\n", ++nbC);
		}
		else
		{		
			fscanf(file, "%d", &nbC);
			fseek(file, 0, SEEK_SET);
			
			fprintf(file, "%d\n", --nbC);

		}
		fclose(file);
	}
}

/*----Compte le nombre d'element dans la liste-----
-------------------------------------------------*/

int CountList(CharacterInfo *c)
{
	int nb = 0;
	while(c != NULL)
	{
		nb++;
		c = c->next;
	}
	return nb;
}


/*------Recupere le d'element dans le fichier-----
-------------------------------------------------*/

int CounterData()
{
	int a = 0;
	FILE *file = NULL;
	file = fopen("RTFP.config", "r+");
	if(file != NULL)
	{
		//char chaine[100] = "";
		//a = atoi(fgets(chaine, 100, file));
	
		
		fscanf(file, "%d", &a);
		fseek(file, 0, SEEK_SET);
//		printf(" LE FICHIER RTFP.CONFOG EST A   %d    ",a);
		if( a == 90){a=9;}
	}
	fclose(file);

	return a;

}

/*--------Affiche les elements de la liste----------
-------------------------------------------------*/

void ShowList(CharacterInfo *c)
{
	int nb = 1;

	do
	{
		printf("Le nb %d s'appelle %s\n", nb, c->name);
		c = c->next;
		nb++;
	}while(c != NULL);

}

/*-----Chargement et creation de la liste---------
----------------ITERATIF------------------------*/

CharacterInfo* ArrayData()
{
	
/*
	CharacterInfo *temp = malloc(sizeof(CharacterInfo));
	int size = CounterData();
	if(size != 0)
	{
		FILE *file = NULL;
		file = fopen("RTFP.data", "r");
		if(file != NULL)
		{
			//while(fgetc(file) != '\n'){}
			for(int i = 1; i<size; i++)
			{*/
				FILE *file = NULL;
				file = fopen("RTFP.data", "r");
				// CharacterInfo *c = malloc(sizeof(CharacterInfo));
				CharacterInfo *c = NULL ;
					for(int i =1; i<=CounterData();i++)
					{	
						int pos = 0;
						char temp ;		
						char t[50] = "";
						while((temp = fgetc(file)) != '\n')
						{
							t[pos]=temp;
							pos++;
						}
						//fgets(t, 100, file) ;
						//char *w = t;
						printf("$$$$ %s   $$$$", t);
						//scanf("%s", temp);

						c = AddInfoStart(c, t);



					}
					
					return c;

				//}
			/*}
			fclose(file);
		}
	}

	return temp;*/
}



/*----- ANCIENNE VERSION creation de la liste------
-------------------------------------------------*/

/*
CharacterInfo* ArrayData()
{
	

	CharacterInfo *temp = malloc(sizeof(CharacterInfo));
	int size = CounterData();
	if(size != 0)
	{
		FILE *file = NULL;
		file = fopen("RTFP.data", "r");
		if(file != NULL)
		{
			//while(fgetc(file) != '\n'){}

			CharacterInfo *a = malloc(sizeof(CharacterInfo));
			temp = a;
			a->name = "b\n";
			for(int i = 1; i<size; i++)
			{
				CharacterInfo *c = malloc(sizeof(CharacterInfo));
				if(c != NULL)
				{						
					char t[50] = "";
					fgets(t, 100, file) ;
					char *w = t;
					// printf("LE NOM EST %s",t);
					c->name = w;
					//fscanf(file, "%s", c->name);
					//printf("name: %s\n", c->name);
					c->next = NULL;
					c->caracter = NULL;
					c->image = NULL;
					a->next = c;
					a = c;
				}
			}
			fclose(file);
		}
	}
	else
	{
		temp = NULL;
	}

	return temp;
*/


/*
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
	free(ArrayInfo);*/
	
//} 



/*---------Chargement et creation de la liste------------
-----------------------RECURCIF------------------------*/


CharacterInfo* ArrayRec(int size)
{
	if(size == 0)
		return NULL;
	else{
		CharacterInfo *new = malloc(sizeof(CharacterInfo));
		FILE *file = fopen("RTFP.data", "r");
		char chaine[100] = "";
		for(int i = CounterData(); i>size; i--)
		{	
			fgets(chaine, 100, file);

		}
		new->name = chaine;

   

		new->next = ArrayRec(size-1);
		return new;
		}
}
