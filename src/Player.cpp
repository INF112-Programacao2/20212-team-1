#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Position.hpp"
#include "Object.hpp"
#include "Personagem.hpp"
#include "Player.hpp"


int Player::_numSprites = 4;
int Player::_tamPixels = 16;

Player::Player(std::string name, ALLEGRO_BITMAP *image,int x, int y, int tam_x, int tam_y):
    Personagem(name, image,x, y), _tam_x(tam_x), _tam_y(tam_y),_direcao_anterior(0), _numPasso(0) {};


Player::~Player(){}

void Player::walk(int direcao, Map &mapa){
    
    if(direcao == -1){
        al_draw_bitmap_region(_image, 0, 0,this->_tam_x,this->_tam_y,_position.get_x() * _tamPixels,_position.get_y() * _tamPixels,0 );
        _numPasso = 0;
        this->_direcao_anterior = 0;

    }else{
        if(direcao == 0 && mapa.get_val_walkable(this->_position.get_x(), this->_position.get_y() + 1) == '1'){
            this->_position.add_y();
        }else if(direcao == 1 && mapa.get_val_walkable(this->_position.get_x(), this->_position.get_y() - 1) == '1'){
            this->_position.sub_y();
        }else if(direcao == 2 && mapa.get_val_walkable(this->_position.get_x() - 1, this->_position.get_y() ) == '1'){
            this->_position.sub_x();
        }else if(direcao == 3 && mapa.get_val_walkable(this->_position.get_x() + 1, this->_position.get_y() ) == '1'){
            this->_position.add_x();
        }
        if(this->_direcao_anterior == direcao){
            this->_numPasso++;
            if(this->_numPasso >= _numSprites )
                this->_numPasso = 0;

        }else{
            this->_numPasso = 0;
        }
        this->_direcao_anterior = direcao;

        al_draw_bitmap_region(_image, this->_numPasso * this->_tam_x, direcao * this->_tam_y,this->_tam_x,this->_tam_y,_position.get_x() * _tamPixels,_position.get_y() * _tamPixels,0 );
    }
    
}

// TODO: Função interact()
void Player::interact(Npc *npc) {
	
}
