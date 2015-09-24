#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *imageBase = NULL;
	imageBase = SDL_LoadBMP("tutu.bmp");
	if(imageBase != NULL)
	{
		printf("ok charg %d %d\n", imageBase->w, imageBase->h);

		if(imageBase->w <20 | imageBase->h<20)
		{
			printf("echec %d %d\n", imageBase->w, imageBase->h);	
		}
	}
	else
	{
		printf("Echec charg");
	}
	
	SDL_FreeSurface(imageBase);
	SDL_Quit();
	return 0;

       

}

void goToGrey(SDL_Surface * surface)
{
	for(int i = 0, surface->w, i++)
	{
		for(int j = 0, surface->h, j++)
		{
			Uint8 r, v, b;
			SDL_GetRGB(surface->pixels + j * surface->w*i,//a finir
			
		}
	}
}
