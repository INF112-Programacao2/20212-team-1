/* Character.hpp */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Position.hpp"
#include "Object.hpp"
#include "Capimon.hpp"

#include <string>

class Character : public Object {
    protected:
      std::string _name;
      vector<*Capimon> _deck
    public:
		  Character(std::string name, ALLEGRO_BITMAP *image,int x, int y);
		  ~Character();
		  std::string get_name();
		  void add_capimon(Capimon *capimon);
};

#endif /* CHARACTER_HPP */
