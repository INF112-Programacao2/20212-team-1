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
		Player *_hero;
		Npc *_enemy;
		//comecando alteracoes 

		/*const*/ ALLEGRO_BITMAP* _health_bar /* = al_load_bitmap("img/battle/health_bar.bmp") */;	// this variable is like a const
		/*const*/ ALLEGRO_BITMAP* _colored_bar /* = al_load_bitmap("img/battle/colored_bar.bmp") */;	// this varible is like a const
		/*const*/ ALLEGRO_FONT* _font /* = al_load_font("font.ttf", 11, 0) */;	// this varible is like a const
		static float _x_bar_npc;	// this varible is like a const
		static float _y_bar_npc;	// this varible is like a const
		static float _x_bar_player;	// this varible is like a const
		static float _y_bar_player;	// this varible is like a const

		//metodos privados que serao usados em start_battle para realizar todas as acoes da batalha
		// TODO: Unificate draw_player_capimon() and draw_npc_capimon()
		void draw_player_capimon();
		void draw_npc_capimon();
		// TODO: Unificate draw_player_status() and draw_npc_status()
		void draw_player_status();
		void draw_npc_status();
		
		/* PLAYER_ATTACK_HPP ATRIBUTES - BEGIN */
		// TODO: Change position of consts
		const int UP_LEFT = 0;
		const int DOWN_LEFT = 1;
		const int UP_RIGHT = 2;
		const int DOWN_RIGHT = 3;
		/* PLAYER_ATTACK_HPP ATRIBUTES - END */
		
		/* NEW ATRIBUTES - BEGIN */
		Capimon* _selected_player_capimon = nullptr;
		Skill* _selected_player_skill = nullptr;
		Capimon* _selected_npc_capimon = nullptr;
		Skill* _selected_npc_skill = nullptr;
		/* NEW ATRIBUTES - END */

	public:
		Battle(Player *hero, Npc *enemy, ALLEGRO_FONT *font, std::string endereco_life_bar, std::endereco_color_bar);
		//	Alternative constructor considering _health_bar, _colored_bat and _font like consts
		Battle(Player *hero, Npc *enemy);
		~Battle();
		void start_battle();
		
		/* PLAYER_ATTACK_HPP FUNCTIONS - BEGIN */
		void draw_cursor(); //void draw(); // TODO: This will be a private function latter
		int select_enemy_attack(); //int ataqueInimigo();
		int select_player_attack(); //void selectAttack(int key);
		int do_attack();
		/* PLAYER_ATTACK_HPP FUNCTIONS - END */
		
		/* SKILL FUNCTIONS - BEGIN */
		void draw_skill(Skill* skill);	// void draw_skill_in_battle()	// TODO: This will be a private function latter
		/* SKILL FUNCTIONS - END */
		
		/* NEW FUNCTIONS - BEGIN */
		bool there_is_a_looser();
		
		// TODO: Unificate _selected_player_[...] with _selected_npc_[...]
		Capimon* get_selected_player_capimon();
		Skill* get_selected_player_skill();
		void set_selected_player_capimon(Capimon* selected_player_capimon);
		void set_selected_player_skill(Skill* selected_player_skill);
		
		Capimon* get_selected_npc_capimon();
		Skill* get_selected_npc_skill();
		void set_selected_npc_capimon(Capimon* selected_npc_capimon);
		void set_selected_npc_skill(Skill* selected_npc_skill);
		/* NEW FUNCTIONS - END */
};
