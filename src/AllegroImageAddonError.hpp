/* AllegroImageAddonError.hpp */

#ifndef ALLEGRO_IMAGE_ADDON_ERROR_HPP
#define ALLEGRO_IMAGE_ADDON_ERROR_HPP

#include "AllegroInitializationError.hpp"

class allegro_image_addon_error : public allegro_initialization_error {
	public:
		virtual const char* what() const noexcept override;
};

#endif /* ALLEGRO_IMAGE_ADDON_ERROR_HPP */
