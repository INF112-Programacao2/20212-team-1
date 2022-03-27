/* Character.hpp */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Position.hpp"
#include "Object.hpp"
#include "Capimon.hpp"

#include <string>

// Maybe this is a virtual class, because it's impossible to exist an object of type Character
class Character : public Object {
    protected:
    	const unsigned int AMOUNT_DECK = 4;
      std::string _name;
      vector<*Capimon> _deck;
      Capimon* _selected_capimon = nullptr;
    public:
		  Character(std::string name, ALLEGRO_BITMAP *image,int x, int y);
		  ~Character();
		  std::string get_name();
		  void add_capimon(Capimon *capimon);
      vector<Capimon> get_deck();
      void select_capimon();
      Capimon* get_selected_capimon();
      Position get_CAPIMON_DRAW_POSITION() = 0;
};
#endif /* CHARACTER_HPP */
