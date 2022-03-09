/* Map.hpp */

#ifndef INF112_MAP_HPP
#define INF12_MAP_HPP

#include "object.hpp"
#include <fstream>

class Map : public Object {
	private:
		int _width, _hight;	// width and hight
		unsigned char **_walkable;
		
	public:
		Map(std::string arquivo, ALLEGRO_BITMAP *image,int x, int y);
		~Map();
		int get_width();
		int get_hight();
		char get_val_walkable(int x, int y);
		void draw_part();		
};

#endif /* MAP_HPP */
