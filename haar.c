# include <stdio.h>
# include <stdlib.h>
# include <SDL/SDL.h>
# include <SDL_image/SDL_image.h>
# include "pretraitement2.h"

int haar1(SDL_surface *integral_image);
//void haar2();
//void haar3();
//void haar4();
//void haar5();

int main()
{
    
}

int haar1(SDL_surface *integral_image)
{
    Uint32 a,b,c,d,e,f;
    a = getpixel(integral_image, 0, 0);
    b = getpixel(integral_image, integral_image->w/2, 0);
    c = getpixel(interal_image, integral_image->w/2, integral_image->h);
    d = getpixel(integral_image, 0, integral_image->h);
    e = getpixel(integral_image, integral_image->w, 0);
    f = getpixel(integral_image, integral_image->w, integral_image->h);

    return (int) (b+f-e-c)-(a+c-b-d); 
}

/*Uint32 haar2(SDL_surface *integral_image)
{
    
}*/
