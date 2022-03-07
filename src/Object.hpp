/* Object.hpp */

#ifndef OBJECT_HPP
#define OBJECT_HPP

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

#endif /* OBJECT_HPP */
