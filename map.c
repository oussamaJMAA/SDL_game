#include "map.h"

void scrolling_map ()
{
    SDL_Rect dest;

    dest.x = 0;
    dest.y = 0;
    dest.w = SCREEN_WIDTH;
    dest.h = SCREEN_HEIGHT;

    SDL_Rect src;

    src.x = map.startX;
    src.y = map.startY;
    src.w = SCREEN_WIDTH;
    src.h = SCREEN_HEIGHT;


    SDL_BlitSurface(map.background, &src, jeu.screen, &dest);

   
}
