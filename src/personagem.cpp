#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "personagem.hpp"
#include "object.hpp"
#include "position.hpp"

Personagem::Personagem(std::string name, ALLEGRO_BITMAP *image,int x, int y):
    _name(name), Object(image, x, y){};

Personagem::~Personagem(){}
