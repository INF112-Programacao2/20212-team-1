#include <allegro5/allegro_font.h>
#include <string>
#include "CapimonStatus.hpp"

CapimonStatus::CapimonStatus(Capimon* _cap, int x, int y)
	: Object(al_load_bitmap("img/StatusBox.bmp"), x, y),
	_bar(al_load_bitmap("img/Bar.bmp")),
	_cap(_cap),
	_health(_cap->Get_Vida()),
	_maxHealth(_cap->Get_Vida())
{
	if (!_cap)
		throw "Nao eh um capimon";
}

void CapimonStatus::decrementHealth(int _a)
{
	if ((this->_health -= _a) <= 0)
		this->_health = 0;
}

void CapimonStatus::draw()
{
	al_draw_bitmap(
		this->_image,
		this->_position.get_x(),
		this->_position.get_y(), 0
		); // Desenha caixa na posição

	al_draw_scaled_bitmap(
		_bar,
		14.f, 14.f,
		BAR_VIDA_WIDTH, BAR_VIDA_HEIGHT,
		14.f, 14.f,
		this->_health * 2.f, BAR_VIDA_HEIGHT, // Calcula tamnaho da barra
		0); // Desenha barra de vida

	al_draw_text(
		Object::gblFont,
		al_map_rgb(255, 255, 255),
		this->_position.get_x() + 14.f,
		this->_position.get_y() + 32.f,
		0, this->_cap->Get_nome()); // Desenha nome do Capimon

	al_draw_text(
		Object::gblFont,
		al_map_rgb(255, 255, 255),
		this->_position.get_x() + 24.f,
		this->_position.get_y() + 32.f,
		0, (std::to_string(this->_health) + "/" + std::to_string(this->_maxHealth)).c_str()); // Desenha vida
}
