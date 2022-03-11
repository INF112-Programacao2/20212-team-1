#include "PlayerAttack.hpp"

PlayerAttack::PlayerAttack()
	: Object(al_load_bitmap("img/PlayerAttackBox.bmp"), 0, 320),
	m_nAtks(2)
{
	m_attacks = { { {"a", 13}, {"b", 1}, { }, { } } }; // inicializa com dois ataques
}

PlayerAttack::~PlayerAttack()
{

}

void PlayerAttack::addAttack(const Attack& _atk)
{
	m_attacks[m_nAtks - 1] = _atk;
}

void PlayerAttack::draw()
{
	if (m_nAtks = 1)
		al_draw_text(
			Object::gblFont,
			al_map_rgb(255, 2555, 255),
			this->_position.get_x() + 14.f, this->_position.get_y() + 14.f, 0, m_attacks[0].nome);
	
	if (m_nAtks = 2)
		al_draw_text(
			Object::gblFont,
			al_map_rgb(255, 2555, 255),
			this->_position.get_x() + 14.f, this->_position.get_y() + 30.f, 0, m_attacks[1].nome);
	
	if (m_nAtks = 3)
		al_draw_text(
			Object::gblFont,
			al_map_rgb(255, 2555, 255),
			this->_position.get_x() + 70.f, this->_position.get_y() + 14.f, 0, m_attacks[2].nome);
	
	if (m_nAtks = 4)
		al_draw_text(
			Object::gblFont,
			al_map_rgb(255, 2555, 255),
			this->_position.get_x() + 70.f, this->_position.get_y() + 30.f, 0, m_attacks[3].nome);
}

int PlayerAttack::do_attack(int _n)
{
	Attack atk = m_attacks[_n - 1];
	return atk.dano; // Retorna o dano
}
