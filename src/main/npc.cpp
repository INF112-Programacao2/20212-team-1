/* npc.cpp */

#include <allegro5/allegro.h>

#include "../Npc.hpp"
#include <iostream>

int main() {
	if (!al_init()) {
		std::cerr << "Error initialising Allegro.\n";
		return -1;
  }
  
  ALLEGRO_DISPLAY *display = al_create_display(640, 480);
  if (!display) {
  	std::cerr << "Error creating displays.\n";
		return -1;
  }
  
  al_install_keyboard();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	
	Position player_position(0,0);
	std::string file[] = {"file/Andre.txt"};
	
	Npc npc("Andre", nullptr, 0, 1, file);	
	ALLEGRO_EVENT event;
	al_wait_for_event(event_queue, &event);
	
	// TODO: if key 'I' is pressed
	if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_I:
				if (npc.can_interact(player_position)) {
					std::cout << "Show interaction\n";
					npc.show_interaction();
				}
				break;
		}
	}
	
	al_destroy_event_queue(event_queue);
	
	return 0;
}
