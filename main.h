  #include "structs.h"


  extern void init(char *title);
  extern void cleanup(void);
  extern void getInput(void);
  extern void draw(void);
  extern void delay(unsigned int);
  extern void loadGame(void);
  extern int  menu(void);
  extern void initializeJonathan(void);
  extern void initializeJonathan_vh(void);
  extern void updateJonathan_vh(void);
  extern void updateEnnemis(void);
  extern void initializeEnnemis(void);
  extern void init_etoiles (void);
  extern void update_etoiles (void);
  extern void initText(Text *T);
  extern int  loadFont(TTF_Font **police);
  extern void freeFont(TTF_Font **police);
  extern void displayText(TTF_Font *police,Text *T);
  extern int  gestion(void);
  extern void initialiser_herbes (void);
  extern void lire (char fich[20]);
  extern void sauvegarde (char fich[20]);
  extern void initializeEnnemis2(void);
  extern void init_herbes2 (void);
  extern void initialiser_statues(void);
  extern void update_herbes2(void);

  Text txt;
  Input input;
  Gestion jeu;
  Map map ;
  Hero jonathan;
  Hero jonathan_vh;
  Hero ennemi[n_ennemis];
  Map ea ;
  Etoile etoile[nbre_Etoiles];
  Herbe herbe[nbre_herbes];
  Etoile ram[nbre_ramasser];
  statue sta[nbre_statues];
