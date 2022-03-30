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
        std::string _speak;	// fala do player
        std::string _answer;	// fala do npc
        std::string _player_name;	// nome do player
        std::string _npc_name;	// nome do npc
        void draw_dialog_box(int reference_x, int reference_y);	// desenha a caixa de diálogo (bitmap)
        void draw_text(int i,int reference_x, int reference_y);	// desenha o texto (pode ser _speak ou _answer)
	public:
		Dialog(std::string player_name, std::string speak, std::string npc_name, std::string answer);	// construtor
		~Dialog();	// destrutor
		std::string get_speak();	// retorna _speak
		std::string get_answer();	// retorna _answer
		std::string get_player_name();	// retorna o nome do player
		std::string get_npc_name();	// retorna o nome do npc
		void set_speak(std::string speak);	// altera _speak
		void set_answer(std::string answer);	// altera _answer
		void draw(int reference_x, int reference_y);	// desenha um diálogo na tela
};
#endif /* DIALOG_HPP */
