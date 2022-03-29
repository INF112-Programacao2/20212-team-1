/* npc.cpp */

#include "../Npc.hpp"
#include "../Player.hpp"
#include <iostream>

//#define RESOLVE_PATH(str) "../file/" str

int main() {
	Player capivara("Capivaristo", nullptr, 1, 1, 0, 0);
	Npc npc("André", nullptr, 1, 1, 1, "../file/Andre.txt", capivara.get_name());
	
	al_init();
	
	ALLEGRO_DISPLAY *display = nullptr;
	display = al_create_display(640, 480);
	
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	
	if (npc.can_interact(capivara.get_position())) {
		npc.draw_next_interaction();
		al_flip_display();
		al_rest(2.0);
	}

	al_destroy_display(display);
	
	return 0;
}
