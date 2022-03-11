/* Interaction.cpp */

#include "Interaction.hpp"

#include <fstream>

Interaction::Interaction(std::string file_directory) {
	std::string line;
	std::ifstream file(file_directory);
	
	std::getline(file, line);
	this->_dialog_length = std::stoi(line, nullptr, 10);
	
	this->_dialogs = new std::string*[this->_dialog_length];
	for (int i = 0; i < this->_dialog_length; i++)
		this->_dialogs[i] = new std::string[2];	// speak and answer
	
	for (int i = 0; i < this->_dialog_length; i++) {
		std::getline(file, line);
		int delim_pos = line.find_first_of(this->DELIMITER);
		this->_dialogs[i][SPEAK] = line.substr(0, delim_pos);
		this->_dialogs[i][ANSWER] = line.substr(delim_pos + 1);
	}
	
	file.close();
}

Interaction::~Interaction() {
	for (int i = 0; i < this->_dialog_length; i++)
		delete [] this->_dialogs[i];
	delete [] this->_dialogs;
}

int Interaction::get_dialog_length() {
	return this->_dialog_length;
}

std::string* Interaction::get_dialog(int n) {
	return this->_dialogs[n];
}
