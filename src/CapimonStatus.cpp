/* CapimonStatus.cpp */

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
