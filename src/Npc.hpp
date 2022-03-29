/* Npc.hpp */

/*
 * This class represents a character that isn't the player, the NPC. It is an independent being that can interact and battle with the player
 */

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
		Npc(std::string name, ALLEGRO_BITMAP *image, int x, int y, unsigned int quantity_of_interactions, std::string interaction_base_directory, std::string player_name);	// the order metter
		~Npc();
		bool can_interact(Position player_position);
		void draw_next_interaction(int reference_x, int reference_y);
		virtual Position get_CAPIMON_DRAW_POSITION() const;
    	virtual Position get_CAPIMON_STATUS_POSITION() const;
		void draw_npc();
};

#endif /* NPC_HPP */
