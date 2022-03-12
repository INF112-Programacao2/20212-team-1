#ifndef INF112_OBJECT_HPP
#define INF112_OBJECT_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include "Position.hpp"

#define DEF_FONT_SIZE	12

class Object{
    protected:
        ALLEGRO_BITMAP *_image;
        Position _position;
    public:
		static ALLEGRO_FONT* gblFont;

        Object(ALLEGRO_BITMAP *image, int x, int y);
        ~Object();
        void change_image(ALLEGRO_BITMAP *image);
        Position get_position();
};
#endif
