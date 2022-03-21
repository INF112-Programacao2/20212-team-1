
#ifndef CAPIMON_HPP
#define CAPIMON_HPP

#include <allegro5/allegro.h>
#include <string>
using std::string;

class Capimon{
    public:
        Capimon(ALLEGRO_BITMAP *capimon, string treinadorPokemon, string habilidade1, string habilidade2, string habilidade3, string habilidade4);
        ~Capimon();
        void Mostrar_Capimon();
        void Mostrar_Capimon_Aliado();
        void Set_DanoCausado(int Dano);
        int Get_Ataque();
        int Get_Vida();
        void desenharHabilidades();
        string Habilidade[4];
        const string *get_habilidade();
    
    private:
        int Vida;
        int Ataque;
        string treinadorPokemon;
        ALLEGRO_BITMAP *capimon;
    
};

#endif