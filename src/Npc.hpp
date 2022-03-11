/* Npc.hpp */

#ifndef NPC_HPP
#define NPC_HPP

#include "Interaction.hpp"
#include <vector>

class Npc : Personagem {
	private:
		ALLEGRO_BITMAP *_dialog_image;
		std::vector _interactions;
	public:
		Npc(std::string name, ALLEGRO_BITMAP *image, int x, int y, ALLEGRO_BITMAP *dialog_image);
		~Npc();
};

#endif /* NPC_HPP */
