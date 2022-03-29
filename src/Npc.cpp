/* Npc.cpp */

#include "Npc.hpp"

//#include <allegro5/allegro.h>

#include <iostream>
#include <cstring>
#include <string>
#include <exception>

Npc::Npc(std::string name, ALLEGRO_BITMAP *image, int x, int y, unsigned int quantity_of_interactions, std::string interaction_base_directory, std::string player_name) :
	Character(name, image, x, y) {
	std::string directory_name = interaction_base_directory.substr(0, interaction_base_directory.find_last_of('.'));
	for (int i = 0; i < quantity_of_interactions; i++) {
		Interaction *interaction = new Interaction(directory_name + std::to_string(i) + ".txt", player_name, this->_name);
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
	
	if ((player_x == npc_x && player_y == npc_y) ||
			(player_x == (npc_x + 1) && player_y == npc_y) ||
			(player_x == (npc_x - 1) && player_y == npc_y) ||
			(player_x == npc_x && player_y == (npc_y + 1)) ||
			(player_x == npc_x && player_y == (npc_y - 1))) {
		return true;
	}
	return false;
}

void Npc::draw_next_interaction(int reference_x, int reference_y) {
	if (this->_interactions.size() == 0) {
		std::cerr << "There is no interaction to draw." << std::endl;
		throw std::exception();
	}
	
	Interaction *interaction = this->_interactions.back();
	this->_interactions.pop();
	
	interaction->draw(reference_x, reference_y);
	delete interaction;
	al_flip_display();
	
}

Position Npc::get_CAPIMON_DRAW_POSITION() const {
    return this->CAPIMON_DRAW_POSITION;
}

Position Npc::get_CAPIMON_STATUS_POSITION() const {
    return this->CAPIMON_STATUS_POSITION;
}

void Npc::draw_npc(){
	al_convert_mask_to_alpha(this->_image, al_map_rgb(255,0,255));
	al_draw_bitmap(this->_image, this->_position.get_x() * this->_tamPixels, this->_position.get_y() * this->_tamPixels, 0);
}
