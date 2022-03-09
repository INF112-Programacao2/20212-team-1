/* Map.cpp */
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Map.hpp"

Map::Map(std::string arquivo, ALLEGRO_BITMAP *image,int x, int y){		
	//Object( image, x, y);
	_image = image;
	_position(x,y);
	std::ifstream file(arquivo);
	file.ignore(100, '\n');
	file.ignore(100, '\n');
	file >> this->_width;
	file >> this->_hight;
	file.ignore(1);
	file.ignore(100, '\n');
	
	this->_walkable = new unsigned char*[this->_hight];
	for (int i = 0; i < this->_hight; i++) {
		this->_walkable[i] = new unsigned char[this->_width];
	}
	
	unsigned char p3[this->_hight][this->_width][3];
	char line[100];
	
	for (int i = 0; i < this->_hight; i++) {
		for (int j = 0; j < this->_width; j++) {
			for (int k = 0; k < 3; k++) {
				file.getline(line, '\n');
				p3[i][j][k] = line[0];
			}
		}
	}
	
	for (int i = 0; i < this->_hight; i++) {
		for (int j = 0; j < this->_width; j++)
			this->_walkable[i][j] = (p3[i][j][0]=='0')?'0':'1';
	}
}

Map::~Map() {
	for (int i = 0; i < this->_hight; i++)
		delete [] _walkable[i];
	delete [] _walkable;
}

int Map::get_width(){
	return this->_width;
}

int Map::get_hight(){
	return this->_hight;
}

char Map::get_val_walkable(int x, int y){
	return _walkable[y][x];
}

void Map::draw_part(){
	al_draw_bitmap(_image,_position.get_x(), _position.get_y(), 0);
}
