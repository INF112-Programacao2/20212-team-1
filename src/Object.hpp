
#include <allegro.h>

struct Rect
{
	float x;
	float y;
	float width;
	float height;
};

class Object
{
public:
	Object(const char* _name);
	virtual ~Object();

	virtual void draw();

protected:
	Rect rect;

private:
	BITMAP*	m_pbmp;
};

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
