/* Dialog.hpp */

#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <string>

class Dialog {
	private:
		std::string _speak;
		std::string _answer;
		std::string _player_name;
		std::string _npc_name;
		
		void draw_dialog_box();
		void draw_text(int i);
	public:
		Dialog(std::string player_name, std::string speak, std::string npc_name, std::string answer);
		~Dialog();
		std::string get_speak();
		std::string get_answer();
		std::string get_player_name();
		std::string get_npc_name();
		void set_speak(std::string speak);
		void set_answer(std::string answer);
		
		void draw();
};

#endif /* Dialog_HPP */