/* Capimon.hpp */

#ifndef CAPIMON_HPP
#define CAPIMON_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>

class Capimon{
	private:
		const int AMOUNT_SKILLS = 4;
		std::string _name;
		ALLEGRO_BITMAP *_image;
		Skill _skills[AMOUNT_SKILLS];	// Or maybe Skill *_skills[4]
		int _max_health;
		int _cur_health;
		//ALLEGRO_BITMAP* _lifeBar;
		//ALLEGRO_BITMAP* _colorBar;
		//ALLEGRO_FONT *_font;
		//static float _x_bar_npc;
		//static float _y_bar_npc;
		//static float _x_bar_player;
		//static float _y_bar_player;

  public:
		Capimon(std::string name, ALLEGRO_BITMAP *image, int max_health, Skill skills[AMOUNT_SKILLS]);
		~Capimon();
		std::string get_name();
		int get_max_health();
		//void draw_player_capimon();//alterar ainda
		//void draw_npc_capimon();//alterar ainda 
		void decrement_health(int dano);
		bool looser();
		//void draw_player_status();
		//void draw_npc_status();

};

#endif /* CAPIMON_HPP */
