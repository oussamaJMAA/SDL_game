#include "etoile.h"

void init_etoiles (void)
{
	int i;
        int x=500;
        jeu.nbre_etoiles=nbre_Etoiles;
        for (i=0;i<jeu.nbre_etoiles;i++)
        {
                x=x+120;
		etoile[i].image=loadImage("1.png");
                etoile[i].x=x;
                etoile[i].y=340;
                etoile[i].w=etoile[i].image->w;
                etoile[i].h=etoile[i].image->h;
        }
}

void update_etoiles (void)
{
	int i,b=0;
	for (i=0;i<jeu.nbre_etoiles;i++)
	{
		if (col_et(&jonathan,&etoile[i])==1)
                {
			etoile[i]=etoile[jeu.nbre_etoiles-1];
                        b+=1;
		}
	}
			jeu.nbre_etoiles-=b;
                        jonathan.score+=b;
}

void draw_etoiles (void)
{
	int i;
	for (i=0;i<jeu.nbre_etoiles;i++)
	{
		    SDL_Rect dest;

		    dest.x = etoile[i].x-map.startX;
		    dest.y = etoile[i].y;
		    dest.w = etoile[i].w;
		    dest.h = etoile[i].h;
		    SDL_BlitSurface (etoile[i].image, NULL , jeu.screen, &dest);

	}
}
