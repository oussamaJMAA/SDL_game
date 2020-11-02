
#include "collision.h"

SDL_Color GetPixel (SDL_Surface* pSurface,int x,int y)
{
  SDL_Color color;
  Uint32 col= 0;
  char* pPosition = (char*) pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col,pPosition,pSurface->format->BytesPerPixel);
  SDL_GetRGB (col,pSurface->format,&color.r,&color.g,&color.b);
 return (color);
}

int collision_back (Hero *a)
{
  SDL_Rect point[8];
  SDL_Color couleur[8];

point[0].x=a->x+a->w+10;
point[0].y=a->y+a->h/2;

point[4].x=a->x+a->w+10;
point[4].y=a->y+a->h/4;

point[5].x=a->x+a->w+10;
point[5].y=a->y+(a->h*3)/4;

point[1].x=a->x+a->w/2;
point[1].y=a->y+a->h;

point[2].x=a->x-10;
point[2].y=a->y+a->h/2;

point[6].x=a->x-10;
point[6].y=a->y+a->h/4;

point[7].x=a->x-10;
point[7].y=a->y+(a->h*3)/4;

point[3].x=a->x+a->w/2;
point[3].y=a->y;

couleur[0]=GetPixel (ea.background, point[0].x, point[0].y);
couleur[1]=GetPixel (ea.background, point[1].x, point[1].y);
couleur[2]=GetPixel (ea.background, point[2].x, point[2].y);
couleur[3]=GetPixel (ea.background, point[3].x, point[3].y);
couleur[4]=GetPixel (ea.background, point[4].x, point[4].y);
couleur[5]=GetPixel (ea.background, point[5].x, point[5].y);
couleur[6]=GetPixel (ea.background, point[6].x, point[6].y);
couleur[7]=GetPixel (ea.background, point[7].x, point[7].y);


if (couleur[1].r==0 && couleur[1].g==0 && couleur[1].b==0)
return 10;

else if (couleur[3].r==255 && couleur[3].g==255 && couleur[3].b==255)
return 4;

else if (couleur[1].r==255 && couleur[1].g==255 && couleur[1].b==255)
return 3;

else if ((couleur[2].r==255 && couleur[2].g==255 && couleur[2].b==255)||(couleur[6].r==255 && couleur[6].g==255 && couleur[6].b==255)||(couleur[7].r==255 && couleur[7].g==255 && couleur[7].b==255))
return 2;

else if ((couleur[0].r==255 && couleur[0].g==255 && couleur[0].b==255)||(couleur[4].r==255 && couleur[4].g==255 && couleur[4].b==255)||(couleur[5].r==255 && couleur[5].g==255 && couleur[5].b==255))
return 1;

else return 0;

}
//ajouter des points pour les collisions , ajuster les trucs fel gimp , revoir le code de la collision , ajouter les ennemis , collision rouge , developper un algorithme pour hiddden 


