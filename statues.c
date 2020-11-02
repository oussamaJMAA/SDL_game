#include "statues.h"

void initialiser_statues (void)
{
	int i;
	for (i=0;i<nbre_statues;i++)
	{
		sta[i].etat=0;
		sta[i].image=loadImage("statue.png");
	}
	sta[0].x=734 ;
	sta[1].x=1573;
	sta[2].x=2418;
	sta[3].x=3796;
	sta[4].x=4822;
	sta[5].x=5568;
        sta[6].x=6348;

	sta[0].y=0 ;
	sta[1].y=0;
	sta[2].y=120;
	sta[3].y=197;
	sta[4].y=100;
	sta[5].y=96;
        sta[6].y=99;
}

int update_statues (void)
{
	int i,b=0;	
	for (i=0;i<nbre_statues;i++)
	{
		if ((jonathan.x>=sta[i].x-10) && (jonathan.x<=sta[i].x+sta[i].image->w+10))
		{
		if (input.hidden==1)
			sta[i].etat=1;
		if (sta[i].etat==1)
		b=1;
		}

		if ((jonathan.x+JONATHAN_WIDTH<=sta[i].x-10 )|| (jonathan.x>=sta[i].x+sta[i].image->w+10))
		{
		sta[i].etat=0;
		}
	}
	return b;
}


void draw_statues (void)
{
	int i;
	for (i=0;i<nbre_statues;i++)
	{
		if (sta[i].etat==1)
		{
		    SDL_Rect dest;

		    dest.x = sta[i].x-map.startX;
		    dest.y = sta[i].y;
		    dest.w = sta[i].image->w;
		    dest.h = sta[i].image->h;
		    SDL_BlitSurface (sta[i].image, NULL , jeu.screen, &dest);
		}
	}
}
