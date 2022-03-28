#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "Battle.hpp"
#include "Position.hpp"
#include "Object.hpp"
#include "Character.hpp"
#include "Player.hpp"
#include "Capimon.hpp"
#include "Npc.hpp"
#include "Skill.hpp"

const float FPS = 5;
const int SCREEN_W = 640;
const int SCREEN_H = 480;



ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *personagem = NULL;


//variaveis para monitorar a camera



int inicializa() {
    if(!al_init())
    {
        std::cerr << "Falha ao carregar Allegro" << std::endl;
        return -1;
    }

    if(!al_install_keyboard())
    {
        std::cerr << "Falha ao inicializar o teclado" << std::endl;
        return -1;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        std::cerr << "Falha ao inicializar o temporizador" << std::endl;
        return -1;
    }

    if(!al_init_image_addon())
    {
        std::cerr <<"Falha ao iniciar al_init_image_addon!" << std::endl;
        return -1;
    }
    
    // if(!al_is_font_addon_initialized())
    // {
    //     std::cerr <<"Falha ao iniciar al_font_addon!" << std::endl;
    //     return -1;
    // }
    
    // if(!al_init_ttf_addon())
    // {
    //     std::cerr <<"Falha ao iniciar al_init_ttf_addon!" << std::endl;
    //     return -1;
    // }
    
    // if(!al_install_audio())
    // {
    //     std::cerr <<"Falha ao iniciar al_install_audio!" << std::endl;
    //     return -1;
    // }
    
    // if(!al_init_acodec_addon())
    // {
    //     std::cerr <<"Falha ao iniciar al_init_acodec_addon!" << std::endl;
    //     return -1;
    // }
    
    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        std::cerr << "Falha ao inicializar a tela" << std::endl;
        al_destroy_timer(timer);
        return -1;
    }

    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        std::cerr << "Falha ao criar a fila de eventos" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    personagem = al_load_bitmap("img/personagem1.bmp");
    if(!personagem)
    {
        std::cerr << "Falha ao carregar o personagem!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }
    

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);
    
    

    return 1;
}

int main(int argc, char **argv){
    al_init();
	al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    if(!inicializa()) return -1;
    
    al_init();
	al_init_image_addon();
	
	ALLEGRO_BITMAP *pi;
	pi = al_load_bitmap("img/battle/pikachu.bmp");
	// TODO: Remove background
	
	Skill choque(0, "Choque do trovão", 10, 20);
	Skill cauda(1, "Cauda de ferro", 50, 120);
	Skill pena(2, "Pena de gaivota", 5, 10);
	Skill copo(3, "Copo de plástico", 175, 200);
	Skill hab[] = {choque, cauda, pena, copo};

	
	Capimon picachu("Picachu", pi, 350, hab );
	Capimon picachu2("Picachu", pi, 350, hab );
	
	std::string falas[] = {"file/Andre.txt"}; 

    Player capivaristo("Capivaristo", personagem,5, 6, 16, 16);
    capivaristo.add_capimon(&picachu);
    Npc Andre("Andre", personagem, 5, 6, falas );
    Andre.add_capimon(&picachu2);
    
    Battle bat("img/battle/TileBatalla.bmp");
    
    bat.start_battle(&capivaristo,&Andre);

    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}

