/* Capimon.cpp */

#include "Capimon.hpp"

int Capimon::AMOUNT_SKILLS = 4;
float Capimon::_x_bar_npc = 14;
float Capimon::_y_bar_npc = 14;
float Capimon::_x_bar_player = 420;
float Capimon::_y_bar_player = 350;

Capimon::Capimon(string name, ALLEGRO_BITMAP *image, int maxHealth, Skill skills[AMOUNT_SKILLS]){
	this->_name = name;
	this->_image = image;
	this->_maxHealth = maxHealth;
	_life_bar = al_load_bitmap("img/battle/Vida.bmp");
	_colorBar = al_load_bitmap("img/battle/Bar.bmp");
	_font = al_load_font("file/font.ttf", 11, 0);
	
	for (int i = 0; i < this->AMOUNT_SKILLS; i++)
		this->_skills[i] = skills[i];
}

Capimon::~Capimon(){
    //al_destroy_bitmap(this->_image);
	al_destroy_bitmap(_life_bar);
	al_destroy_bitmap(_colorBar);
	al_destroy_font(_font);
}

std::string Capimon::get_name() {
	return this->_name;
}

int Capimon::get_maxHealth() {
	return this->_maxHealth;
}

void Capimon::show_capimonPlayer(){
	al_convert_mask_to_alpha(this->_image, al_map_rgb(255,0,255));
	al_draw_bitmap(this->_image, 200, 295, 0); 	//the position is changed if it's a player or and NPC
}

void Capimon::show_capimonNpc(){
	al_convert_mask_to_alpha(this->_image, al_map_rgb(255,0,255));
	al_draw_bitmap(this->_image, 200, 295, 0); 	//the position is changed if it's a player or and NPC 
	//alterar posicao da imagem
}

//funcoes que eram da capimonStatus
void Capimon::decrementHealth(int dano){
	_curHealth -= dano;
	if (_curHealth <= 0)
		_curHealth = 0;
}

bool Capimon::looser(){
	return _curHealth == 0;
}

void Capimon::draw_Status_Player(){
	al_convert_mask_to_alpha(_life_bar, al_map_rgb(255,0,255));
	al_draw_bitmap(_life_bar, _x_bar_player, _y_bar_player, 0);
	al_draw_text(_font, al_map_rgb(0,0,0), _x_bar_player + 14.f, _y_bar_npc + 5.f, ALLEGRO_ALIGN_LEFT, c_str(this->_name));
	al_draw_scaled_bitmap(_colorBar, 0.f, 0.f, 18.f, 10.f, _x_bar_player + 78.f, _y_bar_player + 32.f, ((float)_curHealth / (float)_maxHealth) * 96.f, 10.f, 0);
}

void Capimon::draw_Status_NPC(){
	al_convert_mask_to_alpha(_life_bar, al_map_rgb(255,0,255));
	al_draw_bitmap(_life_bar, _x_bar_npc, _y_bar_npc, 0);
	al_draw_text(_font, al_map_rgb(0,0,0), _x_bar_npc + 14.f, _y_bar_npc + 5.f, ALLEGRO_ALIGN_LEFT, c_str(this->_name));
	al_draw_scaled_bitmap(_colorBar, 0.f, 0.f, 18.f, 10.f, _x_bar_npc + 78.f, _y_bar_npc + 32.f, ((float)_curHealth / (float)_maxHealth) * 96.f, 10.f, 0);
}