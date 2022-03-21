#include <iostream>
#include "CapimonStatus.hpp"

CapimonStatus::CapimonStatus(int maxVida, float x, float y)
	: _maxHealth(maxVida),
	_curHealth(maxVida),
	_x(x),
	_y(y)
{}

void CapimonStatus::decrementHealth(int dano)
{
	_curHealth -= dano;
	if (_curHealth <= 0)
		_curHealth = 0;
}

bool CapimonStatus::looser()
{
	return _curHealth == 0;
}

void CapimonStatus::draw(const char* capname, ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* bar, ALLEGRO_FONT* font)
{
	al_convert_mask_to_alpha(img, al_map_rgb(255,0,255));
	al_draw_bitmap(img, _x, _y, 0);
	al_draw_text(font, al_map_rgb(0,0,0), _x + 14.f, _y + 5.f, ALLEGRO_ALIGN_LEFT, capname);
	al_draw_scaled_bitmap(bar, 0.f, 0.f, 18.f, 10.f, _x + 78.f, _y + 32.f, ((float)_curHealth / (float)_maxHealth) * 96.f, 10.f, 0);
}