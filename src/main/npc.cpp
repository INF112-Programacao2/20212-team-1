/* npc.cpp */

#include "../Npc.hpp"
#include <iostream>

int main() {
	Npc npc("André", nullptr, 10, 10, nullptr);
	std::cout << npc.get_name() << std::endl;
	return 0;
}
