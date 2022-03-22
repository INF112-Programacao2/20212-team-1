/* CapimonStatus.hpp */

#ifndef CAPIMON_STATUS_HPP
#define CAPIMON_STATUS_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>

class CapimonStatus{
	private:
		int _maxHealth;
		int _curHealth;
		ALLEGRO_BITMAP* _img;
		float _x;
		float _y;
	public:
		CapimonStatus(int maxVida, float x, float y);
		void decrementHealth(int dano);
		bool looser();
		void draw(const char* capname, ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* bar, ALLEGRO_FONT* font);
};

#endif /* CAPIMON_STATUS_HPP */
