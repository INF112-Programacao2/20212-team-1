/* Npc.cpp */

#include "Npc.hpp"
#include "Personagem.hpp"
#include "Object.hpp"
#include <allegro5/allegro_color.h>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

Npc::Npc(std::string name, ALLEGRO_BITMAP *image, int x, int y, ALLEGRO_BITMAP *dialog_image, std::string file_directory[]):
	Personagem(name, image, x, y) {
	this->_dialog_image = dialog_image;
	for (int i = 0; i < 1; i++) {
		std::string t = file_directory[i];
		Interaction *interaction = new Interaction(t);
		this->_interactions.push_back(interaction);
	}
};
	
Npc::~Npc() {}

bool Npc::can_interact(Position player_position) {
	int player_x = player_position.get_x();
	int player_y = player_position.get_y();
	int npc_x = this->get_position().get_x();
	int npc_y = this->get_position().get_y();
	// TODO: if key 'I' is pressed
	if ((player_x == (npc_x + 1) && player_y == npc_y) ||
			(player_x == (npc_x - 1) && player_y == npc_y) ||
			(player_x == npc_x && player_y == (npc_y + 1)) ||
			(player_x == npc_x && player_y == (npc_y - 1)))
		// TODO: change parameter
		return true;
	return false;
}

void Npc::show_interaction(int n) {
	// TODO: Create screen
	ALLEGRO_DISPLAY *display = NULL;
	
	if (!al_init()) {
		std::cerr << "Failed to initialize allegro." << std::endl;
		// TODO: throw
		return;
	}
	
	// TODO: Remove creating display
	display = al_create_display(640, 480);
	
	if (!display) {
		std::cout << "Failed to initialize display." << std::endl;
		// TODO: throw
		return;
	}
	
	al_init_image_addon();
	
	ALLEGRO_BITMAP *character = al_load_bitmap("img/dialog-images/oak_.bmp");
	al_draw_bitmap(character, 0, 0, ALLEGRO_FLIP_HORIZONTAL);
	al_flip_display();
		
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	Interaction *interaction = this->_interactions[n];
	for (int i = 0; i < interaction->get_dialog_length(); i++) {
		std::string *d = interaction->get_dialog(i);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(character, 0, 0, ALLEGRO_FLIP_HORIZONTAL);
		al_flip_display();
		this->draw_text("NOME", d[interaction->SPEAK]);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(character, 0, 0, ALLEGRO_FLIP_HORIZONTAL);
		al_flip_display();
		this->draw_text(this->_name, d[interaction->ANSWER]);
	}
	
	al_destroy_bitmap(character);
	
	// TODO: Remove destroying display
	al_destroy_display(display);
}

void Npc::draw_text(std::string name, std::string text) {
	al_init_font_addon();
	al_init_ttf_addon();
	
	char t[text.size()+name.size()+3] = "";
	std::strcpy(t, (name + ": " + text).c_str());

	ALLEGRO_FONT *font = al_load_font("file/font.ttf", 18, 0);
	
	al_draw_multiline_text(font, al_map_rgb(0, 0, 0), 20, 330, 610, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, t);
	al_flip_display();
	al_rest(2.0);
	
}
