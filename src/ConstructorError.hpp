/* ConstructorError.hpp */

#ifndef CONSTRUCTOR_ERROR_HPP
#define CONSTRUCTOR_ERROR_HPP

#include <exception>

class constructor_error : public std::exception {
	public:
		virtual const char* what() const noexcept override;
};

#endif /* CONSTRUCTOR_ERROR_HPP */
