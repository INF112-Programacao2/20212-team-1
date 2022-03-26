/* Capimon.hpp */

#ifndef CAPIMON_HPP
#define CAPIMON_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <string>

class Capimon{
	private:
		
		std::string _name;
		ALLEGRO_BITMAP *_image;
		Skill _skills[AMOUNT_SKILLS];	// Or maybe Skill *_skills[4]
		static int AMOUNT_SKILLS
		int _maxHealth;
		int _curHealth;
		ALLEGRO_BITMAP* _lifeBar;
		ALLEGRO_BITMAP* _colorBar;
		ALLEGRO_FONT *_font;
		static float _x_bar_npc;
		static float _y_bar_npc;
		static float _x_bar_player;
		static float _y_bar_player;

  public:
		Capimon(std::string name, ALLEGRO_BITMAP *image, int maxHealth, Skill skills[AMOUNT_SKILLS]);
		~Capimon();
		std::string get_name();
		int get_maxHealth();
		void show_npc_capimon();//alterar ainda 
		void show_player_capimon();//alterar ainda
		void decrementHealth(int dano);
		bool looser();
		void draw_Status_Player();
		void draw_Status_NPC();

};

#endif /* CAPIMON_HPP */
