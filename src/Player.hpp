/* Player.hpp */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Object.hpp"
#include "Position.hpp"
#include "Map.hpp"
#include "Character.hpp"
#include "Npc.hpp"

class Player : public Character{
  private:
	const Position CAPIMON_DRAW_POSITION = Position(200, 295);
	const Position CAPIMON_STATUS_POSITION = Position(420, 350);
	static int _numSprites;
	static int _tamPixels;
	int _direcao_anterior;
	int _numPasso;
	int _tam_x;
	int _tam_y;
  public:
    Player(std::string name, ALLEGRO_BITMAP *image,int x, int y, int tam_x, int tam_y);
    ~Player();
    bool walk(int direcao, Map &mapa);
    void interact(Npc *npc);
	virtual Position get_CAPIMON_DRAW_POSITION();
    virtual Position get_CAPIMON_STATUS_POSITION();
};
#endif /* PLAYER_HPP */
