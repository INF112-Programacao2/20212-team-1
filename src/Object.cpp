#include "Position.hpp"
#include "Object.hpp"

Object::Object(ALLEGRO_BITMAP *image,int x, int y):
    _position(x,y), _image(image){};

Object::~Object(){}

void Object::change_image(ALLEGRO_BITMAP *image){
    _image = image;
}
