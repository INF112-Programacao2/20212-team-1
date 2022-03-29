#include "HomeMenu.hpp"

HomeMenu::HomeMenu(std::string enderecoMenu1, std::string enderecoMenu2){
    menu1 = al_load_bitmap(enderecoMenu1.c_str());
    menu2 = al_load_bitmap(enderecoMenu2.c_str());
}

HomeMenu::~HomeMenu(){
    al_destroy_bitmap(menu1);
    al_destroy_bitmap(menu2);
}

void HomeMenu::initMenu(){
	bool exit = false;
	float fps = 2;
	bool redraw = true;
	ALLEGRO_TIMER *timer = nullptr;
	timer = al_create_timer(1.0 / fps);
	if(!timer){
        std::cerr << "Falha ao inicializar o temporizador" << std::endl;
        return;
    }
  	
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer)); //adicionando a contagem de tempo na fila
	al_start_timer(timer); //iniciando a contagem de tempo


	bool pisca = true;
    al_draw_bitmap(menu1,0,0,0);
	while(!exit){

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue,&ev);

		if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
        }

		
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
		switch(ev.keyboard.keycode) {
			case ALLEGRO_KEY_ENTER:
				// TODO: Create attack function
				exit = true;
				break;
    	    }
  	    }
		if(redraw && al_is_event_queue_empty(event_queue)){
			redraw = false;

            al_clear_to_color(al_map_rgb(0,0,0));

            //coloca a imagem do menu criando o efeito de piscar
            if(pisca){
                al_draw_bitmap(menu1,0,0,0);
                pisca=!pisca;

            }else{
                al_draw_bitmap(menu2,0,0,0);
                pisca=!pisca;
            }
			
			al_flip_display();
		}
	}

	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer); //destrutor para o tempo
	return;
}