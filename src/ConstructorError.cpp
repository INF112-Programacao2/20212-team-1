/* ConstructorError.cpp */

#include "ConstructorError.hpp"

const char* constructor_error::what() const noexcept {
	return "It wasn't possible to instaciate this object.";
}
