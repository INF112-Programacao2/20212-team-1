/* InitializationError.hpp */

#ifndef ALLEGRO_INITIALIZATION_ERROR_HPP
#define ALLEGRO_INITIALIZATION_ERROR_HPP

#include <exception>

class allegro_initialization_error : public std::exception {
	virtual const char* what() const noexcept = 0;
};

#endif /* INITIALIZATION_ERROR_HPP */
