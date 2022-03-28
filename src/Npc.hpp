/* Npc.hpp */

#ifndef NPC_HPP
#define NPC_HPP

#include "Character.hpp"
#include "Interaction.hpp"

#include <queue>

class Npc : public Character {
	private:
		const Position CAPIMON_DRAW_POSITION = Position(420, 120);
		const Position CAPIMON_STATUS_POSITION = Position(14, 14);
		std::queue<Interaction*> _interactions;
	public:
		Npc(std::string name, ALLEGRO_BITMAP *image, int x, int y, std::string file_directory[]);	// the order metter
		~Npc();
		bool can_interact(Position player_position);
		void show_interaction();
		void draw_text(std::string name, std::string text);
		virtual Position get_CAPIMON_DRAW_POSITION();
      	virtual Position get_CAPIMON_STATUS_POSITION();
};

#endif /* NPC_HPP */
