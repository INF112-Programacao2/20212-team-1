/* Skill.cpp */

#include "Skill.hpp"

#include <cstdlib>
#include <time.h>

Skill::Skill(std::string name, int min_damage, int max_damage) {
	this->_name = name;
	this->_damage_interval[this->MIN_DAMAGE] = min_damage;
	this->_damage_interval[this->MAX_DAMAGE] = max_damage;
}

Skill::~Skill() {}

std::string Skill::get_name() {
	return this->_name;
}

int Skill::select_damage() {
	srand(time(NULL));
	return (this->_damage_interval[this->MIN_DAMAGE] + (rand() % this->_damage_interval[this->MAX_DAMAGE]));	// select a rand value between min and max damage
}

void Skill::draw_skill_in_battle(int i) {
	ALLEGRO_FONT* font = al_load_font("file/font.ttf", 11, 0); // TODO: Unificate fonts
	
	al_draw_text(font, al_map_rgb(0,0,0), (i == 0 || i == 1) ? 40 : 200, (i == 0 || i == 2) ? 420 : 450, ALLEGRO_ALIGN_LEFT, this->_name);	// TODO: Confirme ternary operator use 
	
	al_destroy_font(font);
}