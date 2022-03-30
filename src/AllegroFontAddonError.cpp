/* AllegroFontAddonError.cpp */

#include "AllegroFontAddonError.hpp"

const char* allegro_font_addon_error::what() const noexcept {
	return "Font addon must be initialized.";
}
