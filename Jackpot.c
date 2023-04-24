#include <allegro.h>
#include <stdio.h>
#include <time.h>
#include "header.h"

int roulette(int* symbole)
{
    int victoire = 0;
    srand(time(NULL));
    for(int i = 0 ; i < 3 ; i++)
    {
        symbole[i] = rand()%6;
        printf("%d ", symbole[i]);
    }
    printf("\n");
    if(symbole[0] == symbole[1] && symbole[0] == symbole[2])
    {
        allegro_message("Jackpot. 1 victoire");
        victoire += 1;
    }
    return victoire;
}

int main_jackpot(joueur* joueur)
{
    int* symbole = malloc(4*sizeof(int)); //machine en mode console
    int victoire = 0;
    //En mode console
    victoire = roulette(symbole);
    free(symbole);
    return victoire;
}
