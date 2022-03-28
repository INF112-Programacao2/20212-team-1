/* Interaction.hpp */

/*
Documentation:
Cada NPC possui um conjunto de interações (entre 1 e +inf). A relação é feita a partir de uma lista de strings que contém o diretório de cada uma das interações (cada interação é armazenada em um arquivo).
TODO: Mudar a quantidade de interações por arquivo?
Cada interação é composta por uma conjunto de diálogos. Cada diálogo é composto por duas frases: a fala e a resposta. A fala é correspondente ao protagonista e a resposta é correspondente ao Npc. O arquivo de interação armazena a quantidade de diálogos (n) na primeira linha e seguem-se n linhas com cada um dos diálogos e seus respectivas fala e resposta. O nome do arquivo de interação é o nome do NPC correspondente à interação e o número da interação em ordem cronológica da ocorrência no jogo.
*/

#ifndef INTERACTION_HPP
#define INTERACTION_HPP

#include <string>

class Interaction {
	private:
		int _quantity_of_dialogs;
		std::string** _dialogs;
	public:
		Interaction(std::string file_directory);
		~Interaction();
		const int SIZE = 2;
		const int SPEAK = 0;
		const int ANSWER = 1;
		const char DELIMITER = '|';
		int get_quantity_of_dialogs();
		std::string* get_dialog(int n);
};

#endif /* INTERACTION_HPP */
