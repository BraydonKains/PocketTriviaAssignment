#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "game.h"

int main()
{
	//Allegro setup
	al_init();
	al_init_font_addon();
	ALLEGRO_DISPLAY* display = al_create_display(640, 480);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_init_primitives_addon();
	al_init_image_addon();

	Game main_game;
	main_game.init();

	main_game.run();

	return 0;
}