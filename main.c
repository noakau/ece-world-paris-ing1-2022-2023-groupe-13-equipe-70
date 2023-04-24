#include <stdio.h>
#include <allegro.h>

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
    int nombre_de_joueurs;
    char* nom_du_joueur = malloc(50*sizeof(char));
    initialisation();
    printf("Nombre de joueurs (1 seul ou 2) : ");
    scanf("%d", &nombre_de_joueurs);
    for(int i = 0 ; i < nombre_de_joueurs ; i++)
    {
        printf("Nom du joueur %d : ", i+1);
        scanf("%s", nom_du_joueur);
        printf("%s", nom_du_joueur);
    }
    while(!key[KEY_ESC])
    {
        //
    }
    allegro_exit();
    return 0;
}END_OF_MAIN()
