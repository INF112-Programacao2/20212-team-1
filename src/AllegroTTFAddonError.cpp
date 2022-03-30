/* AllegroTTFAddonError.cpp */

#include "AllegroTTFAddonError.hpp"

const char* allegro_ttf_addon_error::what() const noexcept {
	return "TTF addon must be initialized.";
}
