#include "../Object.hpp"
#include <iostream>

int main() {
	Object ob(nullptr, 10, 10);
	Position p = ob.get_position();
	std::cout << p.get_x() << " " << p.get_y() << std::endl;
}
