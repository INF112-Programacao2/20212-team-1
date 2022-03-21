/* Character.cpp */

#include "Character.hpp"

Character::Character(std::string name, ALLEGRO_BITMAP *image,int x, int y):
    _name(name), Object(image, x, y) {};

Character::~Character() {}

std::string Character::get_name() {
	return this->_name;
}
