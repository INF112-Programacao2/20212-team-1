/* Map.cpp */

#include "Map.hpp"

Map::Map(string arquivo) {		
	std::ifstream file(arquivo);
	
	file.ignore(100, '\n');	// file type
	file.ignore(300, '\n');	// file commentary
	file >> this->_dimension[1];	// file dimension (hight)
	file >> this->_dimension[0];	// file dimension (width)
	file.ignore(100, '\n');	// endline
	file.ignore(100, '\n');	// maximun color
	
	// creating matrix
	this->_walkable = new unsigned char*[this->_dimension[0]];
	for (int i = 0; i < this->_dimension[0]; i++) {
		this->_walkable[i] = new unsigned char[this->_dimension[1]]
	}
	
	char line[100];
	
	for (int i = 0; i < this->_dimension[0]; i++) {
		for (int j = 0; j < this->_dimension[1]; j++) {
			file.getline(line, '\n');
			p[i][j] = (line[0] == '0') ? '0' : '1';
			file.ignore(100, '\n');	// ignoring second píxel
			file.ignore(100, '\n');	// ignoring third pixel
		}
	}
	
	arquivo.close();
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
