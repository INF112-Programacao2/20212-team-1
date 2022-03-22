/* PlayerAttack.hpp */

#ifndef PLAYER_ATTACK_HPP
#define PLAYER_ATTACK_HPP

#include <string>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class PlayerAttack{
	private:
		int _selected;
		// TODO: Change position of consts
		const int UP_LEFT = 0;
		const int DOWN_LEFT = 1;
		const int UP_RIGHT = 2;
		const int DOWN_RIGHT = 3;
	public:
		PlayerAttack();
		void draw(ALLEGRO_FONT *font, ALLEGRO_BITMAP *seta);
		int ataqueInimigo();
		void selectAttack(int key);
		int do_attack();
};

#endif /* PLAYER_ATTACK_HPP */
