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
		const Position CAPIMON_DRAW_POSITION = Position(420, 120);	// posição de desenho de um Capimon na tela de batalha
		const Position CAPIMON_STATUS_POSITION = Position(14, 14);	// posição de desenho da barra de status de um Capimon na tela de batalha
		std::queue<Interaction*> _interactions;	// pilha de interações
	public:
		Npc(std::string name, ALLEGRO_BITMAP *image, int x, int y, unsigned int quantity_of_interactions, std::string interaction_base_directory, std::string player_name);	// construtor
		~Npc();	// destrutor
		bool can_interact(Position player_position);	// retorna verdadeiro caso o Npc possa interagir com um player a partir da posição e falso caso contrário
		void draw_next_interaction(int reference_x, int reference_y);	// desenha a próxima interação da pilha de interações
		virtual Position get_CAPIMON_DRAW_POSITION() const;	// retorna a posição de desenho de um Capimon na tela de batalha
    	virtual Position get_CAPIMON_STATUS_POSITION() const;	// retorna a posição de desenho da barra de status de um Capimon na tela de batalha
		void draw_npc();	// desenha o Npc na tela
};

#endif /* NPC_HPP */
