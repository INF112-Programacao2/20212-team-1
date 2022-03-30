/* Interaction.hpp */

/*
Documentation:
Cada NPC possui um conjunto de interações (entre 1 e +inf). A relação é feita a partir de uma lista de strings que contém o diretório de cada uma das interações (cada interação é armazenada em um arquivo).
Cada interação é composta por uma conjunto de diálogos. Cada diálogo é composto por duas frases: a fala e a resposta. A fala é correspondente ao protagonista e a resposta é correspondente ao Npc. O arquivo de interação armazena a quantidade de diálogos (n) na primeira linha e seguem-se n linhas com cada um dos diálogos e seus respectivas fala e resposta. O nome do arquivo de interação é o nome do NPC correspondente à interação e o número da interação em ordem cronológica da ocorrência no jogo.
*/

#ifndef INTERACTION_HPP
#define INTERACTION_HPP

#include "Dialog.hpp"

#include <vector>

class Interaction {
	private:
		unsigned int _quantity_of_dialogs;	// quantidade de diálogos
		std::vector<Dialog> _dialogs;	// lista de diálogs
		static const char _DELIMITER = '|';	// delimitador de seperação de texto no arquivo da interação
	public:
		Interaction(std::string file_directory, std::string player_name, std::string npc_name);	// construtor
		~Interaction();	// destrutor
		unsigned int get_quantity_of_dialogs();	// retorna a quantidade de diálogos
		Dialog get_dialog(int i);	// retorna o diálogo na posição i da lista de diálogos
		char get_DELIMITER() const;	// retorna o delimitador de seperação de texto no arquivo da interação
		void draw(int reference_x, int reference_y);	// desenha uma interação na tela
};

#endif /* INTERACTION_HPP */
