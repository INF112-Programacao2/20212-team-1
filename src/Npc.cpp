/* Npc.cpp */

#include "Npc.hpp"
#include <iostream>
#include <cstring>

Npc::Npc(std::string name, /*std::string image_directory*/ALLEGRO_BITMAP *image, int x, int y, std::string file_directory[]) :
	Character(name, image, x, y) {
	for (int i = 0; i < 1; i++) {
		std::string t = file_directory[i];
		Interaction *interaction = new Interaction(t);
		this->_interactions.push(interaction);
	}
};
	
Npc::~Npc() {}

bool Npc::can_interact(Position player_position) {
	// TODO: Change variables of position
	int player_x = player_position.get_x();
	int player_y = player_position.get_y();
	int npc_x = this->get_position().get_x();
	int npc_y = this->get_position().get_y();
	if ((player_x == (npc_x + 1) && player_y == npc_y) ||
			(player_x == (npc_x - 1) && player_y == npc_y) ||
			(player_x == npc_x && player_y == (npc_y + 1)) ||
			(player_x == npc_x && player_y == (npc_y - 1))) {
		return true;
	}
	return false;
}

// Show the next interaction in the queue
void Npc::show_interaction() {
	// TODO: Change loading image place
	al_init_image_addon();
	ALLEGRO_BITMAP *dialog_box = al_load_bitmap("img/dialog/dialog_box.bmp");
	
	Interaction *interaction = this->_interactions.front();
	this->_interactions.pop();
		// TODO: Change drawing
	for (int i = 0; i < interaction->get_quantity_of_dialogs(); i++) {
		std::string *d = interaction->get_dialog(i);
		al_draw_bitmap(dialog_box, 0, 384, ALLEGRO_FLIP_HORIZONTAL);
		al_flip_display();
		this->draw_text("NOME", d[interaction->SPEAK]);
		al_draw_bitmap(dialog_box, 0, 384, ALLEGRO_FLIP_HORIZONTAL);
		al_flip_display();
		this->draw_text(this->_name, d[interaction->ANSWER]);
	}
	
	// TODO: Change destroying image place
	al_destroy_bitmap(dialog_box);
}

void Npc::draw_text(std::string name, std::string text) {
	// TODO:: Change font initializers place
	// TODO:: Throw initializer errors
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT *font = al_load_font("file/font.ttf", 18, 0);
	
	// TODO:: Change keyboard initializers place
	// TODO:: Throw initializer errors
	al_install_keyboard();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	// TODO: Change type of t
	const char *name_c = name.c_str();
	const char *text_c = text.c_str();
	
	// TODO: Include possibilite of a text bigger than the box
	al_draw_multiline_text(font, al_map_rgb(0, 0, 0), 20, 394, 604, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, name_c);
	al_draw_multiline_text(font, al_map_rgb(0, 0, 0), 20, 394 + al_get_font_line_height(font), 604, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, text_c);
	al_flip_display();
	
	ALLEGRO_EVENT event;
	al_wait_for_event(event_queue, &event);
	
	if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_N:	// The setted key is "N" (from word "next")
				break;
			default:
				this->draw_text(name, text);
		}
	}
	
	al_destroy_event_queue(event_queue);
}

Position Npc::get_CAPIMON_DRAW_POSITION() const {
    return this->CAPIMON_DRAW_POSITION;
}

Position Npc::get_CAPIMON_STATUS_POSITION() const {
    return this->CAPIMON_STATUS_POSITION;
}
