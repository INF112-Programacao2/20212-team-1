/* Capimon.hpp */

#ifndef CAPIMON_HPP
#define CAPIMON_HPP

#include <allegro5/allegro.h>
#include <string>

class Capimon{
	private:
		std::string _name;
    ALLEGRO_BITMAP *_image;
    int _life;
    Skill _skills[AMOUNT_SKILLS];	// Or maybe Skill *_skills[4]
    static int AMOUNT_SKILLS;
  public:
		Capimon(std::string name, ALLEGRO_BITMAP *image, int life, Skill skills[AMOUNT_SKILLS]);
		~Capimon();
		std::string get_name();
		int get_life();
		void show_capimonNpc();
		void show_capimonPlayer();
};

#endif /* CAPIMON_HPP */
