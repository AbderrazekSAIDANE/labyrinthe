#include<stdio.h>
#include<stdlib.h>
#include"affichage.h"
#include"direction.h"//ce fichier headers n'est pas obligatoire
#include"lireLabyrinthe.h"


int lireLabyrinthe(char nom[20], int tab[TAILLE_X][TAILLE_Y],int depart[2],int arrivee[2])
{
    FILE* fichier = NULL;
    fichier = fopen(nom,"r");
    if(fichier==NULL)
    {
        printf("ERREUUUUR !!!!");// si le fichier n'est pas ouvert un message s'affiche
        return 0;
    }
    else
    {
        fscanf(fichier,"%d %d",&depart[0],&depart[1]);// on aura besoin de ces deux valeurs pour les autres fonction
        fscanf(fichier,"%d %d",&arrivee[0],&arrivee[1]);
        if(fichier != NULL)
        {
            for(int i=0;i<TAILLE_Y;i++)
            {
                for(int j=0;j<TAILLE_X;j++)
                {
                    fscanf(fichier,"%d",&tab[j][i]);// lecture du tableau "Labyrinthe"
                }
            }
        }
    }
    return 1;
}
