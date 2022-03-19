/* npc.cpp */

#include <allegro5/allegro.h>

#include "../Npc.hpp"
#include <iostream>

int main() {
	if (!al_init()) {
		std::cout << "Error initialising Allegro.\n";
		return -1;
  }
  
  ALLEGRO_DISPLAY *display = al_create_display(640, 480);
  if (!display) {
  	std::cout << "Error creating displays.\n";
		return -1;
  }
  
  al_install_keyboard();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	std::string file[] = {"file/Andre.txt"}
	Npc npc("Andre", nullptr, 0, 0, {"file/Andre.txt"});	
	ALLEGRO_EVENT event;
	al_wait_for_event(event_queue, &event);
	
	// TODO: if key 'I' is pressed
	if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_I:	// The setted key is "N" (from word "next")
				bool interaction = npc.interact();
				if (!interaction) {
					std::cout << "Error in interaction Allegro.\n";
					return -1;
				}
				break;
			default:
				break;
		}
		std::cout << "Everything is ok!\n";
	}
	
	al_destroy_event_queue(event_queue);
	
	return 0;
}
