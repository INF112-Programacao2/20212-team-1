/* Capimon.hpp */

#ifndef CAPIMON_HPP
#define CAPIMON_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include <vector>

class Capimon{
	private:
		const int AMOUNT_SKILLS = 4;
		std::string _name;
		ALLEGRO_BITMAP *_image;
		vector<Skill> _skills;
		unsigned int _max_health;
		unsigned int _cur_health;
		//ALLEGRO_BITMAP* _lifeBar;
		//ALLEGRO_BITMAP* _colorBar;
		//ALLEGRO_FONT *_font;
		//static float _x_bar_npc;
		//static float _y_bar_npc;
		//static float _x_bar_player;
		//static float _y_bar_player;

  public:
		Capimon(std::string name, ALLEGRO_BITMAP *image, int max_health, Skill skills[AMOUNT_SKILLS]);	// TODO: Check if parameter skills can cause a bug
		~Capimon();
		std::string get_name();
		unsigned int get_max_health();
		unsigned int get_cur_health();
		vector<Skill> get_skills(int index);
		Skil get_skill();
		
		void decrement_health(int damage);
		//bool looser();
		
		//void draw_player_capimon();//alterar ainda
		//void draw_npc_capimon();//alterar ainda 
		//void draw_player_status();
		//void draw_npc_status();
};

#endif /* CAPIMON_HPP */
