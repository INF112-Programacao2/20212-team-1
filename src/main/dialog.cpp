/* dialog.cpp */

#include "../Dialog.hpp"

#include <iostream>

int main() {
	Dialog dialog("Capivaristo", "Olá! Como está?", "André", "Bem, e você?");
	std::cout << dialog.get_player_name() << ": " << dialog.get_speak() << std::endl;
	std::cout << dialog.get_player_name() << ": " << dialog.get_answer() << std::endl;
	dialog.set_speak("Hello! How are you?");
	dialog.set_answer("Fine, and you?");
	std::cout << dialog.get_speak() << std::endl;
	std::cout << dialog.get_answer() << std::endl;
	
	al_init();
	
	ALLEGRO_DISPLAY *display = nullptr;
	display = al_create_display(640, 480);
	
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	
	dialog.draw();
	
	al_destroy_display(display);
	
	return 0;
}
