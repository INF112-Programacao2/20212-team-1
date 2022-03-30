/* AllegroSystemError.hpp */

#ifndef ALLEGRO_SYSTEM_ERROR_HPP
#define ALLEGRO_SYSTEM_ERROR_HPP

#include "AllegroInitializationError.hpp"

class allegro_system_error : public allegro_initialization_error {
	public:
		virtual const char* what() const noexcept override;
};

#endif /* CONSTRUCTOR_ERROR_HPP */
