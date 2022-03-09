#ifndef INF112_PLAYER_HPP
#define INF112_PLAYER_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Personagem.hpp"
#include "Object.hpp"
#include "Position.hpp"

class Player : public Personagem{
    private:
        static int _numSprites;
        static int _tamPixels;
        int _direcao_anterior;
        int _numPasso;
        int _tam_x;
        int _tam_y;
    public:
        Player(std::string name, ALLEGRO_BITMAP *image,int x, int y, int tam_x, int tam_y);
        ~Player();
        void walk(int direcao);
        
};
#endif
