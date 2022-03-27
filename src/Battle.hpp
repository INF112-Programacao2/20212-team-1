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

	public:
		Battle(Player *hero, Npc *enemy, ALLEGRO_FONT *font, std::string endereco_life_bar, std::endereco_color_bar);
		//	Alternative constructor considering _health_bar, _colored_bat and _font like consts
		Battle(Player *hero, Npc *enemy);
		~Battle();
		void start_battle();
};
