#include "../Interaction.hpp"

#include <iostream>

int main() {
	Interaction interaction("../file/Andre.txt");
	int num_dialogs = interaction.get_quantity_of_dialogs();
	std::cout << "There are " << num_dialogs << " dialogs\n" << std::endl;
	for (unsigned int i = 0; i < num_dialogs; i++) {
		Dialog dialog = interaction.get_dialog(i);
		std::cout << "Speak: " << dialog.get_speak() << std::endl;
		std::cout << "Answer: " << dialog.get_answer() << std::endl;
		std::cout << "***" << std::endl;
	}
	return 0;
}
