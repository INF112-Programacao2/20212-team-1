/* PlayerAttack.hpp */

#ifndef PLAYER_ATTACK_HPP
#define PLAYER_ATTACK_HPP

#include <string>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class PlayerAttack{
public:
	PlayerAttack();

    //void set_habilidades(const string* hl);

	void draw(ALLEGRO_FONT *font, ALLEGRO_BITMAP *seta);

	int ataqueInimigo();

	void selectAttack(int key);

	int do_attack();

private:
	//const string* m_attacks; // Define um maximo de quatro ataques por Capimon
	int _selected; // 0 = cima-esquerda, 1 = baixo-esquerda, 2 = cima-direita, 3 = baixo-direita
};

#endif /* PLAYER_ATTACK_HPP */