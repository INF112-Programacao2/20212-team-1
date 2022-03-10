/* Map.cpp */
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <fstream>

#include "Map.hpp"
#include "Object.hpp"
#include "Position.hpp"


Map::Map(std::string arquivo, ALLEGRO_BITMAP *image,int x, int y) : Object(image, x, y){
	std::ifstream file(arquivo);
	
	file.ignore(100, '\n');	// file type
	file.ignore(300, '\n');	// file commentary
	file >> this->_width;	// file dimension (hight)
	file >> this->_hight;	// file dimension (width)
	file.ignore(100, '\n');	// endline
	file.ignore(100, '\n');	// maximun color
	
	// creating matrix
	this->_walkable = new unsigned char*[this->_hight];
	for (int i = 0; i < this->_hight; i++) {
		this->_walkable[i] = new unsigned char[this->_width];
	}
	
	char line[100];
	
	for (int i = 0; i < this->_hight; i++) {
		for (int j = 0; j < this->_width; j++) {
			file.getline(line, '\n');
			_walkable[i][j] = (line[0] == '0') ? '0' : '1';
			file.ignore(100, '\n');	// ignoring second píxel
			file.ignore(100, '\n');	// ignoring third pixel
		}
	}
	
	file.close();
};

Map::~Map() {
	for (int i = 0; i < this->_hight; i++)
		delete [] _walkable[i];
	delete [] _walkable;
}

int Map::get_width() const{
	return this->_width;
}

int Map::get_hight() const{
	return this->_hight;
}

char Map::get_val_walkable(int x, int y){
	return _walkable[y][x];
}

void Map::draw_part(){
	al_draw_bitmap(_image,_position.get_x(), _position.get_y(), 0);
}
