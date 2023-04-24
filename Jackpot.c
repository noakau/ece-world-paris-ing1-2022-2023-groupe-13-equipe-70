#include <allegro.h>
#include <stdio.h>
#include <time.h>
#include "header.h"

void roulette(int* symbole)
{
    srand(time(NULL));
    for(int i = 0 ; i < 3 ; i++)
    {
        symbole[i] = rand()%6;
        printf("%d ", symbole[i]);
    }
    printf("\n");
}

int main_jackpot(joueur* joueur)
{
    int* symbole = malloc(4*sizeof(int)); //machine en mode console
    //En mode console
    roulette(symbole);
    free(symbole);
    return 1;
}
