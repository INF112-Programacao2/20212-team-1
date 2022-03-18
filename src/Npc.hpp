/* Npc.hpp */

#ifndef NPC_HPP
#define NPC_HPP

#include "Personagem.hpp"
#include "Interaction.hpp"

#include <vector>

class Npc : public Personagem {
	private:
		ALLEGRO_BITMAP *_dialog_image;
		std::vector<Interaction*> _interactions;
	public:
		Npc(std::string name, ALLEGRO_BITMAP *image, int x, int y, std::string file_directory[]);
		~Npc();
		bool interact(Position player_position);
		void show_interaction();
		void draw_text(std::string name, std::string text);
};

#endif /* NPC_HPP */
