#ifndef INF112_PERSONAGEM_HPP
#define INF112_PERSONAGEM_HPP

#include "Position.hpp"
#include "Object.hpp"

class Personagem : public Object{
    protected:
      std::string _name;
      // TODO: Adicionar vetor de Capimons
      //vector<*Capimon> _deck
    public:
    	// TODO: Incluir deck
		  Personagem(std::string name, ALLEGRO_BITMAP *image,int x, int y);
		  ~Personagem();

};
#endif
