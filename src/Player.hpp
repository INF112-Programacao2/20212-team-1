/* Player.hpp */

/*
 * This class represent the player of the game, allowing the user to control the position of the play with the keyboard and make interactions with NPC's
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Position.hpp"
#include "Object.hpp"
#include "Map.hpp"
#include "Character.hpp"
#include "Npc.hpp"

class Player : public Character{
  private:
		const Position CAPIMON_DRAW_POSITION = Position(200, 295); //Posição onde será desenhado o capimon do player
		const Position CAPIMON_STATUS_POSITION = Position(420, 350); //Posição onde será desenhado o status do capimon do player
		const int _numSprites = 4; // Numero de sprites por linha que serão utilizados para causar a sensação de movimento
		int _direcao_anterior; // variavel para saber a direção que o player tinha ido anteriormente, utilizada para fazer a animação dele andando
		int _numPasso; //Variável para saber qual passo vai dar 
		int _tam_x; //tamanho em x do personagem em pixels
		int _tam_y; //tamanho em y do personagem em pixels
  public:
  	Player(std::string name, ALLEGRO_BITMAP *image,int x, int y, int tam_x, int tam_y); //Construtor de Player
    ~Player(); //Destrutor de Player
    bool walk(int direcao, Map &mapa); //Método para fazer o personagem andar e realiza a animação disso na tela, retorna um bool informando se foi possível ou não, ela utiliza uma mapa para saber onde pode andar
    void interact(Npc *npc);
	virtual Position get_CAPIMON_DRAW_POSITION() const; //Método para obter a posição onde o capimon do player vai ser desenhado
    virtual Position get_CAPIMON_STATUS_POSITION() const; //Método para obter a posição onde o status do capimon do player vai ser desenhado
};

#endif /* PLAYER_HPP */
