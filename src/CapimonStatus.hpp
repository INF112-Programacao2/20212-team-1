
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

CapimonStatus::CapimonStatus()
{

}

void CapimonStatus::decrementHealth(int _a)
{
	m_health -= _a;
}

void CapimonStatus::draw()
{
	Object::draw();
}
