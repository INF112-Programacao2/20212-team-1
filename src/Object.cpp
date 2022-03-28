/* Object.cpp */

#include "Object.hpp"

ALLEGRO_FONT* Object::gblFont = al_load_font("file/fonte.ttf", DEF_FONT_SIZE, 0);

Object::Object(ALLEGRO_BITMAP *image,int x, int y):
	_position(x,y), _image(image) {
		this->_font_directory = "file/font.ttf";
		this->_font_size = 11;
		/*
		TODO:
		if (alegro is init and addon font is init)
			this->_font = al_load_font(this->_font_directory.c_str(), this->_font_size, 0);
		*/
	};

Object::~Object(){}

void Object::change_image(ALLEGRO_BITMAP *image){
	this->_image = image;
}

Position Object::get_position() {
	return this->_position;
}
