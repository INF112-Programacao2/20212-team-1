#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <fstream>

#include "Position.hpp"
#include "Object.hpp"
#include "Personagem.hpp"
#include "Player.hpp"
//s#include "Map.hpp"

using namespace std;

const float FPS = 5;
const int SCREEN_W = 640;
const int SCREEN_H = 480;

enum MYKEYS
{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};


ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *personagem = NULL;
ALLEGRO_BITMAP *mapa = NULL;

//variaveis para monitorar a camera
ALLEGRO_TRANSFORM camera;
int camera_x = 0;
int camera_y = 0;
int pos_x = 3;
int pos_y = 4;

bool key[4] = { false, false, false, false };
bool redraw = true;
bool sair = false;

int inicializa() {
    if(!al_init())
    {
        cout << "Falha ao carregar Allegro" << endl;
        return 0;
    }

    if(!al_install_keyboard())
    {
        cout << "Falha ao inicializar o teclado" << endl;
        return 0;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        cout << "Falha ao inicializar o temporizador" << endl;
        return 0;
    }

    if(!al_init_image_addon())
    {
        cout <<"Falha ao iniciar al_init_image_addon!" << endl;
        return 0;
    }

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        cout << "Falha ao inicializar a tela" << endl;
        al_destroy_timer(timer);
        return 0;
    }


    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        cout << "Falha ao criar a fila de eventos" << endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return 0;
    }

    personagem = al_load_bitmap("img/personagem1.bmp");
    if(!personagem)
    {
        cout << "Falha ao carregar o personagem!" << endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return 0;
    }
    
    mapa = al_load_bitmap("img/map.bmp");
    if(!mapa)
    {
        cout << "Falha ao carregar o mapa!" << endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return 0;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

    return 1;
}

int main(int argc, char **argv)
{
    if(!inicializa()) return -1;

    Player capivaristo("Capivaristo", personagem,5, 6, 16, 16);
    Map map("img/walkable_map.pnm", mapa, 0, 0);

    while(!sair)
    {
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

    al_destroy_bitmap(personagem);
    al_destroy_bitmap(mapa);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}
