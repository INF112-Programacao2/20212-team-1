/* AllegroTTFAddonError.hpp */

#ifndef ALLEGRO_TTF_ADDON_ERROR_HPP
#define ALLEGRO_TTF_ADDON_ERROR_HPP

#include "AllegroInitializationError.hpp"

class allegro_ttf_addon_error : public allegro_initialization_error {
	virtual const char* what() const noexcept override;
};

#endif /* #define ALLEGRO_TTF_ADDON_ERROR_HPP */
