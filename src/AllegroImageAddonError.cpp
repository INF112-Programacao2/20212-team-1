/* AllegroImageAddonError.cpp */

#include "AllegroImageAddonError.hpp"

const char* allegro_image_addon_error::what() const noexcept {
	return "Image addon must be initialized.";
}
