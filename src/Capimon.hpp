/* Capimon.hpp */

#ifndef CAPIMON_HPP
#define CAPIMON_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include <vector>
#include "Skill.hpp"

class Capimon{
	private:
		static int AMOUNT_SKILLS;
		std::string _name;
		ALLEGRO_BITMAP *_image;
		std::vector<Skill> _skills;
		unsigned int _max_health;
		unsigned int _cur_health;
		//ALLEGRO_BITMAP* _lifeBar;
		//ALLEGRO_BITMAP* _colorBar;
		//ALLEGRO_FONT *_font;
		//static float _x_bar_npc;
		//static float _y_bar_npc;
		//static float _x_bar_player;
		//static float _y_bar_player;
		Skill* _selected_skill = nullptr;

  public:
		Capimon(std::string name, /*std::string image_directory*/ALLEGRO_BITMAP *image, int max_health, Skill skills[]);	// TODO: Check if parameter skills can cause a bug
		~Capimon();
		std::string get_name();
		unsigned int get_max_health();
		unsigned int get_cur_health();
		std::vector<Skill> get_skills();
		Skill get_skill(int index);
		void select_skill();
		Skill* get_selected_skill();
		void set_selected_skill(Skill *selected_skill);
		void set_selected_skill(int index);
		ALLEGRO_BITMAP* get_image();
		
		void decrement_health(int damage);
		void heal_health();
		//bool looser();
		
		//void draw_player_capimon();//alterar ainda
		//void draw_npc_capimon();//alterar ainda 
		//void draw_player_status();
		//void draw_npc_status();
};

#endif /* CAPIMON_HPP */
