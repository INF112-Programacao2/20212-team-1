#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Personagem.hpp"
#include "Object.hpp"
#include "Position.hpp"

Personagem::Personagem(std::string name, ALLEGRO_BITMAP *image,int x, int y):
    _name(name), Object(image, x, y){};

Personagem::~Personagem(){}
