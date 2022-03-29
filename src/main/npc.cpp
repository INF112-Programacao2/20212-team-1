/* npc.cpp */

#include <allegro5/allegro.h>

#include "../Npc.hpp"
#include <iostream>

int main() {
  al_install_keyboard();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	Player player("Capivaristo", nullptr, 0, 0, 0, 0);
	
	std::string file[] = {"file/Andre.txt"};
	Npc npc("André", nullptr, 1, 1, file);
		
	ALLEGRO_EVENT event;
	al_wait_for_event(event_queue, &event);
	
	if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_I:
				if (npc.can_interact(player_position)) {
					npc.show_interaction();
				}
				break;
		}
	}
	
	al_destroy_event_queue(event_queue);
	
	return 0;
}
