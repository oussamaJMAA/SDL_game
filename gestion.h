#include "structs.h"
extern Hero jonathan ;
extern Map map;
extern Gestion jeu;
extern Input input;
extern Hero ennemi[];

extern void initializeJonathan(void);
extern void initializeEnnemis(void);
extern void init_etoiles(void);
extern void initialiser_herbes (void);
extern void drawImage(SDL_Surface *image, int x, int y);
extern int  collision_back (Hero *a);
extern void init_herbes2 (void);

