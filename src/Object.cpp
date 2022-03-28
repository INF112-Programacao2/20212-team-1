/* Object.cpp */

#include "Object.hpp"

#include <string>

Object::Object(/*std::string image_directory*/ALLEGRO_BITMAP *image,int x, int y):
	_position(x,y), _image(image) {
		this->_font_directory = "file/font.ttf";
		this->_font_size = 11;
		/*
		TODO:
		if (alegro is not init)
			throw allegro must be initialized
		if (addon font is not init)
			throw allegro font must be initialized
		this->_font = al_load_font(this->_font_directory.c_str(), this->_font_size, 0);
		if (addon image is not)
			throw allegro image must be initialized
		this->_image = al_load_bitmap(image_directory.c_str());
		*/
	};

Object::~Object(){}

void Object::set_image(ALLEGRO_BITMAP *image){
	this->_image = image;
}

ALLEGRO_BITMAP* get_image() {
	return this->_image;
}

Position Object::get_position() {
	return this->_position;
}
