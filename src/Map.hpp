/* Map.hpp */

/*
 * This class represents the mapa, where the player can walk and make all the interactions with other beings
 */
//Classe para manipulação do mapa do jogo
#ifndef MAP_HPP
#define MAP_HPP

#include "Position.hpp"
#include "Object.hpp"

#include <fstream>

class Map : public Object{  //herda de Object, pois possui atributos comuns a outras classes como imagem e posição inicial
	private:
		int _width, _hight;	// width and hight
		unsigned char **_walkable;  //Matriz com informações do mapa 
		
	public:
		Map(std::string arquivo, ALLEGRO_BITMAP *image,int x, int y); //Construtor de Map
		~Map(); //Destrutor de map
		int get_width(); //Método obter a largura do Map
		int get_hight(); //Método para obter a altura do Map
		char get_val_walkable(int x, int y); //Método para saber o que está armazenado na matriz de informações do Map
		void draw_part(); //Metodo para realizar o desenho do Map na tela
};
#endif /* MAP_HPP */
