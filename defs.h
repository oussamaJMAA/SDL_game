  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <math.h>
  #include <SDL/SDL.h>
  #include <SDL/SDL_image.h>
  #include <SDL/SDL_ttf.h>
  #include<SDL/SDL_mixer.h>
 
  #define SCREEN_WIDTH 640
  #define SCREEN_HEIGHT 480

   #define JONATHAN_WIDTH 70
   #define JONATHAN_HEIGHT 135

   #define ENNEMI_WIDTH 65
   #define ENNEMI_HEIGHT 137

   #define JONATHAN_VH_WIDTH 265
   #define JONATHAN_VH_HEIGHT 300


  #define LEVEL1_WIDTH 8000 
  #define LEVEL1_HEIGHT 480

  #define TIME_BETWEEN_2_FRAMES 10
  #define FRAMES_PER_SECOND 20

    #define JONATHAN_VH_SPEED 30
    #define v_saut -115
    #define v_grav 25
    #define ennemi_speed 30

   #define WALK 8
   #define RIGHT 1
   #define LEFT 2
   #define UP 3
   #define DOWN 4
   #define STOP 0
  
   #define n_ennemis 7
   #define nbre_Etoiles 50
   #define nbre_herbes 6
   #define nbre_ramasser 9
   #define nbre_statues 7
