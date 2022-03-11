/* Npc.cpp */

#include "Npc.hpp"

Npc::Npc(std::string name, ALLEGRO_BITMAP *image, int x, int y, ALLEGRO_BITMAP *dialog_image):
	Personagem(name, image, x, y), _dialog_image(dialog_image) {};
	
Npc::~Npc() {}
