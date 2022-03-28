/* Interaction.cpp */

#include "Interaction.hpp"

#include <fstream>

Interaction::Interaction(std::string file_directory) {
	std::string line;
	std::ifstream file(file_directory);
	
	std::getline(file, line);
	this->_quantity_of_dialogs = std::stoi(line, nullptr, 10);
	
	this->_dialogs = new std::string*[this->_quantity_of_dialogs];
	for (int i = 0; i < this->_quantity_of_dialogs; i++)
		this->_dialogs[i] = new std::string[this->SIZE];	// speak and answer
	
	for (int i = 0; i < this->_quantity_of_dialogs; i++) {
		std::getline(file, line);
		int delim_pos = line.find_first_of(this->DELIMITER);
		this->_dialogs[i][this->SPEAK] = line.substr(0, delim_pos);
		this->_dialogs[i][this->ANSWER] = line.substr(delim_pos + 1);
	}
	
	file.close();
}

Interaction::~Interaction() {
	for (int i = 0; i < this->_quantity_of_dialogs; i++)
		delete [] this->_dialogs[i];
	delete [] this->_dialogs;
}

int Interaction::get_quantity_of_dialogs() {
	return this->_quantity_of_dialogs;
}

std::string* Interaction::get_dialog(int n) {
	return this->_dialogs[n];
}
