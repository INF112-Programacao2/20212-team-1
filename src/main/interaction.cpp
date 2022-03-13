#include "../Interaction.hpp"

#include <iostream>

int main() {
	Interaction it("file/Andre.txt");
	int num_dialogs = it.get_dialog_length();
	std::cout << "There are " << num_dialogs << " dialogs\n" << std::endl;
	for (int i = 0; i < num_dialogs; i++) {
		std::string* dialog = it.get_dialog(i);
		std::cout << "Player: " << dialog[it.SPEAK] << std::endl;
		std::cout << "NPC: " << dialog[it.ANSWER] << std::endl;
		std::cout << "***" << std::endl;
	}
	return 0;
}
