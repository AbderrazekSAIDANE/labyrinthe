
// gcc -c parcours.c

#include<stdio.h>
#include<stdlib.h>
#include"direction.h"
#include"affichage.h"



void parcours(int tab[TAILLE_X][TAILLE_Y],int depX,int depY,int arX,int arY,int *bloque,int *r)
{
    int depart[2],arrivee[2];
    int d,a=0,b=0;
    int tempo=0;
    tab[depX][depY]=*r;// la case de départ égale à 1 car c'est de la qu'on commence à parcourir le tableau
    
    /* il est évident que le programme est bloqué avant la premère itération donc */
    
    while(tab[arX][arY] == 0) // si tab[arrivee_X][arrivee_Y] != 0
                                        // alors nous avons atteint la case d'arrivée
    {
        for(int i=0;i<TAILLE_X;i++)
        {
            for(int j=0;j<TAILLE_Y;j++)
            {
                    if(tab[i][j]==*r)// cette boucle nous permet d'atteindre les case suivant non vivitée
                    {
                        for(d=0;d<4;d++)//d représente le vecteur de directeur
                                        //ou plus simplement quelle case voisin on regarde
                        {
                            direction(&a,&b,d,i,j);//a et b représente les deux coordonnées de la case voisine
                            if(tab[a][b]==0)
                            {
                                tab[a][b]=*r+1;
                                 *bloque = 0;
                            }
                            //tant que l'algorithme n'a pas vérifié les cases voisines il se concidère bloqué
                        }
                   }        //*bloque = 1;
            }
        }
            *r=*r+1;
 //on incrémente le r après d'on est parcouru tout le tableau car il se peut que un r minimum soit à la fin du tableau
    }
    //return bloque;
    if(tab[arX][arY] != *r)
        *bloque = 1;
}
