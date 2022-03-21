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
    const int AMOUNT_SKILLS = 4;
  public:
		Capimon(std::string name, ALLEGRO_BITMAP *image, int life, Skill skills[]);
		~Capimon();
		int get_life();
		void show_capimon();
};

#endif /* CAPIMON_HPP */
