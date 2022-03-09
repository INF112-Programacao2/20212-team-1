#ifndef INF112_PERSONAGEM_HPP
#define INF112_PERSONAGEM_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Position.hpp"
#include "Object.hpp"

class Personagem : public Object{
    protected:
        std::string _name;
        //vector<*Capimon> deck adicionar vetor de capimons depois
    public:
        Personagem(std::string name, ALLEGRO_BITMAP *image,int x, int y); // colocar o deck depois
        ~Personagem();

};
#endif
