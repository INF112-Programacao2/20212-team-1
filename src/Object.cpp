/* Object.cpp */

Object::Object(const char* _name)
{
	m_pbmp = load_bitmap(_name, nullptr);
}

Object::~Object()
{
	destroy_bitmap(m_pbmp);
}

void Object::draw()
{
	draw_sprite(TELA, m_pbmp, rect.x, rect.y);
}

Rect& Object::get_rect()
{
	return m_rect;
}
