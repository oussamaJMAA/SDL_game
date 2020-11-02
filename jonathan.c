   #include "jonathan.h"


  void initializeJonathan(void)
   {

       jonathan.sprite = loadImage("jonathan.png");
       jonathan.gain=loadImage("gain.png");

    jonathan.direction = RIGHT;
    jonathan.etat = WALK;
    jonathan.hidden = 0;
   

    jonathan.frameNumber = 0;
    jonathan.frameTimer = TIME_BETWEEN_2_FRAMES;

       jonathan.x = 0;
       jonathan.y = 0;
       jonathan.h = JONATHAN_HEIGHT;
       jonathan.w = JONATHAN_WIDTH;
       jonathan.posTimer=5;
       jonathan.jump=0;
       jonathan.score=0;
       jonathan.vies=3;
       jonathan.score2=0;


   }

  
    void drawJonathan(void)
{
    SDL_Rect dest;

    dest.x = jonathan.x-map.startX;
    dest.y = jonathan.y;
    dest.w = JONATHAN_WIDTH;
    dest.h = JONATHAN_HEIGHT;

    SDL_Rect src;

    src.x = jonathan.frameNumber * JONATHAN_WIDTH;

    if(jonathan.direction ==LEFT)
    src.y = JONATHAN_HEIGHT;
    else if (jonathan.direction == RIGHT)
    src.y = 0;

    src.w = JONATHAN_WIDTH;
    src.h = JONATHAN_HEIGHT;

    SDL_BlitSurface(jonathan.sprite, &src, jeu.screen, &dest);
}

 void centerScrollingOnJonathan(void)
 {
    map.startX = (jonathan.x+JONATHAN_WIDTH) - (SCREEN_WIDTH / 2);
    map.startY = (jonathan.y+JONATHAN_HEIGHT) - (SCREEN_HEIGHT / 2);

 
    if (map.startX < 0)
    {
        map.startX = 0;
    }

    else if (map.startX + SCREEN_WIDTH >= LEVEL1_WIDTH)
    {
        map.startX = LEVEL1_WIDTH - SCREEN_WIDTH;
    }


    if (map.startY < 0)
    {
        map.startY = 0;
    }

    else if (map.startY + SCREEN_HEIGHT >= LEVEL1_HEIGHT)
    {
        map.startY = LEVEL1_HEIGHT - SCREEN_HEIGHT;
    }
 }
 void updateJonathan(void)
{
    int test;
    arduinoReadData(&test);
    if (jonathan.posTimer==0)
    {       
            jonathan.y+=25;
            if (jonathan.etat==UP)
            {
                    if (jonathan.direction==RIGHT)
                    jonathan.x+=20;
                    else if (jonathan.direction==LEFT)
		    jonathan.x-=20;
              }
	     if ((input.left == 1 || test==2)&& jonathan.etat!=UP)
	    {
		jonathan.x -= JONATHAN_VH_SPEED;
		jonathan.frameNumber++;
	       /*collision bords background*/
		if (jonathan.x < 0)
		{
		    jonathan.x = 0;
		}
		if(jonathan.direction !=LEFT)
		{
		    jonathan.direction = LEFT;
		    jonathan.sprite = loadImage("jonathan.png");
		    jonathan.frameNumber=0;
		}
	    }

	    else if ((input.right == 1 || test==1)&& jonathan.etat!=UP)
	    {
		jonathan.x += JONATHAN_VH_SPEED;
		jonathan.frameNumber++;
	       
		if (jonathan.x + JONATHAN_WIDTH >= LEVEL1_WIDTH)
		{
		    jonathan.x = LEVEL1_WIDTH - JONATHAN_WIDTH;
		}
		if(jonathan.direction !=RIGHT)
		{
		    jonathan.direction =  RIGHT;
		    jonathan.sprite = loadImage("jonathan.png");
		    jonathan.frameNumber=0;
		}
	    }
            else if ((input.up==1 || test==3)&& jonathan.jump!=2)
            {
                if (jonathan.jump==0)
		{
		        jonathan.y+=v_saut;
                        if (jonathan.direction==RIGHT)
		        jonathan.x+=JONATHAN_VH_SPEED/2;
                        else if (jonathan.direction==LEFT)
                        jonathan.x-=JONATHAN_VH_SPEED/2;
		        jonathan.etat=UP;
			jonathan.jump=1;
		}
                else if (input.up==1 && jonathan.jump==1)
                {
			jonathan.y+=v_saut;
                        jonathan.jump=2;
		}
                input.up=0;
            }

	    while (collision_back (&jonathan)==4)
            jonathan.y+=1;

            while (collision_back (&jonathan)==3)
            {
		jonathan.etat=WALK;
            	jonathan.jump=0;
            	jonathan.y-=1;
	    }
		
	    while (collision_back (&jonathan)==2)
            jonathan.x+=1;

	    while (collision_back (&jonathan)==1)
            jonathan.x-=1;

            jonathan.posTimer=5;
	    
	    if (level==1)
	    jonathan.hidden=update_herbes ();
	    else if (level==2)
	    jonathan.hidden=update_statues ();

      	    centerScrollingOnJonathan();
       }
       else jonathan.posTimer--;
}

void afficher_vie(void)
{
	SDL_Surface *vie1, *vie2, *vie3;
	vie1=IMG_Load("vie1.png");
	vie2=IMG_Load("vie2.png");
	vie3=IMG_Load("vie3.png");
        
	SDL_Rect pos1,pos2,pos3;
	pos1.x=jonathan.x-map.startX;
	pos1.y=jonathan.y-vie1->h;
	pos2.x=jonathan.x-map.startX;
	pos2.y=jonathan.y-vie2->h;
	pos3.x=jonathan.x-map.startX;
	pos3.y=jonathan.y-vie3->h;	
           		
  	 if(jonathan.vies==3)
        	SDL_BlitSurface(vie3, NULL,jeu.screen,&pos3);
	else if (jonathan.vies==2)
		SDL_BlitSurface(vie2, NULL,jeu.screen,&pos2);	
	else if (jonathan.vies==1)	
		SDL_BlitSurface(vie1, NULL,jeu.screen,&pos1);
}	
		

