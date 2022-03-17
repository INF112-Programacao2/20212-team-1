/* npc.cpp */

#include "../Npc.hpp"
#include <iostream>
#include "../Personagem.hpp"
#include "../Object.hpp"
#include <string>

std::string file[] = {"file/Andre.txt"};

int main() {
	Npc npc("Andre", nullptr, 10, 10, nullptr, file);
	std::cout << npc.get_name() << std::endl;
	npc.show_interaction(0);
	return 0;
}
