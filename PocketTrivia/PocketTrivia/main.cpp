#include <allegro.h>
#include <cstdint>
#include <stdint.h>

using namespace std;

int main() {
	allegro_init();
	set_gfx_mode(GFX_SAFE, 640, 480, 0, 0);
	install_keyboard();

	textout_ex(screen, font, "fuck athabasca", 1, 1, 10, -1);
	textout_ex(screen, font, "fuck athabasca escape to quit", 1, 1, 10, -1);
	while (!key[KEY_ESC]);
	allegro_exit();
	return 0;
}

END_OF_MAIN()