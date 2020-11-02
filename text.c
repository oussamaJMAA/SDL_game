#include "text.h"

void initText(Text *T)
{
	T->position=NULL;
        T->score=NULL;
}

int loadFont(TTF_Font **police)
{
	if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return EXIT_FAILURE;
	}
	*police = TTF_OpenFont("Ubuntu-Title.ttf", 25);
	return EXIT_SUCCESS;
}


void displayText(TTF_Font *police,Text *T)
{
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Rect positionTextPos;
	SDL_Rect positionTextScore;

	positionTextPos.x=SCREEN_WIDTH-250;
	positionTextScore.x=SCREEN_WIDTH-250;

	positionTextPos.y=50;
	positionTextScore.y=100;

	char score[50];
	char position[50];


	sprintf(position,"Vies = %d",jonathan.vies);
	T->position = TTF_RenderText_Shaded(police,position,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->position, SDL_SRCCOLORKEY, SDL_MapRGB(T->position->format, 255, 255, 255));

	if (level==1)
	sprintf(score,"Score = %d",jonathan.score);
	else if (level==2)
	sprintf(score,"Score = %d",jonathan.score);

	T->score = TTF_RenderText_Shaded(police,score,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->score, SDL_SRCCOLORKEY, SDL_MapRGB(T->score->format, 255, 255, 255));


	SDL_BlitSurface(T->position,NULL,jeu.screen,&positionTextPos);
	SDL_BlitSurface(T->score,NULL,jeu.screen,&positionTextScore);

}

void freeFont(TTF_Font **police)
{
	TTF_CloseFont(*police); /* Doit être avant TTF_Quit() */
    TTF_Quit();	
}
