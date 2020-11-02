 #include "init.h"


   void init(char *title)
   {

    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0,SDL_HWPALETTE|SDL_DOUBLEBUF);


    if (jeu.screen == NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH,  
                     SCREEN_HEIGHT, SDL_GetError());
            exit(1);
        }


    SDL_WM_SetCaption("BACK TO MAYA", NULL);
    
    SDL_ShowCursor(SDL_DISABLE);


    }

	
         void loadGame(void)
    {
        if (level==1)
        {
		map.background = loadImage("final.png");
		ea.background = loadImage("89.png");
	}
	else if (level==2)
	{
		map.background = loadImage("level2.png");
		ea.background = loadImage("666.png");
	}

     }

    void cleanup()
   {

      if (map.background != NULL)
      {
            SDL_FreeSurface(map.background);
      }
      SDL_Quit();

    }
