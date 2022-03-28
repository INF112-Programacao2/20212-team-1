/* Interaction.hpp */

#ifndef INTERACTION_HPP
#define INTERACTION_HPP

#include "Dialog.hpp"

#include <vector>

class Interaction {
	private:
		unsigned int _quantity_of_dialogs;
		std::vector<Dialog> _dialogs;
		static const char _DELIMITER = '|';
	public:
		Interaction(std::string file_directory);
		~Interaction();
		unsigned int get_quantity_of_dialogs();
		Dialog get_dialog(int i);
		char get_DELIMITER() const;
};

#endif /* INTERACTION_HPP */
