/* PlayerAttack.cpp */

#include "PlayerAttack.hpp"
#include <cstdlib>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>

PlayerAttack::PlayerAttack() 
    : _selected()
{ }

// void PlayerAttack::set_habilidades(const std::string *hl)
// {
// 	this->m_attacks = hl;
// }

void PlayerAttack::draw(ALLEGRO_FONT *font, ALLEGRO_BITMAP *seta)
{
    seta = al_load_bitmap("img/Cursor.bmp");
    al_convert_mask_to_alpha(seta, al_map_rgb(255,0,255));
    //al_draw_bitmap(seta, 420, 120, 0);
    switch (_selected)
    {
    case 0: // CHOQUE DO TROVÃO
        al_draw_bitmap(seta, 30, 420, 0);
        break;
    case 1: // Choque d
        al_draw_bitmap(seta, 30, 450, 0);
        break;
    case 2: // Choque do 
        al_draw_bitmap(seta, 190, 420, 0);
        break;
    case 3: // Choque do 
        al_draw_bitmap(seta, 190, 450, 0);
        break;
    // default:
    //     break;
    }

    al_draw_text(font, al_map_rgb(0,0,0), 40, 420, ALLEGRO_ALIGN_LEFT, "CHOQUE DO TROVÃO (3)"); // 0
    al_draw_text(font, al_map_rgb(0,0,0), 40, 450, ALLEGRO_ALIGN_LEFT, "ATAQUE RÁPIDO (1)"); // 1
    al_draw_text(font, al_map_rgb(0,0,0), 200, 420, ALLEGRO_ALIGN_LEFT, "INVESTIDA DO TROVÃO (5)"); // 2
    al_draw_text(font, al_map_rgb(0,0,0), 200, 450, ALLEGRO_ALIGN_LEFT, "CAUDA DE FERRO (9)"); // 3
}

int PlayerAttack::ataqueInimigo()
{
	int i = rand() % 4;
	switch (i)
	{
	case 0:
		return 3;
		break;
	case 1:
		return 6;
		break;
	case 2:
		return 5;
		break;
	case 3:
		return 9;
		break;
	default:
		return -1;
	}
}

void PlayerAttack::selectAttack(int key)
{
 	switch (key)
 	{
 	case ALLEGRO_KEY_LEFT:
 		switch (_selected)
 		{
 		case 2:
 			_selected = 0;
 			break;
 		case 3:
 			_selected = 1;
 			break;
 		default:
			break;
		}
		break;
	case ALLEGRO_KEY_RIGHT:
		switch (_selected)
		{
		case 0:
			_selected = 2;
			break;
		case 1:
			_selected = 3;
			break;
		default:
			break;
		}
		break;
	case ALLEGRO_KEY_UP:
		switch (_selected)
		{
		case 1:
			_selected = 0;
			break;
		case 3:
			_selected = 2;
			break;
		default:
			break;
		}
		break;
	case ALLEGRO_KEY_DOWN:
		switch (_selected)
		{
		case 0:
			_selected = 1;
			break;
		case 2:
			_selected = 3;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

int PlayerAttack::do_attack()
{
	switch (_selected)
	{
	case 0:
		return 3;
		break;
	case 1:
		return 1;
		break;
	case 2:
		return 5;
		break;
	case 3:
		return 9;
		break;
	default:
		return -1;
	}
}
// void PlayerAttack::get_habilidades(){
    
// }
