#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Position.hpp"
#include "Object.hpp"

ALLEGRO_FONT* Object::gblFont = al_load_font("img/fonte.bmp", DEF_FONT_SIZE, 0);

Object::Object(ALLEGRO_BITMAP *image,int x, int y):
    _position(x,y), _image(image){};

Object::~Object(){}

void Object::change_image(ALLEGRO_BITMAP *image){
    _image = image;
}
