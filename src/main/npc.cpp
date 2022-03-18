/* npc.cpp */

#include "../Npc.hpp"
#include <iostream>

int main() {
	Npc npc("André", nullptr, 0, 0, file);
	std::cout << npc.get_name() << std::endl;
	npc.show_interaction(0);
	return 0;
}
