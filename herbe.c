#include "herbe.h"

void initialiser_herbes (void)
{
	int i;
	for (i=0;i<nbre_herbes;i++)
	{
		herbe[i].etat=0;
		herbe[i].image=loadImage("herbe.png");
		herbe[i].y=395-herbe[i].image->h;
	}
	herbe[0].x=630 ;
	herbe[1].x=1920 ;
	herbe[2].x=2364 ;
	herbe[3].x=4108 ;
	herbe[4].x=5384;
	herbe[5].x=5740;
}

int update_herbes (void)
{
	int i,b=0;	
	for (i=0;i<nbre_herbes;i++)
	{
		if ((jonathan.x>=herbe[i].x-10) && (jonathan.x<=herbe[i].x+herbe[i].image->w+10))
		{
		if (input.hidden==1)
			herbe[i].etat=1;
		if (herbe[i].etat==1)
		b=1;
		}

		if ((jonathan.x+JONATHAN_WIDTH<=herbe[i].x-10 )|| (jonathan.x>=herbe[i].x+herbe[i].image->w+10))
		{
		herbe[i].etat=0;
		}
	}
	return b;
}


void draw_herbes (void)
{
	int i;
	for (i=0;i<nbre_herbes;i++)
	{
		if (herbe[i].etat==1)
		{
		    SDL_Rect dest;

		    dest.x = herbe[i].x-map.startX;
		    dest.y = herbe[i].y;
		    dest.w = herbe[i].image->w;
		    dest.h = herbe[i].image->h;
		    SDL_BlitSurface (herbe[i].image, NULL , jeu.screen, &dest);
		}
	}
}
