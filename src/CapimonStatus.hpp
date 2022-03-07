/* CapimonStatus.hpp */

#ifndef CAPIMON_STATUS_HPP
#define CAPIMON_STATUS_HPP

#include "Object.hpp"

class CapimonStatus
{
public:
	CapimonStatus();

	void decrementHealth(int _a);

	void draw() override;

private:
	int m_health;
	int m_maxHealth;
};

#endif /* CAPIMON_STATUS_HPP */
