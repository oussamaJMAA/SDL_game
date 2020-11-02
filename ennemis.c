#include "ennemis.h"


void initializeEnnemis(void)
{
    int i;
	jeu.nbre_ennemis=n_ennemis;
    for (i=0;i<jeu.nbre_ennemis;i++)
    {
        ennemi[i].sprite = loadImage("ennemi.png");
        ennemi[i].direction = RIGHT;
        ennemi[i].frameNumber = 0;
        ennemi[i].frameTimer = TIME_BETWEEN_2_FRAMES;
        ennemi[i].posTimer=10;
        ennemi[i].w=ENNEMI_WIDTH;
        ennemi[i].h=ENNEMI_HEIGHT;
	ennemi[i].attack=0;
     }

    ennemi[0].x=785;
    ennemi[0].y=0;
    ennemi[0].posX=785;
    ennemi[0].posY=0;

    ennemi[1].x=1986;
    ennemi[1].y=0;
    ennemi[1].posX=1986;
    ennemi[1].posY=0;

    ennemi[2].x=2450;
    ennemi[2].y=0;
    ennemi[2].posX=2450;
    ennemi[2].posY=0;


    ennemi[3].x=4167;
    ennemi[3].y=0;
    ennemi[3].posX=4167;
    ennemi[3].posY=0;

    ennemi[4].x=5141;
    ennemi[4].y=0;
    ennemi[4].posX=5141;
    ennemi[4].posY=0;


    ennemi[5].x=5827;
    ennemi[5].y=0;
    ennemi[5].posX=5827;
    ennemi[5].posY=0;

    ennemi[6].x=5900;
    ennemi[6].y=0;
    ennemi[6].posX=5900;
    ennemi[6].posY=0;
}

void initializeEnnemis2(void)
{
    int i;
	jeu.nbre_ennemis=n_ennemis;
    for (i=0;i<jeu.nbre_ennemis;i++)
    {
        ennemi[i].sprite = loadImage("ennemi.png");
        ennemi[i].direction = RIGHT;
        ennemi[i].frameNumber = 0;
        ennemi[i].frameTimer = TIME_BETWEEN_2_FRAMES;
        ennemi[i].posTimer=10;
        ennemi[i].w=ENNEMI_WIDTH;
        ennemi[i].h=ENNEMI_HEIGHT;
	ennemi[i].attack=0;
     }
    
    ennemi[0].x=876;
    ennemi[0].y=0;
    ennemi[0].posX=876;
    ennemi[0].posY=0;

    ennemi[1].x=1637;
    ennemi[1].y=0;
    ennemi[1].posX=1637;
    ennemi[1].posY=0;

    ennemi[2].x=2490;
    ennemi[2].y=0;
    ennemi[2].posX=2490;
    ennemi[2].posY=0;


    ennemi[3].x=3857;
    ennemi[3].y=0;
    ennemi[3].posX=3857;
    ennemi[3].posY=0;

    ennemi[4].x=4880;
    ennemi[4].y=0;
    ennemi[4].posX=4880;
    ennemi[4].posY=0;


    ennemi[5].x=5702;
    ennemi[5].y=0;
    ennemi[5].posX=5702;
    ennemi[5].posY=0;

    ennemi[6].x=6431;
    ennemi[6].y=0;
    ennemi[6].posX=6431;
    ennemi[6].posY=0;
}

void attack_ennemis (Hero *e)
{
		if ((e->direction==RIGHT) && ((e->x-jonathan.x)>=-SCREEN_WIDTH/2+40) && ((e->x-jonathan.x)<=0) && (jonathan.hidden==0))
		{
			e->attack=1;
			if (e->x<=jonathan.x+35)
				e->x+=35;
			if (collision_back (e)==1)
				e->x-=35;
		}
                else if ((e->direction==LEFT) && ((jonathan.x-e->x)>=-SCREEN_WIDTH/2+40) && ((jonathan.x-e->x)<=0) && (jonathan.hidden==0))
		{
			e->attack=1;
			if (e->x>=jonathan.x-35)
				e->x-=35;
			if (collision_back (e)==2)
				e->x+=35;			
		}
		else e->attack=0;
}



void updateEnnemis (void)
{
   int i;
   for (i=0;i<jeu.nbre_ennemis;i++)
   {
       if (ennemi[i].posTimer==0)
       {
		attack_ennemis(&ennemi[i]);
                ennemi[i].y+=50;
		if (ennemi[i].attack==0)
		{
		       if (ennemi[i].direction==RIGHT && collision_back (&ennemi[i])!=0)
			{
			    if (ennemi[i].x>=ennemi[i].posX+100)
			    ennemi[i].direction=LEFT;
			 }


			else if (ennemi[i].direction==LEFT && collision_back (&ennemi[i])!=0)
			{
			    if (ennemi[i].x<=ennemi[i].posX-100)
			    ennemi[i].direction=RIGHT;
			}
			switch (ennemi[i].direction)
			{	
				case RIGHT:
				ennemi[i].x+=ennemi_speed;
				break;
				
				case LEFT:
				ennemi[i].x-=ennemi_speed;
				break;
			}
		}

            while (collision_back (&ennemi[i])==4)
            ennemi[i].y+=1;
            while (collision_back (&ennemi[i])==3)
            ennemi[i].y-=1;
            while (collision_back (&ennemi[i])==2)
            ennemi[i].x-=1;
            while (collision_back (&ennemi[i])==1)
            ennemi[i].x+=1;

            if (collide(&jonathan,&ennemi[i])==1 && (jonathan.hidden==0))
            {
		if (jonathan.direction==RIGHT && ennemi[i].direction==LEFT)
			{jonathan.x-=35;
			ennemi[i].x+=45;}
		else if (jonathan.direction==LEFT && ennemi[i].direction==RIGHT)
                	{jonathan.x+=35;
			ennemi[i].x-=45;}
		else if (jonathan.direction==RIGHT && ennemi[i].direction==RIGHT)
			{jonathan.x+=35;
			ennemi[i].x-=45;}
		else if (jonathan.direction==LEFT && ennemi[i].direction==LEFT)
                	{jonathan.x-=35;
			ennemi[i].x+=45;}
		jonathan.vies-=1;
	    }


            ennemi[i].posTimer=10;
       }
       else ennemi[i].posTimer--;
   }
}

void drawEnnemis (void)
{
    int i;
    for (i=0;i<jeu.nbre_ennemis;i++)
    {
	    SDL_Rect dest;

	    dest.x = ennemi[i].x-map.startX;
	    dest.y = ennemi[i].y;
	    dest.w = ENNEMI_WIDTH;
	    dest.h = ENNEMI_HEIGHT;

	    SDL_Rect src;

	    src.x = ennemi[i].frameNumber * ENNEMI_WIDTH;

	    if(ennemi[i].direction ==LEFT)
	    src.y = ENNEMI_HEIGHT;
	    else if (ennemi[i].direction == RIGHT)
	    src.y = 0;

	    src.w = ENNEMI_WIDTH;
	    src.h = ENNEMI_HEIGHT;

	    SDL_BlitSurface(ennemi[i].sprite, &src, jeu.screen, &dest);
      }
}

void drawAnimatedEnnemis(void)
{
     int i;

     
     for (i=0;i<jeu.nbre_ennemis;i++)
     {
          if (ennemi[i].frameTimer <= 0)
    	  {
		  ennemi[i].frameTimer = TIME_BETWEEN_2_FRAMES;
		  ennemi[i].frameNumber++;

		  if(ennemi[i].frameNumber >= ennemi[i].sprite->w / ENNEMI_WIDTH)
		     {
		        ennemi[i].frameNumber = 0;
		     }
          }
          else
                  ennemi[i].frameTimer--;

      }

    drawEnnemis();
}
