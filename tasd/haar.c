# include <stdio.h>
# include <stdlib.h>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
#include "funcInter.h"
#include "data.h"
# include "haar.h"
# include <math.h>
# include <dirent.h>
# include <string.h>
int main (int argc, char *argv[])
{
 /*
  if(argc < 2)
  {
    printf("manque arg");
  }
  else
  {
    if(argc >= 3)
    {
    */
	  //deux argument:= 1er grey pour la fonction et le deuxième un nom d'image :appeler
        if((strcmp(argv[1],"grey"))==0)
        {
          SDL_Surface *surface=IMG_Load(argv[2]);
          goToGrey(surface);
	  /*example* arr;
	      image *tab = malloc(797*sizeof(image));
         arr=weightImage(tab, 797, 797);
	  float tab1[4]={-972.0,-1.0,0.222619,24.0};
	  float tab2[4]={3564.0,1.0,0.204066,24.0};
	  float tab3[4]={-1165.5,-1.0,0.198428,21.0};
	  float tab4[4]={1310.0,1.0,0.209290,20.0};
	  float tab5[4]={751.5,1.0,0.199548,9.0};
	  float tab6[4]={1190.0,1.0,0.204657,20.0};
	  float tab7[4]={8061.5,1.0,0.178388,23.0};
	  float tab8[4]={-504.0,-1.0,0.214318,16.0};
	  float tab9[4]={-4092.0,-1.0,0.170897,24.0};
	  float tab10[4]={-298.5,-1.0,0.178046,3.0};
	  float tab11[4]={6309.0,1.0,0.144317,18.0};
	  float tab12[4]={143.5,1.0,0.157750,7.0};
	  float tab13[4]={4826.0,1.0,0.248784,38.0};
	  float tab14[4]={-4212.0,-1.0,0.181252,24.0};
	  float tab15[4]={-1092.0,-1.0,0.191624,24.0};
	  float tab16[4]={8412.0,1.0,0.109095,24.0};
    float tab17[4]={112.5,1.0,0.104319,3.0};
	  float tab18[4]={-175.5,-1.0,0.166597,1.0};
	  float tab19[4]={4109.0,1.0,0.140488,42.0};
	  float tab20[4]={3173.0,1.0,0.158814,38.0};
	  float tab21[4]={1914.0,1.0,0.133727,12.0};
	  float tab22[4]={13.0,1.0,0.158362,2.0};
	  float tab23[4]={262.5,1.0,0.149735,5.0};
	  //evaluation prend en param: example *arr, int i(ieme image)
		// creer nb = nbligne dans fichier ,tab, lis dans le fichier et le remplis (avec serateurs...)
		// creer float = tab[4] * evaluate(tab, arr[i].feat[tab[3]])
	  for(int z=0;z<797;z++)
	  {float a=0.630079*evaluate(tab1,arr[z].feat[81095]);
	  float b=0.692751*evaluate(tab2,arr[z].feat[103319]);
	  float c=0.702541*evaluate(tab3,arr[z].feat[81556]);
	  float d=0.672720*evaluate(tab4,arr[z].feat[105231]);
	  float e=0.699813*evaluate(tab5,arr[z].feat[109008]);
	  float f=0.685823*evaluate(tab6,arr[z].feat[105342]);
	  float g=0.772684*evaluate(tab7,arr[z].feat[99628]);
	  float h=0.654340*evaluate(tab8,arr[z].feat[85502]);
	  float i=0.796683*evaluate(tab9,arr[z].feat[77819]);
	  float j=0.770885*evaluate(tab10,arr[z].feat[72880]);
	  float k=0.900025*evaluate(tab11,arr[z].feat[99926]);
	  float l=0.843853*evaluate(tab12,arr[z].feat[110235]);
	  float m=0.557756*evaluate(tab13,arr[z].feat[99462]);
	  float n=0.756812*evaluate(tab14,arr[z].feat[77819]);
          float o=0.726207*evaluate(tab15,arr[z].feat[77771]);
	  float p=1.068905*evaluate(tab16,arr[z].feat[99467]);
	  float q=1.084687*evaluate(tab17,arr[z].feat[110324]);
	  float r=0.804995*evaluate(tab18,arr[z].feat[72632]);
	  float s=0.915483*evaluate(tab19,arr[z].feat[95971]);
	  float t=0.840918*evaluate(tab20,arr[z].feat[99757]);
	  float u=0.943950*evaluate(tab21,arr[z].feat[106812]);
	  float v=0.840947*evaluate(tab22,arr[z].feat[110893]);
	  float w=0.881422*evaluate(tab23,arr[z].feat[108866]);

	  printf("%f\n",a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w);}*/
        }
   // 2 argument:= 1er integral pour la fonction et le deuxième un nom d'image:appeler
        if((strcmp(argv[1],"integral"))==0)
        {
          SDL_Surface *surface=IMG_Load(argv[2]);
         int **arr= Integral(surface);
	  printf("%d\n%d\n", getpixel(surface,0,0), getpixel(surface,0,1));
          printf("%d\n",arr[0][1]);		
        }
//2 argument:= 1er haar pour la fonction et le deuxième un nom d'image:appeler
        if((strcmp(argv[1],"haar"))==0)
        {	
	   /*example* arr;
	   image *tab = malloc(797*sizeof(image));
           arr=weightImage(tab, 797, 797);
	  cascade(arr,0.1,20,0.1,0.1);*/
		SDL_Surface *surf=IMG_Load("po1.jpg");
		//drawEmptyRect(surf,0,0,250,250,0,0,0);		
		detect(surf);
         //SDL_Surface *surface=IMG_Load(argv[2]);
        
		//int **arr = Integral(surface);
	/*if(argc==4)
	  {printf("Le caractéristique %d vaut %d\n",atoi(argv[3]),(q[atoi(argv[3])]).res);}*/
	 //printf("%d\n",eval(0,arr,0));
        }

//2 argument 1er decision 2eme entier i: appeler
         if((strcmp(argv[1],"decision"))==0)
        {
          example* arr;
	      image *tab = malloc(797*sizeof(image));
         arr=weightImage(tab, 797, 797);
	quickSort(arr,0,796,atoi(argv[2]));	
	     float *t=decision(arr,(atoi(argv[2])),796);
	
	printf("%f|",t[0]);
	printf("%f|",t[1]);
	printf("%f|",t[2]);
	printf("%f|",t[3]);
	printf("%f|",t[4]);
	printf("\n");
        }
//2 argument adaboost pour la fonction entier T pour le nombre de tour:appeler
      if((strcmp(argv[1],"adaboost"))==0)
      {
        example* arr;
	    image *tab = malloc(797*sizeof(image));
	    arr=weightImage(tab, 797, 797);	
	    adaboost(arr,atoi(argv[2]),320);
      }
   // if(argc == 2)
   // {
      //1 argument 1er image pour la fonction:appeler
        if((strcmp(argv[1],"image"))==0)
        {
          example* arr;
	      image *tab = malloc(797*sizeof(image));
	      arr=weightImage(tab, 797, 797);
        }

   /* }
      if(argc > 2)
      {
      */
        if(strcmp(argv[1], "bd") == 0)
        {
          CharacterInfo *c = NULL;
          c= ArrayData();
          char *a = "jerome", *b = "guillaume", *e= "valentin", *d = NULL;
          char **tab = malloc(4 * sizeof(a));
          tab[0] = a;
          tab[1] = b;
          tab[2] = e; 
          tab[3] = d;
          printf("enter\n\n\n"); 

          if(strcmp(argv[2],"-add")==0)
          {
            printf("addddddddddddddddddd!");
            c=AddInfo(c, argv[3]);
          }

          if(strcmp(argv[2],"-addBatch")==0)
          {
            c=AddBatch(c, tab);
          }

          if(strcmp(argv[2], "-remove")==0)
          {
            c=RemoveInfo(c, argv[3]);
          }

           if(strcmp(argv[2] , "-modif")==0)
          {
            ModifInfo(c, argv[3], argv[4]);
          }

          if(strcmp(argv[2], "-ls")==0)
          {
            ShowList(c);
          }
       /* }
      }
      else
    {
      printf("erreur arg");
    }
  }*/
  }
  return 0;
}

example* weightImage(image tab[], int len, int nb) 
{	
  DIR* rep = NULL;
  rep = opendir("visage");
  example *array = malloc(sizeof(example) * nb);
  struct dirent* filel = NULL;
	int i =0;
        
    if(rep != NULL)
	{

		while(((filel = readdir(rep)) != NULL)&(i<299))
		{
			char file[20]="visage/";
			char *data = filel->d_name;
			if(data[0] != '.')
			{
				strcat(file,data);
				image picture;
				picture.name = file;
				tab[i]=picture;
				
				SDL_Surface *win = NULL;
				
				win = IMG_Load(tab[i].name);
				example e;
				e.feat = haarr2(win);
			   	e.label = 1;
			    	e.weight = 1/598.0;
				array[i] = e;
				SDL_FreeSurface(win);
				printf("%s\n", tab[i].name);
				i++;
			}
		}
	
	}

  
	closedir(rep);
  DIR* rep1 = NULL;
  rep1 = opendir("nonvisage");
  
   struct dirent* filel1 = NULL;
	 

    if(rep1 != NULL)
	{

		while(((filel1 = readdir(rep1)) != NULL)&(i<len))
		{
			char file[26]="nonvisage/";
			char *data = filel1->d_name;
			if(data[0] != '.')
			{
				strcat(file,data);
				image picture;
				picture.name = file;
				tab[i]=picture;
				SDL_Surface *win = NULL;
				win = IMG_Load(tab[i].name);
				example e;
				e.feat = haarr2(win);
			   	e.label = -1;
			    	e.weight = 1/998.0;
				array[i] = e;
				SDL_FreeSurface(win);
				printf("%s\n", tab[i].name);
				i++;
			}
		}
	
	}
	printf("%d\n",i);
  
	closedir(rep1);	
		
	
		
return array;}

feature* haarr2(SDL_Surface *image)
{ 
   int nb=0;
   int nbtot=0;
    //queue q = q_new();
    feature *tab=malloc(sizeof(feature)*162336);
    int **arr = Integral(image);
    int a,b,c,d,e,f;
    int S1, S2,S3,S4;
    for(int i=0; i<24; i++)
    {
	for(int j=0; j<24; j++)
	{
		for(int h=1; i+h-1<24; h++)
		{
			for(int w=1; j+2*w-1<24; w++)
			{	
				feature feat;
				feat.t=1;
				feat.i=i;
				feat.j=j;
				feat.w=w;
				feat.h=h;
				a = i+h-1;
				b = j+w-1;
				c = j-1;
				d = i-1;
				e = j+2*w-1;
				S1=(((a<0)||(b<0))?0:arr[a][b])-(((a<0)||(c<0))?0:arr[a][c])-(((d<0)||(b<0))?0:arr[d][b])+(((d<0)||(c<0))?0:arr[d][c]);
				S2=(((a<0)||(e<0))?0:arr[a][e])-(((a<0)||(b<0))?0:arr[a][b])-(((d<0)||(e<0))?0:arr[d][e])+(((d<0)||(b<0))?0:arr[d][b]);
				feat.res=S1-S2;
				//enqueue(q,feat);
				nb++;
				tab[nbtot]=feat;
				nbtot++;
				
			}
		}
	}
    }
	printf("Il y a %d caractéristiques de type 1\n", nb);
	nb=0;

    for(int i=0; i<24; i++)
    {
	for(int j=0; j<24; j++)
	{
		for(int h=1; i+h-1<24; h++)
		{
			for(int w=1; j+3*w-1<24; w++)
			{	
				feature feat;
				feat.t=2;
				feat.i=i;
				feat.j=j;
				feat.w=w;
				feat.h=h;
				a = i+h-1;
				b = j+w-1;
				c = j-1;
				d = i-1;
				e = j+2*w-1;
				f = j+3*w-1;
 				S1 = (((a<0)|(b<0))?0:arr[a][b])-(((a<0)|(c<0))?0:arr[a][c])-(((d<0)|(b<0))?0:arr[d][b])+(((d<0)|(c<0))?0:arr[d][c]);
				S2=(((a<0)|(e<0))?0:arr[a][e])-(((a<0)|(b<0))?0:arr[a][b])-(((d<0)|(e<0))?0:arr[d][e])+(((d<0)|(b<0))?0:arr[d][b]);
				S3 = (((a<0)|(f<0))?0:arr[a][f])-(((a<0)|(e<0))?0:arr[a][e])-(((d<0)|(f<0))?0:arr[d][f])+(((d<0)|(e<0))?0:arr[d][e]);
				feat.res = S1-S2+S3;
				//enqueue(q,feat);
				nb++;
				tab[nbtot]=feat;
				nbtot++;
			}
		}
	}
    }
		printf("Il y a %d caractéristiques de type 2\n", nb);
		nb=0;
    for(int i=0; i<24; i++)
    {
	for(int j=0; j<24; j++)
	{
		for(int h=1; i+2*h-1<24; h++)
		{
			for(int w=1; j+w-1<24; w++)
			{	
				feature feat;
				feat.t=3;
				feat.i=i;
				feat.j=j;
				feat.w=w;
				feat.h=h;
  				a = i+h-1;
				b = j+w-1;
				c = j-1;
				d = i-1;
				e = i+2*h-1;
  				S1=(((a<0)|(b<0))?0:arr[a][b])-(((a<0)|(c<0))?0:arr[a][c])-(((d<0)|(b<0))?0:arr[d][b])+(((d<0)|(c<0))?0:arr[d][c]);
                                S2=(((e<0)|(b<0))?0:arr[e][b])-(((e<0)|(c<0))?0:arr[e][c])-(((a<0)|(b<0))?0:arr[a][b])+(((a<0)|(c<0))?0:arr[a][c]);
				feat.res = S1-S2;
				//enqueue(q,feat);
				nb++;
				tab[nbtot]=feat;
				nbtot++;
			}
		}
	}
    }
 		printf("Il y a %d caractéristiques de type 3\n", nb);
		nb=0;
    for(int i=0; i<24; i++)
    {
	for(int j=0; j<24; j++)
	{
		for(int h=1; i+3*h-1<24; h++)
		{
			for(int w=1; j+w-1<24; w++)
			{	
				feature feat;
				feat.t=4;
				feat.i=i;
				feat.j=j;
				feat.w=w;
				feat.h=h;
				a = i+h-1;
				b = j+w-1;
				c = j-1;
				d = i-1;
				e = i+2*h-1;
				f = i+3*h-1;
				S1 = (((a<0)|(b<0))?0:arr[a][b])-(((a<0)|(c<0))?0:arr[a][c])-(((d<0)|(b<0))?0:arr[d][b])+(((d<0)|(c<0))?0:arr[d][c]);
				S2=(((e<0)|(b<0))?0:arr[e][b])-(((e<0)|(c<0))?0:arr[e][c])-(((a<0)|(b<0))?0:arr[a][b])+(((a<0)|(c<0))?0:arr[a][c]);
				S3=(((f<0)|(b<0))?0:arr[f][b])-(((f<0)|(c<0))?0:arr[f][c])-(((e<0)|(b<0))?0:arr[e][b])+(((e<0)|(c<0))?0:arr[e][c]);
				feat.res = S1-S2+S3;
				//enqueue(q,feat);
				nb++;
				tab[nbtot]=feat;
				nbtot++;
			}
		}
	}
    }
		printf("Il y a %d caractéristiques de type 4\n", nb);
		nb=0;
    for(int i=0; i<24; i++)
    {
	for(int j=0; j<24; j++)
	{
		for(int h=1; i+2*h-1<24; h++)
		{
			for(int w=1; j+2*w-1<24; w++)
			{	
				feature feat;
				feat.t=5;
				feat.i=i;
				feat.j=j;
				feat.w=w;
				feat.h=h;
				a = i+h-1;
				b = j+w-1;
				c = j-1;
				d = i-1;
				e = i+2*h-1;
				f = j+2*w-1;
				S1=(((a<0)|(b<0))?0:arr[a][b])-(((a<0)|(c<0))?0:arr[a][c])-(((d<0)|(b<0))?0:arr[d][b])+(((d<0)|(c<0))?0:arr[d][c]);
				S2=(((e<0)|(b<0))?0:arr[e][b])-(((e<0)|(c<0))?0:arr[e][c])-(((a<0)|(b<0))?0:arr[a][b])+(((a<0)|(c<0))?0:arr[a][c]);
				S3=(((a<0)|(f<0))?0:arr[a][f])-(((a<0)|(b<0))?0:arr[a][b])-(((d<0)|(f<0))?0:arr[d][f])+(((d<0)|(b<0))?0:arr[d][b]);
				S4=(((e<0)|(f<0))?0:arr[e][f])-(((e<0)|(b<0))?0:arr[e][b])-(((a<0)|(f<0))?0:arr[a][f])+(((a<0)|(b<0))?0:arr[a][b]);
				feat.res = S1-S2-S3+S4;
				//enqueue(q,feat);
				tab[nbtot]=feat;
				nb++;
				nbtot++;
			}
		}
	}
    }
	printf("Il y a %d caractéristiques de type 5\n", nb);
	printf("Il y a au total %d caractéristiques dans une image de taille 24*24\n", nbtot);	
	free(arr);
	return tab;
    
}


int scaling(SDL_Surface *image, feature feat,int t)
{ 
    int a,b,c,d,e,f;
    
    int n,w,i,j,h;
    int **arr = Integral(image);

    if(feat.t == 1)
    {
	int x = 1;
	n = 2*feat.w*feat.h;
	i = (int)(round((feat.i*t)/24));
	j = (int)(round((feat.j*t)/24));
	h = (int)(round((feat.h*t)/24));
	while(x < (((int)(round(1+(2*feat.w*t)/24)))/2)&& 2*x<((t-j+1)))
	{
	    x++;
	}
	int S1,S2;
	w = x;
	a = i+h-1;
	b = j+w-1;
	c = j-1;
	d = i-1;
	e = j+2*w-1;
	S1=(((a<0)|(b<0))?0:arr[a][b])-(((a<0)|(c<0))?0:arr[a][c])-(((d<0)|(b<0))?0:arr[d][b])+(((d<0)|(c<0))?0:arr[d][c]);
	S2=(((a<0)|(e<0))?0:arr[a][e])-(((a<0)|(b<0))?0:arr[a][b])-(((d<0)|(e<0))?0:arr[d][e])+(((d<0)|(b<0))?0:arr[d][b]);
    
       return ((S1-S2)*n)/(2*w*h);
    }

    if(feat.t==2)
    {	
	int x=1;
	i = (int)(round((feat.i*t)/24));
	j = (int)(round((feat.j*t)/24));
	h = (int)(round((feat.h*t)/24));
	n = 3*feat.w*feat.h;
	while(x < (((int)(round(1+(3*feat.w*t)/24)))/3)&& 3*x<((t-j+1)))
	{
	    x++;
	}
	w=x;
	int S1,S2,S3;
	a = i+h-1;
	b = j+w-1;
	c = j-1;
	d = i-1;
	e = j+2*w-1;
	f = j+3*w-1;
 	S1 = (((a<0)|(b<0))?0:arr[a][b])-(((a<0)|(c<0))?0:arr[a][c])-(((d<0)|(b<0))?0:arr[d][b])+(((d<0)|(c<0))?0:arr[d][c]);
	S2=(((a<0)|(e<0))?0:arr[a][e])-(((a<0)|(b<0))?0:arr[a][b])-(((d<0)|(e<0))?0:arr[d][e])+(((d<0)|(b<0))?0:arr[d][b]);
	S3 = (((a<0)|(f<0))?0:arr[a][f])-(((a<0)|(e<0))?0:arr[a][e])-(((d<0)|(f<0))?0:arr[d][f])+(((d<0)|(e<0))?0:arr[d][e]);

    return ((S1-S2+S3)*n)/(3*w*h);
    }

    if(feat.t==3)
    {
	int x=1;
	i = (int)(round((feat.i*t)/24));
	j = (int)(round((feat.j*t)/24));
	w = (int)(round((feat.w*t)/24));
	n = 2*feat.w*feat.h;
	while(x < (((int)(round(1+(2*feat.h*t)/24)))/2)&& 2*x<((t-j+1)))
	{
	    x++;
	}
	h=x;
	int S1,S2;
	a = i+h-1;
	b = j+w-1;
	c = j-1;
	d = i-1;
	e = i+2*h-1;
  	S1=(((a<0)|(b<0))?0:arr[a][b])-(((a<0)|(c<0))?0:arr[a][c])-(((d<0)|(b<0))?0:arr[d][b])+(((d<0)|(c<0))?0:arr[d][c]);
        S2=(((e<0)|(b<0))?0:arr[e][b])-(((e<0)|(c<0))?0:arr[e][c])-(((a<0)|(b<0))?0:arr[a][b])+(((a<0)|(c<0))?0:arr[a][c]);

    return ((S1-S2)*n)/(2*w*h);
    }
    
    if(feat.t==4)
    {
	int x=1;
	i = (int)(round((feat.i*t)/24));
	j = (int)(round((feat.j*t)/24));
	w = (int)(round((feat.w*t)/24));
	n = 3*feat.w*feat.h;
	while(x < (((int)(round(1+(3*feat.h*t)/24)))/3)&& 3*x<((t-j+1)))
	{
	    x++;
	}
	h=x;
	int S1,S2,S3;
	a = i+h-1;
	b = j+w-1;
	c = j-1;
	d = i-1;
	e = i+2*h-1;
	f = i+3*h-1;
	S1 = (((a<0)|(b<0))?0:arr[a][b])-(((a<0)|(c<0))?0:arr[a][c])-(((d<0)|(b<0))?0:arr[d][b])+(((d<0)|(c<0))?0:arr[d][c]);
	S2=(((e<0)|(b<0))?0:arr[e][b])-(((e<0)|(c<0))?0:arr[e][c])-(((a<0)|(b<0))?0:arr[a][b])+(((a<0)|(c<0))?0:arr[a][c]);
	S3=(((f<0)|(b<0))?0:arr[f][b])-(((f<0)|(c<0))?0:arr[f][c])-(((e<0)|(b<0))?0:arr[e][b])+(((e<0)|(c<0))?0:arr[e][c]);
	
    return ((S1-S2+S3)*n)/(3*w*h);
    }
    
    if(feat.t==5)
    {
	int x=1;
	i = (int)(round((feat.i*t)/24));
	j = (int)(round((feat.j*t)/24));
	n = 4*feat.w*feat.h;
	while(x < (((int)(round(1+(2*feat.h*t)/24)))/2)&& 2*x<((t-j+1)))
	{
	    x++;
	}
	h=x;
	x=1;	
	while(x < (((int)(round(1+(2*feat.w*t)/24)))/2)&& 2*x<((t-j+1)))
	{
	    x++;
	}
	w=x;
	int S1,S2,S3,S4;
	a = i+h-1;
	b = j+w-1;
	c = j-1;
	d = i-1;
	e = i+2*h-1;
	f = j+2*w-1;
	S1=(((a<0)|(b<0))?0:arr[a][b])-(((a<0)|(c<0))?0:arr[a][c])-(((d<0)|(b<0))?0:arr[d][b])+(((d<0)|(c<0))?0:arr[d][c]);
	S2=(((e<0)|(b<0))?0:arr[e][b])-(((e<0)|(c<0))?0:arr[e][c])-(((a<0)|(b<0))?0:arr[a][b])+(((a<0)|(c<0))?0:arr[a][c]);
	S3=(((a<0)|(f<0))?0:arr[a][f])-(((a<0)|(b<0))?0:arr[a][b])-(((d<0)|(f<0))?0:arr[d][f])+(((d<0)|(b<0))?0:arr[d][b]);
	S4=(((e<0)|(f<0))?0:arr[e][f])-(((e<0)|(b<0))?0:arr[e][b])-(((a<0)|(f<0))?0:arr[a][f])+(((a<0)|(b<0))?0:arr[a][b]);
	
    return ((S1-S2-S3+S4)*n)/(4*w*h);
    }
  return 0;
}


static inline void swap(example* a, example* b)
{
  example temp = *a;
  *a = *b;
  *b = temp;
}


int partitionner(example *tableau, int p, int r,int k) {
    int pivot = (tableau[p].feat[k]).res, i = p-1, j = r+1;
    int temp;
    while (1) {
        do
            j--;
        while ((tableau[j].feat[k]).res > pivot);
        do
            i++;
        while ((tableau[i].feat[k]).res  < pivot);
        if (i < j) {
            swap(tableau+i,tableau+j);
        }
        else
            return j;
    }
}

void quickSort(example *tableau, int p, int r,int k) {
    int q;
    if (p < r) {
        q = partitionner(tableau, p, r,k);
        quickSort(tableau, p, q,k);
        quickSort(tableau, q+1, r,k);
    }
}
/*static inline
int is_sorted(example *begin, example *end,int j) {
  for (; begin < end - 1 && search((*begin).feat,j).res <= search((*(begin + 1)).feat,j).res; begin++) {}
  return begin == end - 1;
}*/


float* decision(example* arr, int j, int n)
{	
    
    float *ar = malloc(sizeof(float) * 5);
    float treshold = ((arr[0].feat[j]).res)-1.0;
    float margin = 0.0;
    float error = 2.0;
    float toggle = 1.0;
    float w1=0;
    float w2=0;
    float w3=0;
    float w4=0;
    for(int i=0; i<n; i++)
    {
      if(arr[i].label == 1)
      {		
        if((((arr[i].feat)[j]).res) > treshold)
        {
          w1 = w1 + arr[i].weight;
        }
      }
    }
    for(int i=0; i<n; i++)
    {
      if(arr[i].label == -1)
      {
        if((((arr[i].feat)[j]).res) > treshold)
        {
          w2 = w2 + arr[i].weight;
        }
      }
    }
   
    int k = 0;
    float nmargin = margin;
    float ntreshold = treshold;
    float nerror;
    float errorp;
    float errorm;
    float ntoggle;

    while(1)
    {
      errorp = w3 + w2;
      errorm = w1 + w4;
      if(errorp < errorm)
      {
        nerror = errorp;
        ntoggle = 1;
      }
      else
      {
        nerror = errorm;
        ntoggle = -1;
      }
      if((nerror < error) || ((nerror == error) && (nmargin > margin)))
      {
        error = nerror;
        toggle = ntoggle;
        margin = nmargin;
	treshold = ntreshold;
      }

      if(k == n)
      {
        break;
      }
      k++;
      
      while(1)
      {
        if(arr[k].label==-1)
        {
          w4 = w4+arr[k].weight;
          w2 = w2-arr[k].weight;
        }
        else
        {
          w3 = w3+arr[k].weight;
          w1 = w1-arr[k].weight;
        }
        if((k==n) || (((arr[k].feat[j]).res) != ((arr[k+1].feat[j]).res)))
        {
          break;
        }
        else
        {
          k++;
        }
      }
      if(k == n)
      {
        ntreshold = ((arr[n-1].feat[j]).res);
        nmargin = 0;
      }
      else
      {
        ntreshold = (((arr[k].feat[j]).res)+((arr[k+1].feat[j]).res))/2.0;
        nmargin = ((arr[k+1].feat[j]).res) - ((arr[k].feat[j]).res);
      }
    }
    ar[0] = treshold;
    ar[1] = toggle;
    ar[2] = error;
    ar[3] = margin;
    ar[4] =j;
    return ar;
}

int evaluate(float *tab,feature f)
{
   if((f.res>=tab[0])&&(tab[1]==1))
	{
		return 1;
	}
   if((f.res<tab[0])&&(tab[1]==1))
	{
		return -1;
	}
 if((f.res>=tab[0])&&(tab[1]==-1))
	{
		return -1;
	}
   if((f.res<tab[0])&&(tab[1]==-1))
	{
		return 1;
	}
return 0;
   
}
int evaluate2(float *tab,int f)
{
   if((f>=tab[0])&&(tab[1]==1))
	{
		return 1;
	}
   if((f<tab[0])&&(tab[1]==1))
	{
		return -1;
	}
 if((f>=tab[0])&&(tab[1]==-1))
	{
		return -1;
	}
   if((f<tab[0])&&(tab[1]==-1))
	{
		return 1;
	}
return 0;
   
}


float *Beststump (example* arr,int d,int n)
{
	float *ar = malloc(sizeof(int)*5);
	ar[2]=2;
	ar[3]=0;
	
	for (int i=0; i<d; i++)
	{	
		quickSort(arr,0,320,i);
		
		printf("%d\n",i);
		float *ar2 = decision(arr,i,n);
		if(((ar2[2]<ar[2]))||(((ar2[3]>ar[3])&&(ar2[2]==ar[2]))))
		{
				ar[0]=ar2[0];
				ar[1]=ar2[1];
				ar[2]=ar2[2];
				ar[3]=ar2[3];
				ar[4]=i;
			
		}

	}
  return ar;
}

void adaboost(example* arr, int T,int n)
{ 
	FILE* file = NULL;
  	file = fopen("strongClassifieur.txt", "r+");
 
	for(int i=0;i<T;i++)
	{
           printf("%d",i);
	   float error=0;
	   float *tab= Beststump(arr,162335,n);
	    for(int j=0;j<n;j++)
		{
			if(evaluate(tab,(arr[j].feat[(int)tab[4]]))!=arr[j].label)
	            error=error+arr[j].weight;
		}
		
	    if((error==0)&(T==1))
  	    {
                  	if(file != NULL)
  			{
   			for(int i=0; i<5; i++)
   			{
    			  fputc('|',file);
    			  fprintf(file, "%f", tab[i]);
   			}
   			fprintf(file, "\n");}
  	    }
	    else
	        {
		    float coeff=(1.0/2.0)*(log((1.0-error)/error));
		    for(int i=n-2;i>0;i--)
		    {
		            if(evaluate(tab,(arr[i].feat[(int)tab[4]]))!=arr[i].label)
			    {arr[i+1].weight=((arr[i].weight)/2.0)*(1.0/error);}
				else
			    {arr[i+1].weight=((arr[i].weight)/2.0)*(1.0/(1.0-error));}
			    
			 }
	if(file != NULL)
  			 {
   			   for(int i=0; i<5; i++)
   			  {
    			   fputc('|',file);
    			   fprintf(file, "%f", tab[i]);
   			   }
			   fputc('|',file);
			   fprintf(file,"%f",coeff);
   			   fprintf(file, "\n");}
		  
		}
    	
	
	}
	fclose(file);	
}

example* positive(image tab[], int len, int nb) 
{	
  DIR* rep = NULL;
  rep = opendir("positive");
  example *array = malloc(sizeof(example) * nb);
  struct dirent* filel = NULL;
	int i =0;
        
    if(rep != NULL)
	{

		while(((filel = readdir(rep)) != NULL)&(i<nb))
		{
			char file[20]="positive/";
			char *data = filel->d_name;
			if(data[0] != '.')
			{
				strcat(file,data);
				image picture;
				picture.name = file;
				tab[i]=picture;
				
				SDL_Surface *win = NULL;
				
				win = IMG_Load(tab[i].name);
				example e;
				e.feat = haarr2(win);
				array[i] = e;
				SDL_FreeSurface(win);
				printf("%s\n", tab[i].name);
				i++;
			}
		}
	
	}

	closedir(rep);
	return array;
}

example* negative(image tab[], int len, int nb) 
{	
  DIR* rep = NULL;
  rep = opendir("negative");
  example *array = malloc(sizeof(example) * nb);
  struct dirent* filel = NULL;
	int i =0;
        
    if(rep != NULL)
	{

		while(((filel = readdir(rep)) != NULL)&(i<nb))
		{
			char file[20]="negative/";
			char *data = filel->d_name;
			if(data[0] != '.')
			{
				strcat(file,data);
				image picture;
				picture.name = file;
				tab[i]=picture;
				
				SDL_Surface *win = NULL;
				
				win = IMG_Load(tab[i].name);
				example e;
				e.feat = haarr2(win);
				array[i] = e;
				SDL_FreeSurface(win);
				printf("%s\n", tab[i].name);
				i++;
			}
		}
	
	}

	closedir(rep);
	return array;
}

int eval(int n,example* arr,int sl)
{
	FILE* fsrc;
	char buffer[128];
	
	if((fsrc = fopen("strongClassifieur.txt", "rb")) == NULL)
	{
		printf("error\n");
	}
	float s=0;	
	while ( fgets ( buffer, sizeof buffer, fsrc) != NULL ) /* read a line */
      	{
		
		int k = 0;
		size_t i = 1;
		int j=0;
		//printf("%c",buffer[i]);
        	while(buffer[i] != '\0')
		{//printf("%c",buffer[i]);
			float tab[6];
			char buffer2[64];
			if(buffer[i] == '|' || buffer[i+1] == '\0')
			{
				
				tab[k] = strtof(buffer2,NULL);
				//char buffer2[64] = "";
				//printf("|%s",buffer2);
				
				k++;	
				i++;
				j=0;
			if(k==6)
			{
				
				s=s+tab[5]*(evaluate(tab,arr[n].feat[(int)tab[4]])+sl);
			}
				
			}
			

				
				buffer2[j] =buffer[i];
				//printf("%c",buffer2[j]);
				i++;
				j++;
			
		
		}
		printf("\n");		 
      	}
      fclose (fsrc);
	//printf("%f",s);
	return s>0?1:-1;
}

int eval2(feature *feat,int sl)
{
	FILE* fsrc;
	char buffer[128];
	
	if((fsrc = fopen("strongClassifieur.txt", "rb")) == NULL)
	{
		printf("error\n");
	}
	float s=0;	
	while ( fgets ( buffer, sizeof buffer, fsrc) != NULL ) /* read a line */
      	{
		
		int k = 0;
		size_t i = 1;
		int j=0;
		//printf("%c",buffer[i]);
        	while(buffer[i] != '\0')
		{//printf("%c",buffer[i]);
			float tab[6];
			char buffer2[64];
			if(buffer[i] == '|' || buffer[i+1] == '\0')
			{
				
				tab[k] = strtof(buffer2,NULL);
				//char buffer2[64] = "";
				//printf("|%s",buffer2);
				
				k++;	
				i++;
				j=0;
			if(k==6)
			{
				
				s=s+tab[5]*(evaluate2(tab,feat[(int)tab[4]].res));
			}
				
			}
			

				
				buffer2[j] =buffer[i];
				//printf("%c",buffer2[j]);
				i++;
				j++;
			
		
		}
		printf("\n");		 
      	}
      fclose (fsrc);
	//printf("%f",s);
	return s>0?1:-1;
}

void copy()
{
	FILE* fsrc;
	FILE* fdest;
	char buffer[512];
	int nblus;
	if((fsrc = fopen("strongClassifieur.txt", "rb")) == NULL)
	{
		printf("error\n");
	}	
	if((fdest = fopen("Cascade.txt", "a")) == NULL)
	{
		fclose(fsrc);
	}
	while((nblus = fread(buffer, 1, 512, fsrc)) != 0)
	{
		fwrite(buffer, 1, nblus, fdest);	
	}
	fprintf(fdest, "\n");
	fclose(fdest);
	fclose(fsrc);
}

void cascade(example* arr,float fpr,int l,float gl,float bl)
{
	float nfpr = 1;
	float	  ngl =0;
	int t=797;
	int neg=498;
	example* arr2;
	image *tab = malloc(797*sizeof(image));
	arr2=weightImage(tab, 797, 797);
	int vect[797]={0};
	while(nfpr > fpr)
	{
		float u = 0.01;   
    	ngl++;
    	float snl = 0;
    	int tl = 1;
		float ge = 0;
		//int gg = 0;
		float be = 0;
		//int bg = 0;
		float nbl = 0;
		eight : adaboost(arr, tl,t-1);
		//ecrire dans cascade.txt, le contenu de strongclassifieur.txtfait
		copy();
		//(fait)ecrire la fonction qui evalue un classifieur fort
		//et faire l'evaluation pour les 3 tableux
		//faire une boucle jusqua 298 qui compte le nombre d'image ou ya une erreur 		(gamma e)
		
        
		nine :for(int i=0;i<t;i++)
			{
			    if(eval(i,arr2,snl)!=arr[i].label)
				{
					if(arr2[i].label==1)
					{
						ge++;
					}
					else
					{
						be++;
					}
				}
				else
				{
					if(arr2[i].label==-1)
					{
						vect[i]+=1;
					}
				}
			}
		ge=ge/299;
		be=be/neg;
		// idem pour les autres
		//ngl = max(ge,gg);
		//nbl = max(be,bg);
		ngl=ge;
		nbl=be;
		printf("%f\n",ge);
		printf("%f\n",be);
	
		if((ngl <= gl) && (1-nbl >= 1-bl))
		{
			printf("ok");
			nfpr = nfpr * ngl;
			
		}
		else if(((ngl <= gl) && (1-nbl < 1-bl)) && (u > 0.00001 ))
		{
				snl += u;
				if((snl<-1) || (snl>1))
				{
					u = u/2;
					snl -= u;
				}	
				printf("ok1");
				goto nine;
		}
		else if(((ngl > gl) && (1-nbl >= 1-bl)) && (u > 0.00001 ))
		{
				snl -= u;
				if((snl<-1) || (snl>1))
				{
					u = u/2;
					snl += u;
				}
				printf("ok2");	
				goto nine;
		}
		else
		{
			int nl=(10*l+10)<200?(10*l+10):200;
			if(tl > nl)
					{
						snl = -1;
						while(1-nbl < 0.99)
						{
	                                                for(int i=0;i<t;i++)
							{
							    if(eval(i,arr2,snl)!=arr[i].label)
								{
									if(arr2[i].label==1)
									{
										ge++;
									}
									else
									{
										be++;
									}
								}
							}
							ngl = ge;
							nbl = be;
						}	
						nfpr *= ngl;
					}
					else
					{
						printf("ok");
						tl++;
						goto eight;
					}
		}
		
		for(int i=0;i<797;i++)
		{
			if(vect[i]==1)
			{
			
			
			 	
			  for(int j=i; j<t; j++)
			  {
				arr[j] = arr[j+1];
			  }
			  
			  
			
					vect[i]+=1;
					t--;
					neg--;
			}
		}
	}
}
void drawEmptyRect(SDL_Surface * surf,int posX, int posY, int width, int length, int R, int G, int B)
{
	SDL_Rect ligneHaut;
	ligneHaut.x = posX-4;
	ligneHaut.y = posY-4;
	ligneHaut.w = length;
	ligneHaut.h = 4;
 
	SDL_FillRect(surf, &ligneHaut, SDL_MapRGB(surf->format, R, G, B));
 
	SDL_Rect ligneDroite;
	ligneDroite.x = posX+length-4;
	ligneDroite.y = posY-4;
	ligneDroite.w = 4;
	ligneDroite.h = width;
 
	SDL_FillRect(surf, &ligneDroite, SDL_MapRGB(surf->format, R, G, B));
 
	SDL_Rect ligneGauche;
	ligneGauche.x = posX-4;
	ligneGauche.y = posY-4;
	ligneGauche.w = 4;
	ligneGauche.h = width;
 
	SDL_FillRect(surf, &ligneGauche, SDL_MapRGB(surf->format, R, G, B));
 
	SDL_Rect ligneBas;
	ligneBas.x = posX-4;
	ligneBas.y = posY+width-4;
	ligneBas.w = length;
	ligneBas.h = 4;
 
	SDL_FillRect(surf, &ligneBas, SDL_MapRGB(surf->format, R, G, B));
	SDL_SaveBMP (surf,"tata.bmp");
}
void detect(SDL_Surface *surf)
{
	int k=0;
	SDL_Rect R,p;
	p.x=0;
	p.y=0;
	SDL_Surface *fenetre=NULL;
	for(int i=0; i<surf->w-24; i++)
	{
		for(int j=0; j<surf->h-24; j++)
		{
			
						
			fenetre=SDL_CreateRGBSurface(SDL_HWSURFACE,24,24,32,0,0,0,0);
			R.x=i;
			R.y=j;
			R.w=24;
			R.h=24;
			SDL_BlitSurface(surf,&R,fenetre,&p);	
			feature* f=haarr2(fenetre);
			/*if(eval2(f,0)==1)
			{
				drawEmptyRect(surf,0,0,24,24,255,255,0);
			}*/
			free(fenetre);
			free(f);
		}
	}
	printf("%d",k);	
}
