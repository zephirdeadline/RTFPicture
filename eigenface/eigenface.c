#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../pretraitement2.h"

SDL_Surface* Moyenne(SDL_Surface **tab, size_t t);
SDL_Surface* Diff(SDL_Surface* a, SDL_Surface* b);
int main()
{
  /*TEST MOYENNE
  SDL_Surface** tab = malloc(2*sizeof(SDL_Surface));
  tab[0] = IMG_Load("../AnnexesRTFPicture/photo1.jpg");
  tab[1] = *tab ;
  SDL_SaveBMP(Moyenne(tab, 2), "test.bmp");
  */
  SDL_SaveBMP(Diff(IMG_Load("../AnnexesRTFPicture/photo1.jpg"), IMG_Load("../AnnexesRTFPicture/photo1.jpg")), "testDiff.bmp");
  return 0;
}


/*************************************************************
 * *******************Moyenne de l'image********************
 * **********************************************************/


SDL_Surface* Moyenne(SDL_Surface **tab, size_t size)
{
  SDL_Surface *tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, (**tab).w, (**tab).h, 32, 0, 0, 0, 0);
  Uint32 res = 0;
  //printf("entree premiere boucle\n");
  for(size_t j = 0; j < (**tab).w; j++)
  {
    //printf("2eme boucle\n");
    for(size_t k = 0; k < (**tab).h; k++)
    {
      //printf("troisieme boucle\n");
      for(size_t i = 0; i < size; i++)
      {
        res += getpixel(*(tab+i), j, k);
      }
      defPixel(tmp, j, k, res/size);
      res = 0;
    }
  }
  return tmp;
}


/****************************************************************
 * *****************Difference entree et moyenne******************
 * **************************************************************/

SDL_Surface* Diff(SDL_Surface* entry, SDL_Surface* moy)
{
  for(size_t i = 0; i < entry->w; i++)
  {
    for(size_t j = 0; j < entry->h; j ++)
    {
      //rajouter surement boucle for
      defPixel(entry, i, j, getpixel(entry, i, j) - getpixel(moy, i, j));
    }
  }
  return entry;
}
