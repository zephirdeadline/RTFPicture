#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#define ZEROX = 640/2
#define ZEROY = 480/2
#include <time.h>
#include <unistd.h>
#include <SDL/SDL_ttf.h>

struct vector
{
  int x;
  int y;
  int nb;
};


void pause1();
Uint32 getpixel( SDL_Surface *s, unsigned x, unsigned y);
void defPixel(SDL_Surface *s, int x, int y, Uint32 color);
float pow1(int a);
float sizeCircle(int r);
void drag(SDL_Surface *t,int z, int q, int j, float a, float b, float c, float d);
struct vector* rotate(struct vector *a, int i, int o);
void drawModulo(SDL_Surface *s, int t, int u);
void findEq(SDL_Surface *s, int zerox, int zeroy, int r, float t);
struct vector *findVal(int v);
struct vector* tab[1000];

int mod =200;
float table = 2;
//int r = 200;
int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
  TTF_Init();
  TTF_Font *police = TTF_OpenFont("DejaVuSans.ttf", 65);
  SDL_Color couleurNoire = {255, 255, 255};
  SDL_Color couleurNoire1 = {0, 0, 0};

  int zerox = 640/2, zeroy = 480/2;
  SDL_Surface *ecran = NULL, *texte = NULL;
  ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
  SDL_Rect position;
  position.x = 0;
  position.y = 0;
  int r = 200;

  printf("ok\n");
  SDL_Surface *Main = SDL_CreateRGBSurface(SDL_HWSURFACE,640,480,32,0,0,0,0);
  defPixel(Main, zerox, zeroy, SDL_MapRGB(Main->format,255,255,255));

  while(table<20)
  {
//texte = TTF_RenderText_Blended(police, "Salut les Zr0s !", couleurNoire); 
  printf("ok\n");
 // texte = TTF_RenderText_Shaded(police, mod, couleurNoire, couleurNoire1);
    /*dessine le cercle*/////////////////  

    for (int i = zerox-r; i<= zerox+r; i++)
      for(int j = zeroy-r; j <= zeroy+r; j++)
        if((pow1(i-zerox) + pow1(j-zeroy) > pow1(r)) && (pow1(i-zerox) + pow1(j-zeroy) < pow1(r+1))  )
          defPixel(Main, i, j, SDL_MapRGB(Main->format,255,255,255));


    float size;
    printf("taille: %f\n", size = sizeCircle(r)); 

    drawModulo(Main,mod , r);
    findEq(Main, zerox, zeroy,  r, table);

    for(int i  = 0; i<mod; i++)
      printf("x: %d, y: %d, nb: %d\n", tab[i]->x, tab[i]->y, tab[i]->nb);

    SDL_BlitSurface(Main, NULL, ecran, &position);

    SDL_Flip(ecran);
    SDL_FillRect(Main, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); 
   sleep(0.2);
  table+=0.1; 
  }
  pause1();
  TTF_CloseFont(police);
  SDL_Quit();
TTF_Quit();
  return EXIT_SUCCESS; 
}


void findEq(SDL_Surface *s, int zerox, int zeroy, int r, float t)
{

  struct vector *a, *b;

  for(int i = 0; i<mod; i++)
  {
    struct vector *a, *b;
    a = tab[i];
    b = findVal((int)(i*t)%mod);
    printf("find: %d\n", b->nb);
    drag(s, zerox, zeroy, r, a->x, a->y, b->x, b->y);
  }
}


struct vector* findVal(int v)
{
  int i = 0;
  while(tab[i]->nb != v)
  {
    i++;
  }
  printf("find: %d\n", tab[i]->nb);
  return tab[i];
}


void drawModulo(SDL_Surface *Main, int n, int r)
{
  int nb = 0;

  struct vector *v = malloc(sizeof(struct vector));
  v->x = 0;
  v->y =r;
  v->nb = 0;
  tab[0] = v;
  nb ++;
  for(int i = 1; i<n; i++)
  {
    struct vector *l = malloc(sizeof(struct vector));
    l = rotate(tab[nb-1], mod, r);
    l->nb = i;
    tab[i] = l;
    nb++;
  }
  for (int i = 0; i<n; i++)
  {
    tab[i]->x+=640/2;
    tab[i]->y+=480/2;

    defPixel(Main, tab[i]->x, tab[i]->y, SDL_MapRGB(Main->format, 250, i*50, i*50));
    defPixel(Main, tab[i]->x-1, tab[i]->y, SDL_MapRGB(Main->format, 250, i*50, i*50));
    defPixel(Main, tab[i]->x, tab[i]->y-1, SDL_MapRGB(Main->format, 250, i*50, i*50));
    defPixel(Main, tab[i]->x-1, tab[i]->y-1, SDL_MapRGB(Main->format, 250, i*50, i*50));

  }

}

struct vector* rotate(struct vector *a, int n, int r)
{
  float l = sizeCircle(r)/n;
  float rad = l/r;

  struct vector *v = malloc(sizeof(struct vector));
  v->x = (a->x*cos(rad)-a->y*sin(rad));
  v->y = (a->x*sin(rad)+a->y*cos(rad));
  v->x = v->x*r/(sqrt(pow1(v->x)+pow1(v->y)));
  v->y = v->y*r/(sqrt(pow1(v->x)+pow1(v->y)));

  return v;
}



void drag(SDL_Surface *s,int zerox, int zeroy,int r, float ax, float ay, float bx, float by)
{
  float coef = (by-ay)/(bx-ax);
  printf("coef dir: %f\n", coef);
  float b = (ay-coef*ax);
  for (int i = zerox-r; i< zerox+r; i++)
    for(int j = zeroy-r; j < zeroy+r; j++)
    {
      if(j >= (int)(coef*(i)+b) && j <= (int)(coef*(i)+1+b) && (pow1(i-zerox) + pow1(j-zeroy) < pow1(r)) )
      {
        defPixel(s, i, j, SDL_MapRGB(s->format,255,255,255));

        //printf("ok");
      }
      //printf("OK j= %f, %d\n", coef*i+j, j);

    }
}

float sizeCircle(int r)
{
  return 2*3.1416 *r;
}


float pow1(int a)
{
  return a*a;
}



Uint32 getpixel(SDL_Surface *surface,unsigned x, unsigned y)
{
  Uint8 *p=(Uint8 *)surface->pixels+y*surface->pitch+x*(surface->format->BytesPerPixel);
  switch (surface->format->BytesPerPixel)
  {
    case 1:
      return *p;
    case 2:
      return *(Uint16 *)p;
    case 3:
      if(SDL_BYTEORDER==SDL_BIG_ENDIAN)
        return p[0]<<16|p[1]<<8|p[2];
      else
        return p[0]|p[1]<<8|p[2]<<16;
    case 4:
      return *(Uint32 *)p;

  }
  return 0;
}


void defPixel(SDL_Surface *surface,int x,int y,Uint32 color)
{
  int byte=surface->format->BytesPerPixel;
  Uint8 *p=(Uint8 *)surface->pixels+y*surface->pitch+x*byte;
  switch(byte)
  {
    case 1:
      *p=color;
      break;
    case 2:
      *(Uint16*)p=color;
      break;
    case 3:
      if(SDL_BYTEORDER==SDL_BIG_ENDIAN)
      {
        p[0]=(color>>16)&0xff;
        p[1]=(color>>8)&0xff;
        p[2]=color & 0xff;
      }
      else
      {
        p[0]=color & 0xff;
        p[1]=(color>>8) &0xff;
        p[2]=(color>>16)& 0xff;
      }
      break;
    case 4:
      *(Uint32 *)p=color;
      break;
  }
}

void pause1()
{
  int continuer = 1;
  SDL_Event event;

  while (continuer)
  {

    
       SDL_WaitEvent(&event);
       switch(event.type)
       {
       case SDL_QUIT:
       continuer = 0;
       }
       
   // mod++;
  }
}