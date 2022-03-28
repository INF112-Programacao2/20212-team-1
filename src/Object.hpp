/* Object.hpp */

/*
 * This class represent everything that has a "fisical" image in the game
 */
 
//Classe privaria que ira armazer informações de imagens e posicão

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
		// std::string _font_directory;
		// ALLEGRO_FONT* _font;
		// int _font_size;
		Object(ALLEGRO_BITMAP *image, int x, int y); //construtor da classe Object
		~Object(); //destrutor da classe Object
		ALLEGRO_BITMAP* get_image(); //método para obter o bitmap de imagem da classe
		void set_image(ALLEGRO_BITMAP *image); //método para trocar o bitmap de imagem do object
		Position get_position(); // método para retonar a Position do objeto
};

#endif /* OBJECT_HPP */
