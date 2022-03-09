/* Map.cpp */

#include "Map.hpp"

Map::Map(string arquivo) {		
	int width, hight;
		
	std::ifstream file(arquivo);
	file.ignore(100, '\n');
	file.ignore(100, '\n');
	file >> width;
	file >> hight;
	file.ignore(1);
	file.ignore(100, '\n');
	
	this->_walkable = new unsigned char*[hight];
	for (int i = 0; i < hight; i++) {
		this->_walkable[i] = new unsigned char[widht]
	}
	
	unsigned char p3[hight][width][3];
	char line[100];
	
	for (int i = 0; i < hight; i++) {
		for (int j = 0; j < width; j++) {
			for (int k = 0; k < 3; k++) {
				file.getline(line, '\n');
				p[i][j][k] = line[0];
			}
		}
	}
	
	for (int i = 0; i < hight; i++) {
		for (int j = 0; j < width; j++)
			this->_walkable[i][j] = (p3[i][j][0]=='0')?'0':'1';
	}
}

Map::~Map() {
	for (unsigned char* i : this->_walkable)
		delete [] i;
	delete [] walkable;
}

int Map::get_width() const {
	return this->_dimension[0];
}

int Map::get_hight() const {
	return this->_dimension[1];
}
