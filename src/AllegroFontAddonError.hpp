/* AllegroFontAddonError.hpp */

#ifndef ALLEGRO_FONT_ADDON_ERROR_HPP
#define ALLEGRO_FONT_ADDON_ERROR_HPP

#include "AllegroInitializationError.hpp"

class allegro_font_addon_error : public allegro_initialization_error {
	public:
		virtual const char* what() const noexcept override;
};

#endif /* ALLEGRO_FONT_ADDON_ERROR_HPP */
