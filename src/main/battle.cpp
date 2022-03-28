#include "../Battle.hpp"
#include "../Position.hpp"
#include "../Object.hpp"
#include "../Character.hpp"
#include "../Player.hpp"
#include "../Capimon.hpp"
#include "../Npc.hpp"
#include "../Skill.hpp"

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
ALLEGRO_FONT *font = al_load_font("font.ttf", 11, 0);
ALLEGRO_FONT *fonteFinal = al_load_font("font.ttf", 30, 0);
ALLEGRO_SAMPLE *musica = NULL;
ALLEGRO_SAMPLE_INSTANCE *musicaInstancia = NULL;
ALLEGRO_BITMAP *background;
ALLEGRO_BITMAP *options;
ALLEGRO_BITMAP *capimonJulio;
ALLEGRO_BITMAP *capimonAndre;
ALLEGRO_BITMAP *capimonAliado;
ALLEGRO_BITMAP *seta;
ALLEGRO_BITMAP *vida;
ALLEGRO_BITMAP *bar;

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
    
    if(!al_is_font_addon_initialized())
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

    personagem = al_load_bitmap("../img/personagem1.bmp");
    if(!personagem)
    {
        std::cerr << "Falha ao carregar o personagem!" << std::endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }
    
    mapa = al_load_bitmap("../img/map.bmp");
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

    musica = al_load_sample("../audios/musica.ogg");
    musicaInstancia = al_create_sample_instance(musica);
    al_set_sample_instance_playmode(musicaInstancia, ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(musicaInstancia, al_get_default_mixer());
    
    

    return 1;
}

int main(int argc, char **argv){
    if(!inicializa()) return -1;
    
    al_init();
	al_init_image_addon();
	
	ALLEGRO_BITMAP *pi;
	pi = al_load_bitmap("../img/battle/pikachu.bmp");
	// TODO: Remove background
	
	Skill choque(0, "Choque do trovão", 10, 20);
	Skill cauda(1, "Cauda de ferro", 50, 120);
	Skill pena(2, "Pena de gaivota", 5, 10);
	Skill copo(3, "Copo de plástico", 175, 200);
	Skill hab[4] = {choque, cauda, pena, copo};

	
	Capimon picachu("Picachu", pi, 350, hab );
	Capimon picachu2("Picachu", pi, 350, hab );
	
	std::string falas[] = {"../file/Andre.txt"}; 

    Player capivaristo("Capivaristo", personagem,5, 6, 16, 16);
    capivaristo.add_capimon(&picachu);
    Npc Andre("Andre", personagem, 5, 6, falas );
    Andre.add_capimon(&picachu2);
    
    Map map("../img/walkable_map.pnm", mapa, 0, 0);
    Battle bat("../img/battle/TileBatalla.bmp");
    
    bat.start_battle(&capivaristo,&Andre);

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

    al_destroy_bitmap(mapa);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);

    return 0;
}

