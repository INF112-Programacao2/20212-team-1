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
	public:
		Battle(Player *hero, Npc *enemy);
		~Battle();
		void start_battle();
};
