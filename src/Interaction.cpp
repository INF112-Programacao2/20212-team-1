/* Interaction.cpp */

#include "Interaction.hpp"

#include <fstream>
#include <exception>

Interaction::Interaction(std::string file_directory, std::string player_name, std::string npc_name) {
	std::string line;
	std::ifstream file(file_directory);
	if (!file.is_open())
		throw std::invalid_argument("It wasn't possible to open file in file_directory.");
	
	std::getline(file, line);
	this->_quantity_of_dialogs = std::stoul(line, nullptr);
	
	for (int i = 0; i < this->_quantity_of_dialogs; i++) {
		std::getline(file, line);
		int delim_pos = line.find_first_of(this->_DELIMITER);
		std::string speak = line.substr(0, delim_pos);
		std::string answer = line.substr(delim_pos + 1);
		this->_dialogs.push_back(Dialog(player_name, speak, npc_name, answer));
	}
	
	file.close();
	
	if (this->_quantity_of_dialogs != this->_dialogs.size())
		throw std::invalid_argument("The used file has a content problem.");
}

Interaction::~Interaction() {}

char Interaction::get_DELIMITER() const {
	return Interaction::_DELIMITER;
}

unsigned int Interaction::get_quantity_of_dialogs() {
	return this->_quantity_of_dialogs;
}

Dialog Interaction::get_dialog(int index) {
	if (index < 0 || index > this->_dialogs.size() - 1)
		throw std::invalid_argument("The value i must be beetween 0 and (_dialogs.size() - 1).");
	return this->_dialogs.at(index);
}

void Interaction::draw(int reference_x, int reference_y) {
	for (Dialog dialog : this->_dialogs)
		dialog.draw(reference_x, reference_y);
}