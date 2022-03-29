/* Object.cpp */

#include "Object.hpp"

#include <string>

Object::Object(/*std::string image_directory*/ALLEGRO_BITMAP *image,int x, int y) :
	_position(x,y), _image(image) {};

Object::~Object(){}

void Object::set_image(ALLEGRO_BITMAP *image){
	this->_image = image;
}

ALLEGRO_BITMAP* Object::get_image() {
	return this->_image;
}

Position Object::get_position() {
	return this->_position;
}
