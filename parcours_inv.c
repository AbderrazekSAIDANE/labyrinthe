
// gcc -c parcours_inv.c

#include<stdio.h>
#include<stdlib.h>
#include"direction.h"
#include"affichage.h"



int parcours_inv(int tab[TAILLE_X][TAILLE_Y],int depX,int depY,int arX,int arY,int *r)
{
    int depart[2],arrivee[2];
    int d,a=0,b=0,z,p=*r;
    int tempo=0;
    tab[depX][depY]=(-2);// la case d'arrivée prend la valeur -2 au lieu de r "dernière valeur de r"
    int i=arX,j=arY;

        for(z=p;z>0;z--)
        {
                for(d=0;d<4;d++)//d représente le vecteur de                direction
                                        //ou plus simplement quelle case voisin on regarde
                {
                        
                    direction(&a,&b,d,i,j);//a et b représente les deux coordonnées de la case voisine
                        if(tab[a][b]==(z-1))
                        {
                            tab[a][b]=-2;// toute le case de retour doivent être égale à -2
                            i=a;
                            j=b;
                        }
                }
        }
    // Si la phase de remontée c'est bien déroulée alors les coordonées que nous allons avoir par le biais de la fonction direction seront égales à ceux de la case de départ
    if((a == depX) && (b == depY))
    {
        for (int i=0;i<TAILLE_X;i++)
        {
            for(int j=0;j<TAILLE_Y;j++)
            {
                if (tab[i][j] != -2 & tab[i][j] != -1)
                {
                    tab[i][j]=0;
                }
            }
        }
        return 1;
    }
    else
        return 0;
}

