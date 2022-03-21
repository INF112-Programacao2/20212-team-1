/* Character.hpp */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Position.hpp"
#include "Object.hpp"

#include <string>

class Character : public Object {
    protected:
      std::string _name;
      // TODO: Adicionar vetor de Capimons
      //vector<*Capimon> _deck
    public:
    	// TODO: Incluir deck
		  Character(std::string name, ALLEGRO_BITMAP *image,int x, int y);
		  ~Character();
		  std::string get_name();
};

#endif /* CHARACTER_HPP */
