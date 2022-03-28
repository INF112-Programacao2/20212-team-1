/* Object.hpp */

/*
 * This class represent everything that has a "fisical" image in the game
 */
 

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Position.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>

class Object {
	protected:
		ALLEGRO_BITMAP *_image;
		Position _position;
	public:
		std::string _font_directory;
		ALLEGRO_FONT* _font;
		int _font_size;
		Object(ALLEGRO_BITMAP *image, int x, int y);
		~Object();
		void change_image(ALLEGRO_BITMAP *image);
		ALLEGRO_BITMAP* get_image();
		Position get_position();
};

#endif /* OBJECT_HPP */
