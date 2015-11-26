#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

struct Matrix
{
  int w;
  int h;
  int *mat;
};

Uint32 AddMat(struct Matrix *s, int x, int y, int mat[3][3])
{
  int r=0, g=0, b=0;

  int pix = getpixel(s, x, y);
  SDL_GetRGB(pix, s->format, &r, &g, &b);
  printf("1 pix r = %d\n", g);
  g=0;
  for(int i = -1; i<2; i++)
  {
    Uint8 tr=0, tg=0, tb=0;
    for(int j = -1; j<2;j++)
    {
      tr=0; tg=0; tb=0;

      int temp = getpixel(s, x+j, y+i);
     // SDL_GetRGB(temp, s->format, &tr, &tg, &tb);

      r += mat[j+1][i+1]*tr;
      g += mat[j+1][i+1]*tg;
      b += mat[j+1][i+1]*tb;
      printf("rrr pix r = %d* %d: %d\n", tg, mat[j+1][i+1], g);

    }
  }
  //printf("\n2 pix r = %d\n", g);
  //pix = SDL_MapRGB(s->format, r, g, b);
  return pix;
}

SDL_Surface* PassMat(SDL_Surface *s, int mat[3][3]) 
{
  SDL_Surface *tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);

  for(int i = 1; i<s->h-1; i++)
  {
    for(int j = 1; j<s->w-1; j++)
    {
      defPixel(tmp, j, i, Add(s, j, i, mat));
    }
  }
  return tmp;
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



struct Matrix* SDL_to_Matrix(SDL_Surface *s)
{
  struct Matrix *tmp = malloc(sizeof(struct Matrix));
  tmp->mat = malloc(sizeof(int)*(s->w)*(s->h));
  tmp->w =  s->w;
  tmp->h = s->h;
  //printf("size: %d %d", tmp->w, tmp->h);
  //  //*(mat+s->w*s->h+1) = NULL;
  //    // int size = 0;
  for(int i = 0; i < s->h; i++)
  {
    Uint32 pix = 0;
    Uint8 val = 0;
    for(int j = 0; j < s->w; j++)
    {
      pix = getpixel(s, j, i);
      //  printf("fin get pixel\n %d", i);
      SDL_GetRGB(pix, s->format, &val, &val, &val);
      //printf("setPixel\n");
      *(tmp->mat+s->w*i+j) = (int)val;

    }
  }
    return tmp;
  //
}


int mat[3][3]  = {{0,1,0},
  {0, 0,0},
  {0,0,0}};
struct Matrix* Init_Mat(int w, int h)
{
  struct Matrix *s = malloc(sizeof(s));
  s->w = w;
  s->h = h;
  s->mat = malloc(sizeof(int)*w*h);
  return s;
}

Uint32 Add(SDL_Surface *s, int x, int y, int mat[3][3])
{
  Uint8 r=0, g=0, b=0;


  Uint32 pix = getpixel(s, x, y);
  SDL_GetRGB(pix, s->format, &r, &g, &b);
  printf("1 pix r = %d\n", g);
  g=0;

  for(int i = -1; i<2; i++)
  {
    Uint8 tr=0, tg=0, tb=0;
    for(int j = -1; j<2;j++)
    {
      tr=0; tg=0; tb=0;

      Uint32 temp = getpixel(s, x+j, y+i);
      SDL_GetRGB(temp, s->format, &tr, &tg, &tb);

      r += mat[j+1][i+1]*tr;
      g += mat[j+1][i+1]*tg;
      b += mat[j+1][i+1]*tb;
      printf("rrr pix r = %d* %d: %d\n", tg, mat[j+1][i+1], g);

     // pix+=mat[j+1][i+1]*temp;
    }
  }
  //printf("\n2 pix r = %d\n", pix);

  pix = SDL_MapRGB(s->format, r, g, b);
  return pix;
}

SDL_Surface* PassMat(SDL_Surface *s, int mat[3][3]) 
{
  SDL_Surface *tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);

  for(int i = 1; i<s->h-1; i++)
  {
    for(int j = 1; j<s->w-1; j++)
    {
      defPixel(tmp, j, i, Add(s, j, i, mat));
    }
  }
  return tmp;
}

void print(SDL_Surface *s)
{
  for(int i = 0; i<s->h; i++)
  {
    for(int j = 0; j<s->w; j++)
    {
      Uint32 pix = getpixel(s, j, i);
      Uint8 r, g, b;
      SDL_GetRGB(pix, s->format, &r, &g, &b);
      printf("%3d ", g);
    }
    printf("\n");
  }

}

SDL_Surface* BuildTest(SDL_Surface *s)
{
  SDL_Surface *tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);
  defPixel(tmp, 0, 0, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 0, 1, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 0, 2, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 0, 3, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 0, 4, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 1, 0, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 1, 1, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 1, 2, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 1, 3, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 1, 4, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 2, 0, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 2, 1, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 2, 2, SDL_MapRGB(s->format, 100, 150, 100));
  defPixel(tmp, 2, 3, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 2, 4, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 3, 0, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 3, 1, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 3, 2, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 3, 3, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 3, 4, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 4, 0, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 4, 1, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 4, 2, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 4, 3, SDL_MapRGB(s->format, 100, 100, 100));
  defPixel(tmp, 4, 4, SDL_MapRGB(s->format, 100, 100, 100));
  return tmp;
}

int main()
{
SDL_Surface *tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);

  SDL_Surface *s1 = IMG_Load("img.jpg");

  SDL_Surface *s = BuildTest(s1); 
  struct Matrix *m = SDL_to_Matrix(s) 
  print(s);
  s = PassMat(s, mat);
  print(s);
  SDL_SaveBMP(s, "test.bmp");
}

