#ifndef INF112_OBJECT_HPP
#define INF112_OBJECT_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Object{
    protected:
        ALLEGRO_BITMAP *_image;
        Position _position;
    public:
        Object(ALLEGRO_BITMAP *image, int x, int y);
        ~Object();
        void change_image(ALLEGRO_BITMAP *image );
};
#endif