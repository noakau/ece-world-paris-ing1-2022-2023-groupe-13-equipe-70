#include <stdio.h>
#include <allegro.h>

int main(void)
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
    allegro_exit();
    return 0;
}END_OF_MAIN()
