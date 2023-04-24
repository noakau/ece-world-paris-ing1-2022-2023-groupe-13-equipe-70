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
    int nombre_de_joueurs, jeu_en_cours, joueur_en_cours;
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
        for(joueur_en_cours = 0 ; joueur_en_cours < nombre_de_joueurs ; joueur_en_cours++)
        {
            allegro_message("C'est au tour de %s. Nombre de tickets : %d", joueurs[joueur_en_cours]->nom, joueurs[joueur_en_cours]->ticket);
            joueurs[joueur_en_cours]->ticket -= 1;
            jeu_en_cours = main_jackpot(joueurs[joueur_en_cours]);
            if(joueurs[joueur_en_cours]->ticket == 0)
            {
                allegro_message("Fin de la partie");
                allegro_exit();
                exit(0);
            }
        }
        joueur_en_cours = 0;
    }
    allegro_exit();
    return 0;
}END_OF_MAIN()
