/* Npc.hpp */

#ifndef NPC_HPP
#define NPC_HPP

#include "Character.hpp"
#include "Interaction.hpp"

#include <queue>

class Npc : public Character {
	private:
		std::queue<Interaction*> _interactions;
	public:
		Npc(std::string name, ALLEGRO_BITMAP *image, int x, int y, std::string file_directory[]);	// the order metter
		~Npc();
		bool can_interact(Position player_position);
		void show_interaction();
		void draw_text(std::string name, std::string text);
};

#endif /* NPC_HPP */
