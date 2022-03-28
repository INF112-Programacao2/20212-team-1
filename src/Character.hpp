/* Character.hpp */

/*
 * This class is an abstractition of the intersection between Player and NPC. Both classes have somethings in commum, because they all represents "people", but one controlled by the user and one not.
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Position.hpp"
#include "Object.hpp"
#include "Capimon.hpp"

#include <string>

// Maybe this is a abstract class, because it's impossible to exist an object of type Character
class Character : public Object {
    protected:
      std::string _name;
      std::vector<Capimon*> _deck;
      Capimon* _selected_capimon = nullptr;
    public:
		  Character(std::string name, ALLEGRO_BITMAP *image,int x, int y);
		  ~Character();
		  const unsigned int AMOUNT_DECK = 4;
		  std::string get_name();
		  void add_capimon(Capimon *capimon);
      std::vector<Capimon*> get_deck();
      void select_capimon();
      Capimon* get_selected_capimon();
      void set_selected_capimon(int index);
      virtual Position get_CAPIMON_DRAW_POSITION() = 0;
      virtual Position get_CAPIMON_STATUS_POSITION() = 0;
};
#endif /* CHARACTER_HPP */
