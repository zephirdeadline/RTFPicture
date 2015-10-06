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
---------------------Fonctionnelle---------------*/


char* Concat(char *a, char *b)
{
	char *c = malloc(50*sizeof(char));
	
	for(int i = 0; i<strlen(a); i++)
	{
		*(c+i) = *(a+i);
		//printf("%c %c\n", *(a+i), c[i]);
	}
	int i = 0;
	int lena = strlen(a);
	for(i; i<strlen(b); i++)
	{
		*(c+lena+i)=*(b+i);
	}
	*(c+lena+i) = '\0';
	return c;
	/*
	strcat(c, a);
	return strcat(c, b);*/
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
	new->caracter = Concat(name, "-Caracter"); //Concat(name, "-Caracter");//strcat(name, "Caracter");
	new->image = Concat(name, "-Image");//Concat(name, "-Image");//strcat(name, "Image");
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
	new->name = name; //Concat(name, "");
	new->caracter = Concat(name, "-Caracter");
	new->image = Concat(name, "-Image");//Concat(name, "-Image");//strcat(name, "Image");
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


void ModifInfo(CharacterInfo *c, char *name, char *newName)
{
	while(c->name != name)
	{
			c = c->next;
	}
	c->name = newName;
	c->image = Concat(name, "-Image");
	c->caracter = Concat(name,"-Caracter");
	FILE *file = NULL;
	file = fopen("RTFP.data", "r+");
	if(file != NULL)
	{
		printf("");	
	}	
	else
	{
		printf("impossible d'ouvrir le fichier RTFP.data");
	}
}


/*---Ecriture du fichier RTFP.data a partir le la liste---
---------------------------------------------------------*/
void WriteFile(CharacterInfo *c)
{
	FILE *file = NULL;
	file = fopen("RTFP.data", "w+");
	if(file != NULL)
	{
		do
		{
			char *a;
			fgets(a, 100, file);
			fseek(file, 0, SEEK_END);
			fprintf(file, "%s\n", c->name);
			c = c->next;
		}while(c != NULL);
		printf("fichier ecrit avec succes, merci!\n");
	}
	else
	{
		printf("impossible d'ecrit le fichier\n");
	}
	
}

/*----------Suppression d'un element---------------
-------------------------------------------------*/

CharacterInfo* RemoveInfo(CharacterInfo *c, char *name1)
{ //attention si 0 ou 1 element !! Attention de 10 puis suppr = 90!
	CharacterInfo *a = c;

	//RemoveFile (name); // supprime les fichiers de sauvgarde de l'élement dans la base de donné


	
	 //ConfigFile('-');
//	printf("recherche de : %s dans %s\n", name1, c->name);
	if(CompareChar(c->name, name1))
	{
		printf("element supprimé\n");
		CharacterInfo *b = c;
		c = c->next;
		//WriteFile(c);
		free(b);
		return c;
	}
	else
	{
		//printf("element non trouvé\n");
		
		while(!CompareChar(c->next->name, name1))
		{
			c = c->next;
		}
		if(CompareChar(c->name, name1))
		{
			c->next = c->next->next;
			free(c->next);
		}
		return a;
	}




}



/*-------------------------Comparaison de *char---------------------
--------------------------------------------------------------------*/

int CompareChar(char *a, char *b)
{
	int i = 0;
	while(*(a+i) != '\0')
	{
		if(*(a+i) != *(b+i))
			return 0;
		i++;
		
	}
	return 1;
}


/*--Suppression des fichiers d'un element suprimé--
-------------------------------------------------*/

void RemoveFile (char *FileName)
{

// supprime tous les éléments d'un fichier dans le dossier de sauvgarde => "SaveData"

// Si l'élement n'existe pas, la fonction ne créer aucune erreur.


	char *string = Concat("DataSave/",Concat(FileName, "-Caracter"));
	remove(string);

	string = Concat("DataSave/",Concat(FileName, "-Image"));
	remove(string);



   printf("\n $$$$ L'element %s a bien été suprimé ainsi que tous ses fichiers associés $$$$   \n",FileName);



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


/*----Recupere le nb d'element dans le fichier-----
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
	CharacterInfo *a = c;
	int nb = 1;
	if(CountList != 0)
	{
	do
	{
		printf("Le nb %d s'appelle %s et Caracter = %s et Image = %s\n", nb, a->name, a->caracter, a->image);
		a = a->next;
		nb++;
	}while(a != NULL);
	}
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
						char *t = malloc(50*sizeof(char));
						while((temp = fgetc(file)) != '\n')
						{
							*(t+pos)=temp;
							pos++;
						}
						//fgets(t, 100, file) ;
						//char *w = t;
						//printf("$$$$ %s   $$$$", t);
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
