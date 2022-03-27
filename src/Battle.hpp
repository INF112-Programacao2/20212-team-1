/* Battle.hpp */

#include "Npc.hpp"

// TODO: Check if there is something repeated
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "CapimonStatus.hpp"
#include "Capimon.hpp"
#include "PlayerAttack.hpp"

const int SCREEN_W = 640;
const int SCREEN_H = 480;

class Battle {
	private:
		//Player *_hero;
		//Npc *_enemy;
		
		//comecando alteracoes
		
		const float X_ENEMY_BAR = 14;	// TODO: Maybe move to other class
		const float Y_ENEMY_BAR = 14;	// TODO: Maybe move to other class
		const float X_HERO_BAR = 420;	// TODO: Maybe move to other class
		const float Y_HERO_BAR = 350;	// TODO: Maybe move to other class
		
		ALLEGRO_BITMAP* _health_bar;	// TODO: Maybe declare like a const
		ALLEGRO_BITMAP* _colored_bar;	// TODO: Maybe declare like a const
		ALLEGRO_BITMAP *_options;	// TODO: Maybe declare like a const
		ALLEGRO_FONT* _font;	// TODO: Maybe declare like a const
		
		ALLEGRO_BITMAP *_background; 
		

		//metodos privados que seCapimon *capimonNpcrao usados em start_battle para realizar todas as acoes da batalha
		void draw_capimon(Character *character);
		// TODO: Unificate draw_player_capimon() and draw_npc_capimon()
		void draw_player_capimon(Capimon *capimon);
		void draw_npc_capimon(Capimon *capimon);
		// TODO: Unificate draw_player_status() and draw_npc_status()
		void draw_player_status(Capimon *capimon);
		void draw_npc_status(Capimon *capimon);
		
		// NEW PRIVATE METHODS
		bool there_is_a_looser();
		void verify_selected_display_skill();
		void exit_battle();
		
		/* PLAYER_ATTACK_HPP ATRIBUTES - BEGIN */
		// TODO: Change position of consts
		const int UP_LEFT = 0;
		const int DOWN_LEFT = 1;
		const int UP_RIGHT = 2;
		const int DOWN_RIGHT = 3;
		/* PLAYER_ATTACK_HPP ATRIBUTES - END */
		
		/* SKILL FUNCTIONS - BEGIN */
		void draw_skill(Skill* skill);	// void draw_skill_in_battle()	// TODO: This will be a private function latter
		/* SKILL FUNCTIONS - END */
		
		/* NEW ATRIBUTES - BEGIN */
		Position _selected_display_skill;
		/* NEW ATRIBUTES - END */

	public:
		Battle(std::string options_directory);
		~Battle();
		void start_battle(Player *hero , NPC *enemy);
		
		/* PLAYER_ATTACK_HPP FUNCTIONS - BEGIN */
		void draw_cursor(); //void draw(); // TODO: This will be a private function latter
		// int select_enemy_attack(); //int ataqueInimigo();
		// int select_player_attack(); //void selectAttack(int key);
		// int do_attack();
		/* PLAYER_ATTACK_HPP FUNCTIONS - END */
};
