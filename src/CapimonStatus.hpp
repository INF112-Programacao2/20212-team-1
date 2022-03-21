#ifndef _CAPIMON_STATUS_HPP_
#define _CAPIMON_STATUS_HPP_

#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>

class CapimonStatus{
public:
	CapimonStatus(int maxVida, float x, float y);

	void decrementHealth(int dano);

	bool looser();

	void draw(const char* capname, ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* bar, ALLEGRO_FONT* font);

private:
	int _maxHealth;
	int _curHealth;
	ALLEGRO_BITMAP* _img;
	float _x;
	float _y;
};

#endif // !_CAPIMON_STATUS_HPP_
