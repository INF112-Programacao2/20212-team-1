/* Character.hpp */

/*
 * This class is an abstractition of the intersection between Player and NPC. Both classes have somethings in commum, because they all represents "people", but one controlled by the user and one not.
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Position.hpp"
#include "Object.hpp"
#include "Capimon.hpp"

#include <string>

// Maybe this is a abstract class, because it's impossible to exist an object of type Character
//Classe comum a Npc e Player, pois ambos carregam infomaçẽos comum de um personagem
class Character : public Object {
    protected:
      std::string _name; //Nome do personagem
      const int _tamPixels = 32; //tamanho em pixels utilizao como padrão as dimensões
      std::vector<Capimon*> _deck; //vetor do deck do pertonge
      Capimon* _selected_capimon = nullptr; //Capimon que será selecionado para realizar a batalha
    public:
		  Character(std::string name, /*std::string image_directory*/ALLEGRO_BITMAP *image, int x, int y); //Construtor da Classe Character
		  ~Character(); //Destrutor da classe Charater
		  const unsigned int AMOUNT_DECK = 4;
		  std::string get_name();
		  void add_capimon(Capimon *capimon); //Método para adicionar um Capimon ao deck de Character
      std::vector<Capimon*> get_deck(); //Método para retornar o deck de Capimons do Character
      void select_capimon(); //Método para selecionar um Capimon de maneira aleatória, tal método é utilizado para saber qual capimon usar na batalha
      Capimon* get_selected_capimon(); //Método para retornar o Capimon selecionado
      void set_selected_capimon(int index); //Método para selecionar um Capimon especifico, tal método é utilizado para saber qual capimon usar na batalha
      virtual Position get_CAPIMON_DRAW_POSITION() const = 0; //Método virtual que ira retornar a posição onde deve ser desenhado o Capimon, utilizado na batalha para desenhar nas posições certas
      virtual Position get_CAPIMON_STATUS_POSITION() const = 0;//Método virtual que ira retornar a posição onde deve ser desenhado o status Capimon, utilizado na batalha para desenhar nas posições certas
};
#endif /* CHARACTER_HPP */
