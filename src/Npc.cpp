/* Npc.cpp */

#include "Npc.hpp"

//#include <allegro5/allegro.h>

#include <iostream>
#include <cstring>
#include <string>
#include <exception>

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

void Npc::draw_dialog_box() {
	if (!al_init_image_addon())
		throw std::exception();
		
	ALLEGRO_BITMAP *dialog_box;
	dialog_box = al_load_bitmap("img/dialog/dialog_box.bmp");
	if (!dialog_box)
		throw std::exception();
		
	al_draw_bitmap(dialog_box, 0, 384, ALLEGRO_FLIP_HORIZONTAL);
	
	al_destroy_bitmap(dialog_box);
}

// Show the next interaction in the queue
void Npc::show_interaction() {		
	Interaction *interaction = this->_interactions.front();
	this->_interactions.pop();
	
	int size = interaction->get_quantity_of_dialogs();
	
	const int SPEAK = interaction->SPEAK;
	const int ANSWER = interaction->ANSWER;
	
	for (int i = 0; i < size; i++) {
		std::string name;
		for (int j = 0; j < interaction->SIZE; j++) {
			if (j == 0)
				name = "Capivaristo";
			else if (j == 1)
				name = this->_name;
			
			draw_dialog_box();
			draw_text(name, interaction->get_dialog(i)[j]);
			al_flip_display();
			al_rest(2.0);
		}
	}
}

void Npc::draw_text(std::string name, std::string text) {
	// TODO:: Change font initializers place
	// TODO:: Throw initializer errors
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT *font;
	font = al_load_font("file/font.ttf", 18, 0);


	// TODO: Change type of t
	const char *name_c = name.c_str();
	const char *text_c = text.c_str();
	
	// TODO: Include possibilite of a text bigger than the box
	al_draw_multiline_text(font, al_map_rgb(0, 0, 0), 20, 394, 604, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, name_c);
	al_draw_multiline_text(font, al_map_rgb(0, 0, 0), 20, 394 + al_get_font_line_height(font), 604, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, text_c);
	al_flip_display();
	
	al_destroy_font(font);
}

Position Npc::get_CAPIMON_DRAW_POSITION() const {
    return this->CAPIMON_DRAW_POSITION;
}

Position Npc::get_CAPIMON_STATUS_POSITION() const {
    return this->CAPIMON_STATUS_POSITION;
}

void Npc::draw_npc(){
	al_draw_bitmap(this->_image, this->_position.get_x(), this->_position.get_y(), 0);
}
