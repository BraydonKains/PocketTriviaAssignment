#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "game.h"

int main()
{
	Game main_game;
	main_game.init();

	main_game.run();

	return 0;
}