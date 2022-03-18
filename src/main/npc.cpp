/* npc.cpp */

#include "../Npc.hpp"
#include <iostream>

int main() {
	std::string file[] = {"file/Andre.txt"}
	Npc npc("André", nullptr, 0, 0, file);
	// TODO: if key 'I' is pressed
	npc.show_interaction(0);	// TODO: Change way to store the interactions
	return 0;
}
