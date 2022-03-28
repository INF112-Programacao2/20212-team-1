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
		const Position CAPIMON_DRAW_POSITION = Position(200, 295);
		const Position CAPIMON_STATUS_POSITION = Position(420, 350);
		const int _numSprites = 4;
		const int _tamPixels = 16;
		int _direcao_anterior;
		int _numPasso;
		int _tam_x;
		int _tam_y;
  public:
  	Player(std::string name, ALLEGRO_BITMAP *image,int x, int y, int tam_x, int tam_y);
    ~Player();
    bool walk(int direcao, Map &mapa);
    void interact(Npc *npc);
		virtual Position get_CAPIMON_DRAW_POSITION() const;
    virtual Position get_CAPIMON_STATUS_POSITION() const;
};

#endif /* PLAYER_HPP */
