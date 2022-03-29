/* Dialog.cpp */

#include "Dialog.hpp"

#include <iostream>
#include <exception>

Dialog::Dialog(std::string player_name, std::string speak, std::string npc_name, std::string answer) :
	_player_name(player_name), _speak(speak), _npc_name(npc_name), _answer(answer) {};
	
Dialog::~Dialog() {}

std::string Dialog::get_speak() {
	return this->_speak;
}

std::string Dialog::get_answer() {
	return this->_answer;
}

std::string Dialog::get_player_name() {
	return this->_player_name;
}

std::string Dialog::get_npc_name() {
	return this->_npc_name;
}

void Dialog::set_speak(std::string speak) {
	this->_speak = speak;
}

void Dialog::set_answer(std::string answer) {
	this->_answer = answer;
}

void Dialog::draw_dialog_box() {
	if (!al_is_system_installed()) {
		std::cerr << "Allegro must be installed." << std::endl;
		throw std::exception();
	}
	
	if (!al_is_image_addon_initialized()) {
		std::cerr << "Image addon must be initialized." << std::endl;
		throw std::exception();
	}
		
	ALLEGRO_BITMAP* dialog_box = nullptr;
	dialog_box = al_load_bitmap("img/dialog/dialog_box.bmp");
	
	if (dialog_box == nullptr) {
		std::cerr << "It wasn't possible to load dialog_box.bmp." << std::endl;
		throw std::exception();
	}
		
	al_draw_bitmap(dialog_box, 0, 384, ALLEGRO_FLIP_HORIZONTAL);
	
	//al_destroy_bitmap(dialog_box);
}

void Dialog::draw_text(int i) {	// if i == 0 speak if i == 1 answer
	if (!al_is_system_installed()) {
		std::cerr << "Allegro must be installed." << std::endl;
		throw std::exception();
	}
	
	if (!al_is_font_addon_initialized()) {
		std::cerr << "Font addon must be initialized." << std::endl;
		throw std::exception();
	}
		
	if (!al_is_ttf_addon_initialized()) {
		std::cerr << "Ttf addon must be initialized." << std::endl;
		throw std::exception();
	}
		
	ALLEGRO_FONT* font = nullptr;
	font = al_load_font("file/font.ttf", 18, 0);
	
	if (font == nullptr) {
		std::cerr << "It wasn't possible to load font.ttf." << std::endl;
		throw std::exception();
	}
		
	al_draw_multiline_text(font, al_map_rgb(0, 0, 0), 20, 394, 604, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, (i == 0) ? this->_player_name.c_str() : this->_npc_name.c_str());
	al_draw_multiline_text(font, al_map_rgb(0, 0, 0), 20, 394 + al_get_font_line_height(font), 604, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, (i == 0) ? this->_speak.c_str() : this->_answer.c_str());
}

void Dialog::draw() {
	// TODO: Press N to next
	this->draw_dialog_box();
	this->draw_text(0);
	al_flip_display();	// TODO: Test flip display
	al_rest(5.0);
	this->draw_dialog_box();
	this->draw_text(1);
	al_flip_display();	// TODO: Test flip display
	al_rest(5.0);
}