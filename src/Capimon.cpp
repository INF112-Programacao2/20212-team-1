#include "Capimon.hpp"

Capimon::~Capimon(){

}

Capimon::Capimon(int Tipo){         

	this->C->_Tipo = Tipo;
    //Define o tipo do capimon(Inimigo ou Aliado)   
	if(Tipo==0)
        this->>_image = al_load_bitmap("Capimons.bmp");
    else
        this->set_sprite("Capimons_costas.bmp");
    this->Indice = 2;
    this->X = SCREEN_W+124;
    this->H = 112;
    this->_Ataque = 5;
    this->Sessao = 4;
    this->W = 112;
    this->_Vida = 100;

    Habilidade[0] = "Ataque ";
          //Habilidades do capimon    Habilidade[1] = "";
    Habilidade[3] = "";
    Habilidade[4] = "";
}

void Capimon::Mostrar_Capimon(){        //mostra o capimon na tela
    if(this->X>SCREEN_W-204)
        X -= 3;
}


oid Capimon::Aliado(){
    this->X = (SCREEN_W/2)-W;
    this->Y = SCREEN_H-180;
}

const void Capimon::Acao(){             //acão dcapimon a
    if(_Tipo==0)
        Inimigo();
    else
        Aliado();

    this->animado(0);
}

void Capimon::Inimigo(                //Mostra capimon inimigo){
    this->Mostrar_Capimon();
}

vvod Capimon::Set_DanoCausado(int Dano){
    this->_Vida -= Dano;
}

int Capimon::Get_Vida(){
    return _Vida;
}

int Capimon::Get_Ataque(){
    return _Ataque;
}
