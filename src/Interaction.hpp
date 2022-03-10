/* Interaction.hpp */

#ifndef INTERACTION_HPP
#define INTERACTION_HPP

#include <string>

class Interaction {
	private:
		int _dialog_length;
		std::string** _dialogs;
	public:
		Interaction(std::string file_directory);
		~Interaction();
		int get_dialog_length();
		std::string* get_dialog(int n);
		
		const int SPEAK = 0;
		const int ANSWER = 1;
		const char DELIMITER = '|';
};

#endif /* INTERACTION_HPP */
