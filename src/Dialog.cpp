/* Dialog.cpp */

#include "Dialog.hpp"

#include <iostream>
#include "AllegroSystemError.hpp"
#include "AllegroImageAddonError.hpp"
#include "AllegroFontAddonError.hpp"
#include "AllegroTTFAddonError.hpp"

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

void Dialog::draw_dialog_box(int reference_x, int reference_y) {
	if (!al_is_system_installed()) {
		throw allegro_system_error();
	}
	
	if (!al_is_image_addon_initialized()) {
		throw allegro_image_addon_error();
	}
		
	ALLEGRO_BITMAP* dialog_box = nullptr;
	dialog_box = al_load_bitmap("img/dialog/dialog_box.bmp");
	
	if (dialog_box == nullptr) {
		std::cerr << "It wasn't possible to load dialog_box.bmp." << std::endl;
		throw std::exception();
	}
		
	al_draw_bitmap(dialog_box, reference_x, reference_y + 384, ALLEGRO_FLIP_HORIZONTAL);
	
	//al_destroy_bitmap(dialog_box);
}

void Dialog::draw_text(int i, int reference_x, int reference_y) {	// if i == 0 speak if i == 1 answer
	if (!al_is_system_installed()) {
		throw allegro_system_error();
	}
	
	if (!al_is_font_addon_initialized()) {
		throw allegro_font_addon_error();
	}
		
	if (!al_is_ttf_addon_initialized()) {
		throw allegro_ttf_addon_error();
	}
		
	ALLEGRO_FONT* font = nullptr;
	font = al_load_font("file/font.ttf", 18, 0);
	
	if (font == nullptr) {
		std::cerr << "It wasn't possible to load font.ttf." << std::endl;
		throw std::exception();
	}
		
	al_draw_multiline_text(font, al_map_rgb(0, 0, 0), reference_x + 20, reference_y + 394, 604, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, (i == 0) ? this->_player_name.c_str() : this->_npc_name.c_str());
	al_draw_multiline_text(font, al_map_rgb(0, 0, 0), reference_x + 20, reference_y + 394 + al_get_font_line_height(font), 604, al_get_font_line_height(font), ALLEGRO_ALIGN_LEFT, (i == 0) ? this->_speak.c_str() : this->_answer.c_str());
}

void Dialog::draw(int reference_x, int reference_y) {
	// TODO: Press N to next
	this->draw_dialog_box(reference_x, reference_y);
	this->draw_text(0,reference_x, reference_y);
	al_flip_display();	// TODO: Test flip display
	al_rest(2.5);
	this->draw_dialog_box(reference_x, reference_y);
	this->draw_text(1,reference_x, reference_y);
	al_flip_display();	// TODO: Test flip display
	al_rest(2.5);
}
