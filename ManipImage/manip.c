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

struct Matrix* Init_Mat(int w, int h)
{
  struct Matrix *s = malloc(sizeof(struct Matrix));
  s->w = w;
  s->h = h;
  s->mat = malloc(sizeof(int)*w*h);
  for(int i = 0; i<w*h; i++)
  {
    *(s->mat+i) = 0;
  }
  return s;
}


void printM(struct Matrix *mat)
{
  int k = 0;
  while(k<mat->w*mat->h)
  {
    for(int i = 0; i<mat->w; i++)
    {
      printf("%3d ", *(mat->mat+k));
      //mat = mat+1;
      k++;
    }
    printf("\n");
  }
}



int AddMat(struct Matrix *s, int x, int y, int mat[3][3])
{
  int r=0, g=0, b=0;

  //int pix = *(s->mat+mat->w*y+x);
  //SDL_GetRGB(pix, s->format, &r, &g, &b);
  //printf("1 pix r = %d\n", g);

  for(int i = -1; i<2; i++)
  {
    int tr=0; //tg=0, tb=0;
    for(int j = -1; j<2;j++)
    {
      tr=0; //tg=0; tb=0;

      tr = *(s->mat+s->w*(y+i)+(x+j));
      // SDL_GetRGB(temp, s->format, &tr, &tg, &tb);

      r += mat[i+1][j+1]*tr;
      //g += mat[j+1][i+1]*tg;
      //b += mat[j+1][i+1]*tb;
      //printf("rrr pix r = %d* %d: %d\n", tr, mat[j+1][i+1], tr);

    }
  }
  //printf("\n2 pix r = %d\n", g);
  //pix = SDL_MapRGB(s->format, r, g, b);
  return r;
}







struct Matrix* PassMatMat(struct Matrix *s, int mat[3][3]) 
{
  struct Matrix *temp = Init_Mat(s->w, s->h);

  for(int i = 1; i<s->h-1; i++)
  {
    for(int j = 1; j<s->w-1; j++)
    {
      *(temp->mat+s->w*i+j) = AddMat(s, j, i, mat);
    }
  }
  return temp;
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



void SDL_to_Matrix(SDL_Surface *s, struct Matrix **r, struct Matrix **g, struct Matrix **b)
{
  (*r)= malloc(sizeof(struct Matrix));
  (*r)->mat = malloc(sizeof(int)*(s->w)*(s->h));
  (*r)->w =  s->w;
  (*r)->h = s->h;
  (*g)= malloc(sizeof(struct Matrix));

  (*g)->mat = malloc(sizeof(int)*(s->w)*(s->h));
  (*g)->w =  s->w;
  (*g)->h = s->h;
  (*b)= malloc(sizeof(struct Matrix));

  (*b)->mat = malloc(sizeof(int)*(s->w)*(s->h));
  (*b)->w =  s->w;
  (*b)->h = s->h;

  //printf("size: %d %d", tmp->w, tmp->h);
  //  //*(mat+s->w*s->h+1) = NULL;
  //    // int size = 0;
  for(int i = 0; i < s->h; i++)
  {
    Uint32 pix = 0;
    Uint8 vr, vg, vb;
    for(int j = 0; j < s->w; j++)
    {
      pix = getpixel(s, j, i);
      //  printf("fin get pixel\n %d", i);
      SDL_GetRGB(pix, s->format, &vr, &vg, &vb);
      //printf("setPixel\n");
      *((*r)->mat+s->w*i+j) = (int)vr;
      *((*g)->mat+s->w*i+j) = (int)vg;
      *((*b)->mat+s->w*i+j) = (int)vb;
      //printf("%d\n", *(g->mat+s->w*i+j));
    }
  }

  //
}


int mat[3][3]  = {{0,1,0},
  {1, 5,1},
  {0,1,0}};

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

SDL_Surface* Convert(struct Matrix *m, struct Matrix *gr, struct Matrix *bl)
{
  SDL_Surface *tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, m->w, m->h, 32, 0, 0, 0, 0);
  for(int i = 0; i<m->h; i++)
  {
    for(int j = 0; j<m->w; j++)
    {
      Uint32 pix = 0;
      Uint8 r, g, b;
      r = *(m->mat+m->w*i+j);
      g = *(gr->mat+gr->w*i+j);
      b = *(bl->mat+bl->w*i+j);

      if(r<0) r = 0;
      if(r>255) r = 255;
      if(g<0) g = 0;
      if(g>255) g = 255;
      if(b<0) b = 0;
      if(b>255) b = 255;

      pix = SDL_MapRGB(tmp->format, r, g, b);
      defPixel(tmp, j, i, pix);
    }
  }
  return tmp;
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
  defPixel(tmp, 2, 2, SDL_MapRGB(s->format, 150, 150, 150));
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



SDL_Surface* Convolution(SDL_Surface *s, int mat[3][3])
{
  int offset = 3/2;
  SDL_Surface *tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, s->w, s->h, 32, 0, 0, 0, 0);
  for(int i = 1; i<s->h-1; i++)
  {
    for(int j = 1; j<s->w-1; j++)
    {
      float r, g, b, cr=0, cg=0, cb=0;
      for(int y = -offset; y<=offset; y++)
      {
        for(int x = -offset; x<=offset; x++)
        {
          Uint32 pix = getpixel(s, j+x, i+y);

          float coef = mat[x+offset][y+offset];
          SDL_GetRGB(pix, s->format, &r, &g, &b);
          cr += r*coef;
          cg += g*coef;
          cb += b*coef;
        }
      }
      if(cr<0) cr = 0;
      if(cr>255) cr = 255;
      if(cg<0) cg = 0;
      if(cg>255) cg = 255;
      if(cb<0) cb = 0;
      if(cb>255) cb = 255;
      defPixel(tmp, j, i, SDL_MapRGB(s->format, (int)cr, (int)cg, (int)cb));
    }
  }
  return tmp;



}




int main()
{
  //SDL_Surface *tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 5, 32, 0, 0, 0, 0);

  SDL_Surface *s1 = IMG_Load("img.jpg");
  s1 = Convolution(s1, mat);
  //SDL_Surface *s = BuildTest(s1); 
  //struct Matrix *r = NULL, *g = NULL, *b = NULL;
  // printf("init mat\n");
  //SDL_to_Matrix(s1, &r, &g, &b); 
  //printf("init mat%d\n", *(r->mat+2));

  //printM(r);
  //printf("init mat\n");
  //printM(g);
  //printM(b);
  //printf("avant passmat\n");
/*  r = PassMatMat(r, mat);
  g = PassMatMat(g, mat);
  b = PassMatMat(b, mat);
*/
  //s1 = Convert(r, g, b);
  //print(s1);
  SDL_SaveBMP(s1, "test.bmp");
}

