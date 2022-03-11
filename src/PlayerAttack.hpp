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

	void addAttack(const Attack& _atk);

	void draw();

	int do_attack(int _n);

private:
	std::array<Attack, 4> m_attacks; // Define um maximo de quatro ataques por Capimon
	int m_nAtks;
};
#endif /* PLAYER_ATTACK_HPP */
