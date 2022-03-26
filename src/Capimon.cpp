/* Capimon.cpp */

#include "Capimon.hpp"

int Capimon::AMOUNT_SKILLS = 4;

Capimon::Capimon(string name, ALLEGRO_BITMAP *image, int life, Skill skills[AMOUNT_SKILLS]){
	this->_name = name;
	this->_image = image;
	this->_life = life;
	
	for (int i = 0; i < this->AMOUNT_SKILLS; i++)
		this->_skills[i] = skills[i];
}

Capimon::~Capimon(){
    //al_destroy_bitmap(this->_image);
}

std::string Capimon::get_name() {
	return this->_name;
}

int Capimon::get_lif() {
	return this->_life;
}

void Capimon::show_capimonPlayer(){
	al_convert_mask_to_alpha(this->_image, al_map_rgb(255,0,255));
	al_draw_bitmap(this->_image, 200, 295, 0); 	//the position is changed if it's a player or and NPC
}

void Capimon::show_capimonNpc(){
	al_convert_mask_to_alpha(this->_image, al_map_rgb(255,0,255));
	al_draw_bitmap(this->_image, 200, 295, 0); 	//the position is changed if it's a player or and NPC 
	//alterar posicao da imagem
}