/* Npc.cpp */

#include "Npc.hpp"
#include <iostream>
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
	// TODO: Change loading image place
	al_init_image_addon();
	ALLEGRO_BITMAP *dialog_box("img/dialog-images/dialog_box.bmp");
	
	Interaction *interaction = this->_interactions[n];
	for (int i = 0; i < interaction->get_dialog_length(); i++) {
		std::string *d = interaction->get_dialog(i);
		al_draw_bitmap(dialog_box, 0, 384, ALLEGRO_FLIP_HORIZONTAL);
		al_flip_display();
		this->draw_text("NOME", d[interaction->SPEAK]);
		al_draw_bitmap(dialog_box, 0, 384, ALLEGRO_FLIP_HORIZONTAL);
		al_flip_display();
		this->draw_text(this->_name, d[interaction->ANSWER]);
	}
}

void Npc::draw_text(std::string name, std::string text) {
	al_init_font_addon();
	al_init_ttf_addon();
	
	// TODO: Change type of t
	char t[text.size()+name.size()+3] = "";
	std::strcpy(t, (name + ": " + text).c_str());

	ALLEGRO_FONT *font = al_load_font("file/font.ttf", 18, 0);
	
	al_draw_multiline_text(font, al_map_rgb(0, 0, 0), 20, 394, 100, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, t);
	al_flip_display();
	// TODO: Change to a press button verification
	al_rest(2.0);
}
