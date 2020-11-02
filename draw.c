#include "draw.h"


     void drawImage(SDL_Surface *image, int x, int y)
  {
       SDL_Rect dest;

       dest.x = x;
       dest.y = y;
       dest.w = image->w;
       dest.h = image->h;

       SDL_BlitSurface(image, NULL, jeu.screen, &dest);
   }

      SDL_Surface *loadImage(char *name)
   {

       SDL_Surface *image = IMG_Load(name);

      if (image == NULL)
      {
           printf("Failed to load image %s\n", name);

          return NULL;
       }

       return image;

   }

  void draw(void)
  {
    scrolling_map ();
    drawanimatedjonathan();
    draw_herbes ();
    drawAnimatedEnnemis();
    draw_etoiles();
    afficher_vie();
  }

  void draw2(void)
  {
    scrolling_map ();
    drawanimatedjonathan();
    draw_statues();
    drawAnimatedEnnemis();
    draw_herbes2 ();
    afficher_vie();
  }


  void delay(unsigned int frameLimit)
  {

    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
  }






