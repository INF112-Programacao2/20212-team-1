#include "../Interaction.hpp"

#include <iostream>

int main() {
	Interaction interaction("../file/Andre.txt", "Capivaristo", "André");
	int num_dialogs = interaction.get_quantity_of_dialogs();
	std::cout << "There are " << num_dialogs << " dialogs\n" << std::endl;
	for (unsigned int i = 0; i < num_dialogs; i++) {
		Dialog dialog = interaction.get_dialog(i);
		std::cout << "Speak: " << dialog.get_speak() << std::endl;
		std::cout << "Answer: " << dialog.get_answer() << std::endl;
		std::cout << "***" << std::endl;
	}
	
	al_init();
	
	ALLEGRO_DISPLAY *display = nullptr;
	display = al_create_display(640, 480);
	
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	
	interaction.draw();
	
	al_destroy_display(display);
	
	return 0;
}
