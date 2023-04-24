#include <stdio.h>
#include <allegro.h>
#include "header.h"

void initialisation()
{
    allegro_init(); //initialisation
    install_keyboard(); //clavier
    install_mouse(); //souris
    set_color_depth(desktop_color_depth());
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0)!=0) //800x600 px
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

int main()
{
    int nombre_de_joueurs, victoire_roulette, joueur_en_cours = 0;
    char* nom_du_joueur = malloc(50*sizeof(char));
    initialisation();
    printf("Nombre de joueurs (2 joueurs minimum) : ");
    scanf("%d", &nombre_de_joueurs);
    joueur* joueurs[nombre_de_joueurs];
    for(int i = 0 ; i < nombre_de_joueurs ; i++)
    {
        joueur *nouveau_joueur = malloc(sizeof(joueur));
        printf("Nom du joueur %d : ", i + 1);
        scanf("%s", nom_du_joueur);
        nouveau_joueur->nom = nom_du_joueur;
        nouveau_joueur->ticket = 5;
        joueurs[i] = nouveau_joueur;
    }
    while(!key[KEY_ESC])
    {
        allegro_message("C'est au tour de %s. Nombre de tickets : %d", joueurs[joueur_en_cours]->nom, joueurs[joueur_en_cours]->ticket);
        joueurs[joueur_en_cours]->ticket -= 1;
        victoire_roulette = main_jackpot(joueurs[joueur_en_cours]); //Jeu du jackpot
        printf("Victoire roulette : %d", victoire_roulette);
        if(joueurs[joueur_en_cours]->ticket == 0)
        {
            allegro_message("Fin de la partie");
            allegro_exit();
            exit(0);
        }
        if(joueur_en_cours + 1 == nombre_de_joueurs)
        {
            joueur_en_cours = 0;
        }
        else
        {
            joueur_en_cours++;
        }
    }
    allegro_exit();
    return 0;
}END_OF_MAIN()
