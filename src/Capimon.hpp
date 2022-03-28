/* Capimon.hpp */

/*
 * This class represents an special pet from a Character, this pet is used in battle with NPC's.
 */
//Classe que representa as criatura de batalha do jogo

#ifndef CAPIMON_HPP
#define CAPIMON_HPP

#include "Object.hpp"
#include "Skill.hpp"

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include <string>
#include <vector>

class Capimon : public Object {
	private:
		std::string _name; //nome do capimon
		int _max_health; //quantidade máxima de vida do capimon
		int _cur_health; //quantidade de vida atual do capimon
		std::vector<Skill> _skills; // vector com as Skills (habilidades) do capimon
		Skill* _selected_skill; //Skill selecionada no momento 
  public:
		Capimon(std::string name, /*std::string image_directory*/ALLEGRO_BITMAP *image, /*int x, int y,*/ int max_health, Skill skills[]); //Construtor de Capimon
		~Capimon(); //Destruto de Capimon
		const int AMOUNT_SKILLS = 4;
		std::string get_name(); //Método para retorna o nome do Capimon
		int get_max_health(); //Método para retorna a quantidade máxima de vida do capimon
		int get_cur_health(); //Método para retonnar a quantidade atual de vida do capimon 
		std::vector<Skill> get_skills(); //Método para retorna o Vetor de habilidades do Capimon
		Skill get_skill(int index); //Método para obter uma Skill especifica do capimon
		void select_skill(); //Método para selecionar uma Skill aleatorio do capimon e colocar na variavel _selected_skill
		Skill* get_selected_skill(); //Método para obter o endereço de memória de de _selected_skill 
		void set_selected_skill(Skill *selected_skill);//Método para atribuir uma Skill passada como argumento para _selected_skill 
		void set_selected_skill(int index); //Método para selecionar uma skill especifica do capimon de acordo o indice passado e atribuir ela a _selected_skill 
		void decrement_health(int damage); //Método para decrementar a vida atual do capimon de acordo com o dano passado
		void heal_health(); //Método para curar o capimon (Colocar a vida atual dele como sendo a máxima de novo)
};

#endif /* CAPIMON_HPP */
