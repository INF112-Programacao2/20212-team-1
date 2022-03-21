/* Personagem.cpp */

#include "Personagem.hpp"

Personagem::Personagem(std::string name, ALLEGRO_BITMAP *image,int x, int y):
    _name(name), Object(image, x, y) {};

Personagem::~Personagem() {}

std::string Personagem::get_name() {
	return this->_name;
}
