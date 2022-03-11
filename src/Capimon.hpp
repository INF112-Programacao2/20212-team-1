/* Capimon.hpp */

#ifndef CAPIMON_HPP
#define CAPIMON_HPP

#include "Object.hpp"

class Capimon : public Object{
    public:
        Capimon(int Tipo);
        ~Capimon();
        void Mostrar_Capimon();
        const void Acao();
        void Aliado();
        void Set_DanoCausado(int Dano);
        void Inimigo();
        int Get_Ataque();
        int Get_Vida();
        std::string Habilidade[4];
    
    private:
        int _Vida;
        int _Tipo;
        int _Ataque;
};

#endif /* CAPIMON_HPP */
