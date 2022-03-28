#include <iostream>
#include <fstream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "Battle.hpp"
#include "Capimon.hpp"
#include "Character.hpp"
#include "Interaction.hpp"
#include "Map.hpp"
#include "Npc.hpp"
#include "Object.hpp"
#include "Player.hpp"
#include "Position.hpp"
#include "Skill.hpp"

const float FPS = 5;
const int SCREEN_W = 640; //tamanho horizontal da tela
const int SCREEN_H = 480; //tamanho vertical da tela

#define Pos_x_inicial 5 //posicao inicial em x do personagem
#define Pos_y_inicial 6 //posicao inicial em y do personagem
#define Tam_x_sprite 32 //tamanho em x de cada sprite do personagem
#define Tam_y_sprite 32 //tamanho em y de cada sprite do personagem

//Posicção dos Ncs no jogo
#define Pos_x_andre 5 //posicao inicial em x do personagem
#define Pos_y_andre 6 //posicao inicial em y do personagem
#define Pos_x_julio 5 //posicao inicial em x do personagem
#define Pos_y_julio 6 //posicao inicial em y do personagem
#define Pos_x_cantineira 5 //posicao inicial em x do personagem
#define Pos_y_cantineira 6 //posicao inicial em y do personagem
#define Pos_x_jacare 5 //posicao inicial em x do personagem
#define Pos_y_jacare 6 //posicao inicial em y do personagem

enum MYKEYS{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

//Arquivos base para rodar o programa allegro
ALLEGRO_DISPLAY *display = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_TIMER *timer = nullptr;

//variaveis para monitorar a camera do personagem
ALLEGRO_TRANSFORM camera;
int camera_x = 0;
int camera_y = 0;
int pos_x = 3;
int pos_y = 4;

bool key[4] = { false, false, false, false };
bool redraw = true;
bool sair = false;

//Criação das variaveis globais que irão armazenar Bitmaps de imagens
// exemplo: ALLEGRO_BITMAP *nomevariavel = nullptr;
ALLEGRO_BITMAP *personagem = nullptr;
ALLEGRO_BITMAP *mapa = nullptr;
ALLEGRO_BITMAP *pikachuBMP = nullptr;
ALLEGRO_BITMAP *blastoiseBMP = nullptr;
ALLEGRO_BITMAP *hitmonchanBMP = nullptr;
ALLEGRO_BITMAP *haunterBMP = nullptr;
ALLEGRO_BITMAP *arcanineBMP = nullptr;
ALLEGRO_BITMAP *andreBMP = nullptr;

//Variaveis para saber se os Npcs estão ativos ou não no mapa
bool ativaJulio = false;
bool ativaAndre = false;
bool ativaCantineira = false;
bool ativaJacare = false;

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
    
    if(!al_init_font_addon())
    {
        std::cerr <<"Falha ao iniciar al_font_addon!" << std::endl;
        return -1;
    }
    
    if(!al_init_ttf_addon())
    {
        std::cerr <<"Falha ao iniciar al_init_ttf_addon!" << std::endl;
        return -1;
    }
    
    if(!al_install_audio())
    {
        std::cerr <<"Falha ao iniciar al_install_audio!" << std::endl;
        return -1;
    }
    
    if(!al_init_acodec_addon())
    {
        std::cerr <<"Falha ao iniciar al_init_acodec_addon!" << std::endl;
        return -1;
    }
    
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

    //inicialização da variaveis do Bitmaps de imagem
    pikachuBMP = al_load_bitmap("img/Pikachu.bmp");
	if(!pikachuBMP)
    {
        std::cerr << "Falha ao carregar o Pikachu!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    blastoiseBMP = al_load_bitmap("img/Blastoise.bmp");
	if(!blastoiseBMP)
    {
        std::cerr << "Falha ao carregar o Blastoise!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    hitmonchanBMP = al_load_bitmap("img/Hitmonchan.bmp");
	if(!hitmonchanBMP)
    {
        std::cerr << "Falha ao carregar o Hitmonchan!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    haunterBMP = al_load_bitmap("img/Haunter.bmp");
	if(!haunterBMP)
    {
        std::cerr << "Falha ao carregar o Haunter!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }
	
    arcanineBMP = al_load_bitmap("img/DoguinhoDoRu.bmp");
    if(!arcanineBMP)
    {
        std::cerr << "Falha ao carregar o Arcanine!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

	andreBMP = al_load_bitmap("img/npc/oak.bmp");
    if(!andreBMP)
    {
        std::cerr << "Falha ao carregar o Andre!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    personagem = al_load_bitmap("img/personagem.bmp");
    if(!personagem)
    {
        std::cerr << "Falha ao carregar o personagem!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }
    
    mapa = al_load_bitmap("img/map1.bmp");
    if(!mapa)
    {
        std::cerr << "Falha ao carregar o mapa!" << std::endl;
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

    //al_reserve_samples(10);

    return 1;
}

int main(int argc, char **argv){

    if(!inicializa()) return -1;


	// Criação de um vetor de skils
	// Skill {PosicaoSkill, nomeSkill, danoMinimo, dano Maximo} chamada implícita do construtor

    //Pikachu
	Skill habA[] = {
		{ 0, "Choque do trovão", 10, 20 },
		{ 1, "Cauda de ferro", 50, 120 },
		{ 2, "Pena de gaivota", 5, 10},
		{ 3, "Copo de plástico", 175, 200 }
	};

    //Blastoise
	Skill habB[] = {
		{ 0, "Ataque intensificado", 8, 30 },
		{ 1, "Enxurrada", 45, 78 },
		{ 2, "Arma d'água", 18, 23},
		{ 3, "Surfar", 1, 23 }
	};

    //Arcanine
	Skill habC[] = {
		{ 0, "Golpe aéreo", 10, 20 },
		{ 1, "Lança chamas", 50, 120 },
		{ 2, "Fúria do dragão", 5, 10},
		{ 3, "Rajada de fogo", 175, 200 }
	};

    //Hitmonchan
	Skill habD[] = {
		{ 0, "Soco Cometa", 10, 20 },
		{ 1, "Soco Rápido", 50, 120 },
		{ 2, "Mega Soco", 5, 10},
		{ 3, "Punho Focus", 175, 200 }
	};

    //Haunter
	Skill habE[] = {
		{ 0, "Raio Confusão", 10, 20 },
		{ 1, "Esfera Obscura", 50, 120 },
		{ 2, "Ataque Hipnótico", 5, 10},
		{ 3, "Assustar", 175, 200 }
	};

    //Criação de Capimons
    //exemplo Capimon nomeCapimon("NomeCapimon", BitmapDaImagem, vida, array de Skills );
    Capimon pikachu("Pikachu", pikachuBMP, 350, habA);
    Capimon blastoise("Blastoise", blastoiseBMP, 400, habB);
    Capimon hitmonchan("Hitmonchan", hitmonchanBMP, 280, habC);
    Capimon haunter("Haunter", haunterBMP, 316, habD);
    Capimon arcanine("Arcanine", arcanineBMP, 300, habE);

    //Criação do player
    Player capivaristo("Capivaristo", personagem,Pos_x_inicial, Pos_y_inicial, Tam_x_sprite, Tam_y_sprite);

    //Criação dos arquivos de falas do Npcs
    //exemplo: std::string falas[] = {"file/Andre.txt"};
	std::string falas[] = { "file/Andre.txt" };
    
    //Criação dos Npcs
    //Exemplo: Npc nomeNpc("NomeNpc", BitmapDaImagem, posicao em x, posicao em y, Array com endereço dos arquivos de fala );
	Npc andre("Prof. Andre", andreBMP, 6*32, 7*32, falas); // TODO: review npc initial position int: x, y
    //Npc julio("Prof. Julio", , int{}, int{}, falas);
    //Npc jacare("Jacare da Vacina", , int{}, int{}, falas);
    //Npc cantineira("Tia da Cantina", , int{}, int{}, falas);

    //Atribuição dos Capimons aos charactes.
    //Exemplo: nomeCharaceter.add_capimon(&CapimonNome);
	capivaristo.add_capimon(&pikachu);
	andre.add_capimon(&hitmonchan);
	//cantineira.add_capimon(&haunter);
    // julio.add_capimon(&blastoise);
    // jacare.add_capimon(&arcanine);

    //Criação do mapa do jogo
    Map map("img/walkable_map.pnm", mapa, 0, 0);

    //Criação das batalhas
    Battle bat("img/battle/TileBatalla.bmp");
    //Inicialização da batalha
    //bat.start_battle(&Player,&Npc);
	bat.start_battle(&capivaristo, &andre);

    while(!sair){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                key[KEY_UP] = true;
                break;

            case ALLEGRO_KEY_DOWN:
                key[KEY_DOWN] = true;
                break;

            case ALLEGRO_KEY_LEFT:
                key[KEY_LEFT] = true;
                break;

            case ALLEGRO_KEY_RIGHT:
                key[KEY_RIGHT] = true;
                break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                key[KEY_UP] = false;
                break;

            case ALLEGRO_KEY_DOWN:
                key[KEY_DOWN] = false;
                break;

            case ALLEGRO_KEY_LEFT:
                key[KEY_LEFT] = false;
                break;

            case ALLEGRO_KEY_RIGHT:
                key[KEY_RIGHT] = false;
                break;

            case ALLEGRO_KEY_ESCAPE:
                sair = true;
                break;
            }
        }

        if(redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = false;
            

            al_clear_to_color(al_map_rgb(0,0,0));
            
            map.draw_part();

            if(key[KEY_UP])
            {
                if(capivaristo.walk(2, map)){
                   pos_y--; 
                }
            }else if(key[KEY_DOWN])
            {
                if(capivaristo.walk(0, map )){
                    pos_y++;
                }
            }else if(key[KEY_LEFT])
            {
                if(capivaristo.walk(1, map )){
                    pos_x--;
                }
            }else if(key[KEY_RIGHT])
            {
                if(capivaristo.walk(3, map)){
                    pos_x++;
                }
            }else{
                capivaristo.walk(-1,map);
            }

            if(pos_x < 0){
                pos_x = 0;
                camera_x--;
            }else if(pos_x > 15){
                pos_x = 15;
                camera_x++;
            }

            if(pos_y < 0){
                pos_y = 0;
                camera_y--;
            }else if(pos_y > 10){
                pos_y = 10;
                camera_y++;
            }
            al_identity_transform(&camera);
            al_translate_transform(&camera, -camera_x * 32, -camera_y * 32);
            al_use_transform(&camera);

            al_flip_display();
        }

    }

    //Destrutor para os Bitmaps das imagens
    //exemplo: al_destroy_bitmap(nome);

    al_destroy_bitmap(personagem);
	al_destroy_bitmap(pikachuBMP);
	al_destroy_bitmap(blastoiseBMP);
	al_destroy_bitmap(hitmonchanBMP);
	al_destroy_bitmap(haunterBMP);
	al_destroy_bitmap(arcanineBMP);
    al_destroy_bitmap(mapa);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
	// NOTE: it is not within this scope
    //al_destroy_font(font);

    return 0;
}
