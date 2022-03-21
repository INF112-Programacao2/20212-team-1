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
	this->_name = name;
}

int Skill::select_damage() {
	srand(time(NULL));
	return (this->_damage_interval[this->MIN_DAMAGE] + (rand() % this->_damage_interval[this->MAX_DAMAGE]));
}
