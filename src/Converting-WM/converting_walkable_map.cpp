#include <fstream>
#include <iostream>

int main() {
	std::ifstream file(arquivo);
	int _dimension[2];
	
	file.ignore(100, '\n');	// file type
	file.ignore(300, '\n');	// file commentary
	file >> _dimension[1];	// file dimension (hight)
	file >> _dimension[0];	// file dimension (width)
	file.ignore(100, '\n');	// endline
	file.ignore(100, '\n');	// maximun color
	
	unsigned char** _walkable;
	
	// creating matrix
	_walkable = new unsigned char*[_dimension[0]];
	for (int i = 0; i < _dimension[0]; i++) {
		_walkable[i] = new unsigned char[_dimension[1]]
	}
	
	char line[100];
	
	for (int i = 0; i < _dimension[0]; i++) {
		for (int j = 0; j < _dimension[1]; j++) {
			file.getline(line, '\n');
			p[i][j] = (line[0] == '0') ? '0' : '1';
			file.ignore(100, '\n');	// ignoring second píxel
			file.ignore(100, '\n');	// ignoring third pixel
		}
	}
	
	arquivo.close();
	
	for (int i = 0; i < _dimension[0]; i++) {
		for (int j = 0; j < _dimension[1]; j++)
			std::cout << _walkable[i][j];
		std::cout << std::endl;
	}
	
	return 0;
}
