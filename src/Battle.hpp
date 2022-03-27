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

		ALLEGRO_BITMAP* _life_Bar;
		ALLEGRO_BITMAP* _color_Bar;
		ALLEGRO_FONT *_font;
		static float _x_bar_npc;
		static float _y_bar_npc;
		static float _x_bar_player;
		static float _y_bar_player;

		//metodos privados que serao usados em start_battle para realizar todas as acoes da batalha
		void draw_player_capimon();//alterar ainda
		void draw_npc_capimon();//alterar ainda 
		void draw_player_status();
		void draw_npc_status();

	public:
		Battle(Player *hero, Npc *enemy, ALLEGRO_FONT *font, std::string endereco_life_bar, std::endereco_color_bar);
		~Battle();
		void start_battle();
};
