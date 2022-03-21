#include "Capimon.hpp"
using std::string;

Capimon::~Capimon(){
    al_destroy_bitmap(capimon);
}

Capimon::Capimon(ALLEGRO_BITMAP *capimon, string treinadorPokemon){
    this->capimon = capimon;
    this->treinadorPokemon = treinadorPokemon;
    this->Vida = 100;
}

void Capimon::Mostrar_Capimon(){
    if(treinadorPokemon=="Capivaristo"){
        capimon = al_load_bitmap("img/pikachu.bmp");
        al_convert_mask_to_alpha(capimon, al_map_rgb(255,0,255));
        al_draw_bitmap(capimon, 200, 295, 0);
    }
    else if(treinadorPokemon=="Julio"){
        capimon = al_load_bitmap("img/charizard.bmp");
        al_convert_mask_to_alpha(capimon, al_map_rgb(255,0,255));
        al_draw_bitmap(capimon, 420, 120, 0);
    }
    else if(treinadorPokemon=="Andre"){
        capimon = al_load_bitmap("img/primeape.bmp");
        al_convert_mask_to_alpha(capimon, al_map_rgb(255,0,255));
        al_draw_bitmap(capimon, 400, 110, 0);
    }
}

const std::string *Capimon::get_habilidade(){
    return Habilidade;
}

int Capimon::Get_Vida(){
    return Vida;
}
