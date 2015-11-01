#include "haar.h"
#include "pretraitement2.h"
#include "funcInter.h"
#include "data.h"
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  if(argc < 2)
  {
    printf("manque arg");
  }
  else
  {
    if(argc > 2)
    {
	  //deux argument:= 1er grey pour la fonction et le deuxième un nom d'image :appeler
        if(argv[1] == "grey")
        {
          SDL_Surface *surface=IMG_Load(argv[2]);
          goToGrey(surface);
        }
   // 2 argument:= 1er integral pour la fonction et le deuxième un nom d'image:appeler
        if(argv[1] == "integral")
        {
          SDL_Surface *surface=IMG_Load(argv[2]);
          Integral(surface);
        }
//2 argument:= 1er haar pour la fonction et le deuxième un nom d'image:appeler
        if(argv[1] == "haar")
        {
          SDL_Surface *surface=IMG_Load(argv[2]);
          haarr2(surface);
        }

//2 argument 1er decision 2eme entier i: appeler
         if(argv[1] == "decision")
        {
          example* arr;
	      image *tab = malloc(797*sizeof(image));
         arr=weightImage(tab, 797, 797);	
	      float *t=decision(arr,(atoi(argv[2]))/*i*/,797);
        }
//2 argument adaboost pour la fonction entier T pour le nombre de tour:appeler
      if(argv[1] == "adaboost")
      {
        example* arr;
	    image *tab = malloc(797*sizeof(image));
	    arr=weightImage(tab, 797, 797);	
	    adaboost(arr,atoi(argv[2]),797);
      }
    else if(argc == 2)
    {
      //1 argument 1er image pour la fonction:appeler
        if(argv[1] == "image")
        {
          example* arr;
	      image *tab = malloc(797*sizeof(image));
	      arr=weightImage(tab, 797, 797);
        }

    }
    else
    {
      printf("erreur arg");
    }
  }
  }
  return 0;
}
