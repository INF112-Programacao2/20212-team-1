/* Capimon.hpp */

#ifndef CAPIMON_HPP
#define CAPIMON_HPP

#include "Skill.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include <string>
#include <vector>

class Capimon : public Object {
	private:
		std::string _name;
		int _max_health;
		int _cur_health;
		std::vector<Skill> _skills;
		Skill* _selected_skill;
  public:
		Capimon(std::string name, /*std::string image_directory*/ALLEGRO_BITMAP *image, int x, int y, int max_health, Skill skills[]);
		~Capimon();
		const int AMOUNT_SKILLS = 4;
		std::string get_name();
		int get_max_health();
		int get_cur_health();
		std::vector<Skill> get_skills();
		Skill get_skill(int index);
		void select_skill();
		Skill* get_selected_skill();
		void set_selected_skill(Skill *selected_skill);
		void set_selected_skill(int index);
		void decrement_health(int damage);
		void heal_health();
};

#endif /* CAPIMON_HPP */
