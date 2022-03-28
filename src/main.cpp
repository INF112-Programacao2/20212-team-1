#include <iostream>
#include <fstream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "Batlle.hpp"
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
#define Tam_x_sprite 16 //tamanho em x de cada sprite do personagem
#define Tam_y_sprite 16 //tamanho em y de cada sprite do personagem

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

//Criação das variaveis globais que iram armazenar Bitmaps de imagens
// exemplo: ALLEGRO_BITMAP *nomevariavel = nullptr;
ALLEGRO_BITMAP *personagem = nullptr;
ALLEGRO_BITMAP *mapa = nullptr;


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
    
    // if(!al_font_addon_initialized())
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
    
    // if(!al_init_acodec_addon();)
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

    //inicialização da variaveis do Bitmaps de imagem
    
    /*exemplo
    nome = al_load_bitmap("enderco do diretori/nomeArquivo.bmp");
    if(!nome)
    {
        std::cerr << "Falha ao carregar o nome!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }
    */

    personagem = al_load_bitmap("img/personagem1.bmp");
    if(!personagem)
    {
        std::cerr << "Falha ao carregar o personagem!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }
    
    mapa = al_load_bitmap("img/map.bmp");
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

    al_reserve_samples(10);

    return 1;
}

int main(int argc, char **argv){

    if(!inicializa()) return -1;

    //Criação da skills dos capimons
    //exemplo: Skill nomeSkil (PosicaoSkill, nomeSkill, danoMinimo, dano Maximo)
    Skill choque(0, "Choque do trovão", 10, 20);
	Skill cauda(1, "Cauda de ferro", 50, 120);
	Skill pena(2, "Pena de gaivota", 5, 10);
	Skill copo(3, "Copo de plastico", 175, 200);

    //atribuição de um conjunto de skills em um array;
    //exemplo: Skill nomeVetorSkil[] = {skill1, skill2, skill3, skill4};
	Skill hab[] = {choque, cauda, pena, copo};

    //Criação de Capimons
    //exemplo Capimon nomeCapimon("NomeCapimon", BitmapDaImagem, vida, array de Skills );
    Capimon picachu("Picachu", pi, 350, hab );


    //Criação do player
    Player capivaristo("Capivaristo", personagem,Pos_x_inicial, Pos_y_inicial, Tam_x_sprite, Tam_y_sprite);

    //Criação dos arquivos de falas do Npcs
    //exemplo: std::string falas[] = {"file/Andre.txt"};
    
    //Criação dos Npcs
    //Exemplo: Npc nomeNpc("NomeNpc", BitmapDaImagem, posicao em x, posicao em y, Array com endereço dos arquivos de fala );

    //Atribuição dos Capimons aos charactes.
    //Exemplo: nomeCharaceter.add_capimon(&CapimonNome);


    //Criação do mapa do jogo
    Map map("img/walkable_map.pnm", mapa, 0, 0);

    //Criação das batalhas
    Battle bat("img/battle/TileBatalla.bmp");
    //Inicialização da batalha
    //bat.start_battle(&Player,&Npc);

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
                if(capivaristo.walk(1, map)){
                   pos_y--; 
                }
            }else if(key[KEY_DOWN])
            {
                if(capivaristo.walk(0, map )){
                    pos_y++;
                }
            }else if(key[KEY_LEFT])
            {
                if(capivaristo.walk(2, map )){
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
            }else if(pos_x > 34){
                pos_x = 34;
                camera_x++;
            }

            if(pos_y < 0){
                pos_y = 0;
                camera_y--;
            }else if(pos_y > 24){
                pos_y = 24;
                camera_y++;
            }
            al_identity_transform(&camera);
            al_translate_transform(&camera, -camera_x * 16, -camera_y * 16);
            al_use_transform(&camera);

            al_flip_display();
        }

    }

    //Destrutor para os Bitmaps das imagens
    //exemplo: al_destroy_bitmap(nome);

    al_destroy_bitmap(personagem);
    al_destroy_bitmap(mapa);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);

    return 0;
}
