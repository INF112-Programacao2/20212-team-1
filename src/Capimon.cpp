/* Capimon.cpp */

#include "Capimon.hpp"

Capimon::~Capimon(){

}

Capimon::Capimon(int Tipo){

    this->_Tipo = Tipo;
    if(Tipo==0)
        this->set_sprite("Capimons.bmp");
    else
        this->set_sprite("Capimons_costas.bmp");
    this->Indice = 2;
    this->X = SCREEN_W+124;
    this->H = 112;
    this->_Ataque = 5;
    this->Sessao = 4;
    this->W = 112;
    this->_Vida = 100;
}

void Capimon::Mostrar_Capimon(){
    if(this->X>SCREEN_W-204)
        X -= 3;
}

void Capimon::Aliado(){
    this->X = (SCREEN_W/2)-W;
    this->Y = SCREEN_H-180;
}

const void Capimon::Acao(){
    if(_Tipo==0)
        Inimigo();
    else
        Aliado();
}

void Capimon::Inimigo(){
    this->Mostrar_Capimon();
}

void Capimon::Set_DanoCausado(int Dano){
    this->_Vida -= Dano;
}

int Capimon::Get_Vida(){
    return _Vida;
}

int Capimon::Get_Ataque(){
    return _Ataque;
}
