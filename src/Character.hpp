/* Personagem.hpp */

#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include "Position.hpp"
#include "Object.hpp"

#include <string>

class Personagem : public Object {
    protected:
      std::string _name;
      // TODO: Adicionar vetor de Capimons
      //vector<*Capimon> _deck
    public:
    	// TODO: Incluir deck
		  Personagem(std::string name, ALLEGRO_BITMAP *image,int x, int y);
		  ~Personagem();
		  std::string get_name();
};

#endif /* PERSONAGEM_HPP */
