/* Character.cpp */

#include "Character.hpp"

Character::Character(std::string name, ALLEGRO_BITMAP *image,int x, int y):
    _name(name), Object(image, x, y) {};

Character::~Character() {}

std::string Character::get_name() {
	return this->_name;
}

void Character::add_capimon(Capimon *capimon) {
	this->_deck.push_back(capimon);
}

vector<Capimon> Character::getCapimons(){
	return _deck;
}
