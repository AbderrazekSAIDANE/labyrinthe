#include<stdio.h>
#include<stdlib.h>
#include"direction.h"

void direction(int *a,int *b,int d,int i,int j)
{
    switch (d)
    {
        case 0 :
            *a=i-1;
            *b=j;
            break;
        case 1 :
            *a=i;
            *b=j+1;
            break;
        case 2 :
            *b=j;
            *a=i+1;
            break;
        case 3 :
            *a=i;
            *b=j-1;
            break;
        default :
            printf("erreur sur la direction");
    }
}
// l'initilisation des pointeurs est très importante on ne peut pas se contenté d'affecté que la valeur pointée par le pointeur qui change 
