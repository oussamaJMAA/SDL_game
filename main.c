    #include "main.h"

    int main( int argc, char *argv[ ] )
   {
      TTF_Font *police = NULL;
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;
    int compteur=0;
    level=1;

        init("Back To Maya");
        if(loadFont(&police) == EXIT_FAILURE)
	{
		printf("Erreur Chargement Font ttf\n");
		return(-1);
	}
	initialiser_herbes ();
        initText(&txt);
	int i;
	switch (menu())
	{
		case 7:
			init_etoiles();
			initializeJonathan();
			initializeEnnemis();
			break;
		case 8:
			lire ("sauvegarde.bin");
			for (i=0;i<jeu.nbre_etoiles;i++)
			{
				etoile[i].image=loadImage("1.png");
			}
			jonathan.sprite = loadImage("jonathan.png");
			for (i=0;i<jeu.nbre_ennemis;i++)
			{
				ennemi[i].sprite = loadImage("ennemi.png"); 
			}
			break;
	}
        loadGame();
        atexit(cleanup);

    go = 1;

    while (go != 0)
    {
	getInput();
	if (input.escape==1)
	{
		switch (menu())
		{	
			case 7:
			initializeJonathan();
			initializeEnnemis();
			init_etoiles();
			initialiser_herbes ();
			level=1;
			loadGame();
			break;
			case 8:
			break ;
			case 99:
			sauvegarde ("sauvegarde.bin");
			exit(0);
		}
		input.left=0;input.right=0;
		input.escape=0;
	}	

	if (level==1)
	{
		updateJonathan();
		update_etoiles();
		updateEnnemis();
		draw();
		displayText(police,&txt);
		level=gestion();	
		SDL_Flip(jeu.screen);
		SDL_Delay(1);
		delay(frameLimit);
		frameLimit = SDL_GetTicks() + 16;
		if (level==2)
		{
			compteur=1;
		}
	}
	if (level==2)
	{
		if (compteur==1)
		{
			loadGame();
			initializeJonathan();
			initializeEnnemis2();
			init_herbes2();
			initialiser_statues();
			compteur=0;	
		}
		updateJonathan();
		update_herbes2();
		updateEnnemis();
		draw2();
		displayText(police,&txt);
		level=gestion();	
		SDL_Flip(jeu.screen);
		SDL_Delay(1);
		delay(frameLimit);
		frameLimit = SDL_GetTicks() + 16;
	}
		
        

    }
	freeFont(&police);
	exit(0);

    }
