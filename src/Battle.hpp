/* Battle.hpp */

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "Position.hpp"
#include "Npc.hpp"
#include "Capimon.hpp"
#include "Character.hpp"
#include "Player.hpp"
#include "Skill.hpp"


// TODO: Check if there is something repeated
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <string>



class Battle {
	private:
		// When using this variavel, remember to convert the int to a float
		// const Position ENEMY_BAR_POSITION = Position(14, 14);
		const float X_ENEMY_BAR = 14;	// TODO: Maybe move to other class
		const float Y_ENEMY_BAR = 14;	// TODO: Maybe move to other class
		// When using this variavel, remember to convert the int to a float
		// const Position HERO_BAR_POSITION = Position(420, 350);
		const float X_HERO_BAR = 420;	// TODO: Maybe move to other class
		const float Y_HERO_BAR = 350;	// TODO: Maybe move to other class
		const int UP_LEFT = 0;
		const int DOWN_LEFT = 1;
		const int UP_RIGHT = 2;
		const int DOWN_RIGHT = 3;
		Position _selected_display_skill;
		Position _cursor_position;
		
		ALLEGRO_BITMAP *_health_bar;	// TODO: Maybe declare like a const
		ALLEGRO_BITMAP *_colored_bar;	// TODO: Maybe declare like a const
		ALLEGRO_BITMAP *_options;	// TODO: Maybe declare like a const
		ALLEGRO_FONT *_font;	// TODO: Maybe declare like a const
		ALLEGRO_BITMAP *_cursor;
		ALLEGRO_BITMAP *_background; 

		void draw_capimon(Character *character);
		void draw_capimon_status(Character *character);
		bool there_is_a_looser(Player *hero, Npc *enemy);
		void verify_selected_display_skill(Character *character);
		void exit_battle();
		void draw_skill(Skill* skill);
		void draw_cursor();

	public:
		Battle(std::string background_directory);
		~Battle();
		bool start_battle(Player *hero , Npc *enemy);
			
};

#endif /* BATTLE_HPP */
