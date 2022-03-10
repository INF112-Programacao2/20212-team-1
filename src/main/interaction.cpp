#include "Interaction.hpp"

#include <iostream>

int main() {
	Interaction it("file/dialogs.txt");
	for (int i = 0; i <it.get_dialog_length(); i++) {
		std::string* dialog = it.get_dialog(i);
		std::cout << dialog[it.SPEAK] << std::endl;
		std::cout << dialog[it.ANSWER] << std::endl;
	}
	return 0;
}
