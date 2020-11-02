#include "defs.h"

  typedef struct Text 
  {
	SDL_Surface *position;
	SDL_Surface *score;
  } Text ;

  typedef struct Input
  {

    int left, right, up, down, jump, attack, enter, erase, pause,hidden,escape;

  } Input;

  typedef struct Gestion
  {

    SDL_Surface *screen;
    int nbre_etoiles ;
    int nbre_ennemis;
    int ramasser;

  } Gestion;

  typedef struct Map
  {

      SDL_Surface *background;
      int startX, startY;

  } Map;

 
   typedef struct Hero
   {
       SDL_Surface *sprite;
       SDL_Surface *game_over;
       SDL_Surface *gain;
       int x, y,w,h,score,score2;/*ses coordonnées*/
       int frameNumber , frameTimer;
       int etat, direction;
       int posX,posY;
       int posTimer;
       int jump;
       int vies;
       int attack;
       int hidden;
	
   } Hero;

  typedef struct Etoile
  {
	SDL_Surface *image;
        int x,y,w,h;
  }Etoile;

  typedef struct Herbe
  {
	int etat;
	SDL_Surface *image;
        int x,y;
  }Herbe;

  typedef struct statue
  {
	int etat;
	SDL_Surface *image;
	int x,y;
  }statue;
  SDL_Surface *game_over;

  int level;
