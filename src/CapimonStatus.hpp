/* CapimonStatus.hpp */

#ifndef CAPIMON_STATUS_HPP
#define CAPIMON_STATUS_HPP

#include "Capimon.hpp"
#include "Object.hpp"

#define BAR_VIDA_WIDTH	16.f
#define BAR_VIDA_HEIGHT	16.f

class CapimonStatus
	: public Object
{
public:
	CapimonStatus(Capimon* cap, int x, int y);

	void decrementHealth(int d);

	void draw();

private:
	ALLEGRO_BITMAP* _bar;
	Capimon* _cap;
	int _health;
	int _maxHealth;
};

#endif /* CAPIMON_STATUS_HPP */
