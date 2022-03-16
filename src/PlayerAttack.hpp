/* PlayerAttack.hpp */

#ifndef PLAYER_ATTACK_HPP
#define PLAYER_ATTACK_HPP

#include <array>
#include "Object.hpp"

struct Attack
{
	const char* nome = "<vazio>"; // Valor default
	int dano = 0;
};

class PlayerAttack
	: public Object
{
public:
	PlayerAttack();
	~PlayerAttack();

	void addAttack(const Attack& atk);

	void selectAttack(int key);

	void draw();

	int do_attack(int n);

private:
	std::array<Attack, 4> _attacks; // Define um maximo de quatro ataques por Capimon
	int _selected; // 0 = cima-esquerda, 1 = baixo-esquerda, 2 = cima-direita, 3 = baixo-direita
	int _nAtks;
};
#endif /* PLAYER_ATTACK_HPP */
