/* AllegroSystemError.cpp */

#include "AllegroSystemError.hpp"

const char* allegro_system_error::what() const noexcept {
	return "Allegro must be installed.";
}
