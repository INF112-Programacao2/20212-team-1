/* Skill.cpp */

#include "Skill.hpp"

#include <cstdlib>
#include <time.h>
// #include <allegro5/allegro.h>
// #include <allegro5/allegro_ttf.h>
// #include <allegro5/allegro_font.h>

Skill::Skill(int index, std::string name, int min_damage, int max_damage) {
	this->_index = index;
	this->_name = name;
	this->_damage_interval[this->MIN_DAMAGE] = min_damage;
	this->_damage_interval[this->MAX_DAMAGE] = max_damage;
}

Skill::~Skill() {}

int Skill::get_index() {
	return this->_index;
}

std::string Skill::get_name() {
	return this->_name;
}

int Skill::select_damage() {
	srand(time(NULL));
	return (this->_damage_interval[this->MIN_DAMAGE] + (rand() % this->_damage_interval[this->MAX_DAMAGE] + 1));	// select a rand value between min and max damage
}

