/* Character.cpp */

#include "Character.hpp"

#include <cstdlib>

Character::Character(std::string name, ALLEGRO_BITMAP *image,int x, int y):
    _name(name), Object(image, x, y) {};

Character::~Character() {}

std::string Character::get_name() {
	return this->_name;
}

void Character::add_capimon(Capimon *capimon) {
	this->_deck.push_back(capimon);
}

vector<Capimon> Character::get_deck() {
	return this->_deck;
}

void Character::select_capimon() {
	srand(time(NULL));
	this->_selected_capimon = this->_deck.at(rand() % this->AMOUNT_DECK);
}

Capimon* Character::get_selected_capimon() {
	return this->_selected_capimon;
}
