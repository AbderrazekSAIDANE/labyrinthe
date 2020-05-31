
//gcc -c Labyrinthe.c

#include<stdio.h>
#include<stdlib.h>
#include"affichage.h"
#include"lireLabyrinthe.h"
#include"direction.h"
#include"parcours.h"
#include"parcours_inv.h"


int main(){
    int tab[TAILLE_X][TAILLE_Y],tempo=0;
    char nom[20];
    int depart[2],arrivee[2];
    int depX,depY,arX,arY,retour;
    int x,y,d,i,r=1;
    int bloque=1;
    printf("donner le nom du fichier\n");
    scanf("%s", nom);
    lireLabyrinthe(nom,tab,depart,arrivee);
    depX=depart[0];
    depY=depart[1];
    arX=arrivee[0];
    arY=arrivee[1];
    parcours(tab,depX,depY,arX,arY,&bloque,&r);
    //printf("la distance est %d\n",r);
    //printf("bloque = %d\n",bloque);
    retour=parcours_inv(tab,depX,depY,arX,arY,&r);
    if((bloque == 1) || (retour == 0)) //l'affichage n'est pas excecuté si un obstacle bloque le chemin ou le retour est défectueux
    {
         
          printf("je ne trouve pas un chemin entre le point de départ et de l'arrivée ou erreur au moment du retour\n");
    }
    else
           {
               initAffichage();
               afficheLabyrinthe(tab,depart,arrivee,tempo);
           }
    return 0;
}




