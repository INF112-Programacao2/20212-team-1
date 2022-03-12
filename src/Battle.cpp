#include "Battle.hpp"

Battle::Battle(cap_vida_t al)
	: Object(al_load_bitmap("img/ArenaDeBatalha.bmp"), 0, 0),
	_cps(al)
{ }

void Battle::setCapimons(cap_vida_t al)
{
	this->_cps = al;
}

void Battle::draw()
{
	al_draw_bitmap(this->_image, this->_position.get_x(), this->_position.get_y(), 0); // Desenha arena

	for (auto cp : _cps)
	{
		cp.second.draw();
		cp.first->Mostrar_Capimon();
	}

	_pl.draw(); // Desenha caixa de ataques
}
