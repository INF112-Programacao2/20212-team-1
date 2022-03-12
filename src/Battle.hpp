/* Battle.hpp */

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <array>
#include <memory>
#include "Capimon.hpp"
#include "CapimonStatus.hpp"
#include "PlayerAttack.hpp"
#include "Object.hpp"

class Battle
	: public Object
{
public:
	typedef std::array<std::pair<Capimon*, CapimonStatus>, 2> cap_vida_t;

	Battle(cap_vida_t al);

	void setCapimons(cap_vida_t al);

	void draw();

private:
	cap_vida_t _cps;
	PlayerAttack _pl;
};

#endif /* BATTLE_HPP */
