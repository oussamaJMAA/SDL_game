#include "gestion.h"

int gestion (void)
{
	if (jonathan.score/9>=1 && level==1)
	{
		jonathan.vies++;
		jonathan.score-=9;
	}

	if (collision_back (&jonathan)==10)
	{
		input.left=0;input.right=0;
		SDL_Delay(1000);
		jonathan.x-=200;
		jonathan.y=0;
		jonathan.vies--;
		jonathan.etat=WALK;
	}

	int i,b=0;
	for (i=0;i<jeu.nbre_ennemis;i++)
	{
		if (collision_back (&ennemi[i])==10)
		{
			ennemi[i]=ennemi[jeu.nbre_ennemis-1];
			b++;
			SDL_Delay(300);
		}
	}
	jeu.nbre_ennemis-=b;
		
	
	if (jonathan.vies==0)
	{
					if (level==1)
					{
						initializeJonathan();
						initializeEnnemis();
						init_etoiles();
						initialiser_herbes ();
					}
				
					else if (level==2)
					{
						initializeJonathan();
						initializeEnnemis2();
						init_herbes2 ();
						initialiser_statues();
					}
		game_over=loadImage("gameover.png");
    		drawImage(game_over,0,0);
		input.left=0;input.right=0;
		int a=1;
		SDL_Flip(jeu.screen);
		SDL_Event event;
		while(a!=0)
			{
				SDL_WaitEvent(&event);
				switch (event.type)
				case SDL_KEYDOWN:
                		switch (event.key.keysym.sym)
                   		case SDLK_RETURN:
                        	{
				a=0;return level;}
			}}
	else if (jonathan.x>=LEVEL1_WIDTH && level==1) return 2;
	else return level;

}
