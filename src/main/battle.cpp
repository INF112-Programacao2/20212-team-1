#include "../Battle.hpp"

int main() {
	al_init();
	al_init_image_addon();
	
	ALLEGRO_BITMAP *pi("../img/battle/pikachu.bmp")
	// TODO: Remove background
	
	Skill choque(0, "Choque do trovão", 10, 20);
	Skill cauda(1, "Cauda de ferro", 50, 120);
	Skill pena(2, "Pena de gaivota", 5, 10);
	Skill copo(3, "Copo de plástico", 175, 200);
	
	Capimon picachu("Picachu", pi, 350, {choque, cauda, pena, copo});
	return 0;
}
