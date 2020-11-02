   #include "jonathan_vh.h"


  void initializeJonathan_vh(void)
   {

       jonathan_vh.sprite = loadImage("jonathan_vh.png");

    jonathan_vh.direction = RIGHT;
    jonathan_vh.etat = WALK;
   

    jonathan_vh.frameNumber = 0;
    jonathan_vh.frameTimer = TIME_BETWEEN_2_FRAMES;

       jonathan_vh.x = 20;
       jonathan_vh.y = 120;

   }

  
    void drawJonathan_vh(void)
{
    SDL_Rect dest;

    dest.x = jonathan_vh.x-map.startX;
    dest.y = jonathan_vh.y-map.startY;
    dest.w = JONATHAN_VH_WIDTH;
    dest.h = JONATHAN_VH_HEIGHT;

    SDL_Rect src;

    src.x = jonathan_vh.frameNumber * JONATHAN_VH_WIDTH;
    src.y = 0;
    src.w = JONATHAN_VH_WIDTH;
    src.h = JONATHAN_VH_HEIGHT;

    SDL_BlitSurface(jonathan_vh.sprite, &src, jeu.screen, &dest);
}

 void centerScrollingOnJonathan_vh(void)
 {
    map.startX = (jonathan_vh.x+JONATHAN_WIDTH) - (SCREEN_WIDTH / 2);
    map.startY = (jonathan_vh.y+JONATHAN_HEIGHT) - (SCREEN_HEIGHT / 2);

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
    printf("%d          %d\n",jonathan_vh.x,map.startX);
 }
 void updateJonathan_vh(void)
{

     if (input.left == 1)
    {
        jonathan_vh.x -= JONATHAN_VH_SPEED;
       
        if (jonathan_vh.x < 0)
        {
            jonathan_vh.x = 0;
        }
        if(jonathan_vh.direction !=LEFT)
        {
            jonathan_vh.direction = LEFT;
            jonathan_vh.sprite = loadImage("jonathan_vh.png");
        }
    }

    else if (input.right == 1)
    {
        jonathan_vh.x += JONATHAN_VH_SPEED;
       
        if (jonathan_vh.x + JONATHAN_VH_WIDTH >= LEVEL1_WIDTH)
        {
            jonathan_vh.x = LEVEL1_WIDTH - JONATHAN_VH_WIDTH;
        }
        if(jonathan_vh.direction !=RIGHT)
        {
            jonathan_vh.direction =  RIGHT;
            jonathan_vh.sprite = loadImage("jonathan_vh.png");
        }

    }
   
    else if (input.up == 1)
    {   
          jonathan_vh.y -= JONATHAN_VH_SPEED;
          
        if (jonathan_vh.y<0)
        {
            jonathan_vh.y=0;
        }
        if(jonathan_vh.direction !=UP)
        {
            jonathan_vh.direction =UP;
            jonathan_vh.sprite = loadImage("jonathan_vh.png");
        }
     }

     else if (input.down == 1)
     {
            jonathan_vh.y += JONATHAN_VH_SPEED;

        if (jonathan_vh.y + JONATHAN_VH_HEIGHT >= LEVEL1_HEIGHT)
        {
            jonathan_vh.y = LEVEL1_HEIGHT - JONATHAN_VH_HEIGHT;
        }
        if(jonathan_vh.direction !=DOWN)
        {
            jonathan_vh.direction =  DOWN;
            jonathan_vh.sprite = loadImage("jonathan_vh.png");
        }
      }
      centerScrollingOnJonathan_vh();
}
