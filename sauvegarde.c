#include "sauvegarde.h"

void sauvegarde (char fich[20])
{
	int i;
	FILE *f;
	
	f=fopen(fich,"wb");
	fwrite(&jeu.nbre_ennemis,sizeof(int),1,f);
	fwrite(&jeu.nbre_etoiles,sizeof(int),1,f);
	for (i=0;i<jeu.nbre_etoiles;i++)
	{
		fwrite(&etoile[i],sizeof(Etoile),1,f);
	}
	
	fwrite(&jonathan,sizeof(Hero),1,f);
	
	for (i=0;i<jeu.nbre_ennemis;i++)
	{
		fwrite(&ennemi[i],sizeof(Hero),1,f);
	}
	
	fclose(f);
	
}

void lire (char fich[20])
{
	int i;
	FILE *f;
	
	f=fopen(fich,"rb");
	if (f==NULL)
	{
		printf("erreur, fichier ne peut pas etre ouvert\n");
		exit(0);
	}
	
	else
	{
		fread(&jeu.nbre_ennemis,sizeof(int),1,f);
		fread(&jeu.nbre_etoiles,sizeof(int),1,f);
		for (i=0;i<jeu.nbre_etoiles;i++)
		{
			fread(&etoile[i],sizeof(Etoile),1,f);
		}
		
		fread(&jonathan,sizeof(Hero),1,f);
	
		for (i=0;i<jeu.nbre_ennemis;i++)
		{
			fread(&ennemi[i],sizeof(Hero),1,f);
		}
	}
	
	fclose(f);
}
