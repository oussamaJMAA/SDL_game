#include "herbes2.h"

void init_herbes2 (void)
{
	int i;
        jeu.ramasser=nbre_ramasser;
        for (i=0;i<jeu.ramasser;i++)
        {
		ram[i].image=loadImage("ram.png");
                ram[i].w=ram[i].image->w;
                ram[i].h=ram[i].image->h;
        }

	ram[0].x=286;
	ram[0].y=241;

	ram[1].x=649;
	ram[1].y=146;

	ram[2].x=1461;
	ram[2].y=146;

	ram[3].x=2085;
	ram[3].y=346;

	ram[4].x=2575;
	ram[4].y=278;

	ram[5].x=2892;
	ram[5].y=152;

	ram[6].x=4020;
	ram[6].y=327;

	ram[7].x=4746;
	ram[7].y=249;

	ram[8].x=5804;
	ram[8].y=253;

	ram[9].x=6545;
	ram[9].y=253;

}

void update_herbes2 (void)
{
	int i,b=0;
	for (i=0;i<jeu.ramasser;i++)
	{
		if (col_et(&jonathan,&ram[i])==1)
                {
			ram[i]=ram[jeu.ramasser-1];
                        b+=1;
		}
	}
			jeu.ramasser-=b;
                        jonathan.score2+=b;
}

void draw_herbes2 (void)
{
	int i;
	for (i=0;i<jeu.ramasser;i++)
	{
		    SDL_Rect dest;

		    dest.x = ram[i].x-map.startX;
		    dest.y = ram[i].y;
		    dest.w = ram[i].w;
		    dest.h = ram[i].h;
		    SDL_BlitSurface (ram[i].image, NULL , jeu.screen, &dest);

	}
}
