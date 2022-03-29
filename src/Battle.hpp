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
		const float X_ENEMY_BAR = 14;
		const float Y_ENEMY_BAR = 14;
		// When using this variavel, remember to convert the int to a float
		const float X_HERO_BAR = 420;
		const float Y_HERO_BAR = 350;

		Position _selected_display_skill; //variavel para armazenar a posição da skill selecionada
		Position _cursor_position; //variavel para armazenar a posição atual do cursor
		
		//bitmaps para as imagens especificas da batalha
		ALLEGRO_BITMAP *_health_bar;
		ALLEGRO_BITMAP *_colored_bar;	
		ALLEGRO_BITMAP *_options;	
		ALLEGRO_FONT *_font;	
		ALLEGRO_BITMAP *_cursor;
		ALLEGRO_BITMAP *_background; 

		void draw_capimon(Character *character); //método para desenhar o capimon na batalha de acordo com o tipo de personagem
		void draw_capimon_status(Character *character); //método para desenhar a barrara de status do capimon de acordo com o tipo de personagem
		bool there_is_a_looser(Player *hero, Npc *enemy); //método para verificar se alguém perdeu
		void verify_selected_display_skill(Character *character); //método para  verificar a skill que foi selecionada no display
		void draw_skill(Skill* skill); //Método para desenhar a skill na batalha
		void draw_cursor(); //Método para desenhar o curso na batalha

	public:
		Battle(std::string background_directory);
		~Battle();
		bool start_battle(Player *hero , Npc *enemy); // Método para iniciar a batalha, retorno um boleano informando se o player ganhou
			
};

#endif /* BATTLE_HPP */
