#include "Personagem.hpp"

Personagem::Personagem(std::string name, ALLEGRO_BITMAP *image,int x, int y):
    _name(name), Object(image, x, y){};

Personagem::~Personagem(){}
