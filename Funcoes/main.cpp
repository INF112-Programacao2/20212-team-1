#include <allegro.h>
#include <list>
#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
#include <sstream>
#include <stdlib.h>
#include "Object.hpp"
#include "HealthBar.hpp"
#include "CapimonStatus.hpp"
#include "PlayerAttack.hpp"
#include "Battle.hpp"
#include "Capimon.hpp"

void iniciar();
void terminar();

BITMAP *TELA;
BITMAP *SCREEN;
BITMAP *SYSTEM;


void *foco = NULL;
int width = 640;
int height = 480;

volatile long contador_velocidade = 0;

void incremento_velocidade(){
    contador_velocidade++;
}
END_OF_FUNCTION(incremento_velocidade);

int main(){

    iniciar();
    TELA = create_bitmap(SCREEN_W, SCREEN_H);
    SYSTEM = create_bitmap(SCREEN_W, SCREEN_H);
    SCREEN = create_bitmap(SCREEN_W, SCREEN_H);
    srand(time(NULL));

    BITMAP *fundo = load_bitmap("ArenaDeBatalha.bmp", NULL);
    InstanciasClasse.pushback(new Capimon());

    while(!key[KEY_ESC]){

        draw_sprite(TELA, fundo, 0, 0);
        if(contador_velocidade>0){
            for(list<Object*>::iterator it = instancias.begin(); it!=InstanciasClasse.end(), it++)
        }
    }
}