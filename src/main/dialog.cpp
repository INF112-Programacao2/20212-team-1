/* dialog.cpp */

#include "../Dialog.hpp"

#include <iostream>

int main() {
	Dialog dialog("Olá! Como está?", "Bem, e você?");
	std::cout << dialog.get_speak() << std::endl;
	std::cout << dialog.get_answer() << std::endl;
	dialog.set_speak("Hello! How are you?");
	dialog.set_answer("Fine, and you?");
	std::cout << dialog.get_speak() << std::endl;
	std::cout << dialog.get_answer() << std::endl;
	
	return 0;
}
