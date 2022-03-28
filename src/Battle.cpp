/* Battle.cpp */

#include "Battle.hpp"

// TODO: Change construct to the easier way
Battle::Battle(std::string background_directory):
	_selected_display_skill(0,0), _cursor_position(30, 420) {
	this->_health_bar = al_load_bitmap("img/battle/health_bar.bmp");
	this->_colored_bar = al_load_bitmap("img/battle/colored_bar.bmp");
	this->_font = al_load_font("file/font.ttf", 11, 0);
	this->_background = al_load_bitmap(background_directory.c_str());
	this->_options = al_load_bitmap("img/battle/PlayerAttackBox.bmp");
	this->_cursor = al_load_bitmap("img/battle/cursor.bmp");
	
}

Battle::~Battle() {
	al_destroy_bitmap(this->_health_bar);
	al_destroy_bitmap(this->_colored_bar);
	al_destroy_font(this->_font);
	al_destroy_bitmap(this->_background);
	al_destroy_bitmap(this->_options);
	al_destroy_bitmap(this->_cursor);
}

// TODO: start_battle()
void Battle::start_battle(Player *hero , Npc *enemy) {
	bool exit = false;
	float fps = 5;
	bool redraw = true;
	bool pressed_enter = false;
	ALLEGRO_TIMER *timer = NULL;
	timer = al_create_timer(1.0 / fps);
	if(!timer){
        std::cerr << "Falha ao inicializar o temporizador" << std::endl;
        return;
  }
  
	hero->set_selected_capimon(0);
	enemy->set_selected_capimon(0);
	hero->get_selected_capimon()->set_selected_skill(0);
	enemy->get_selected_capimon()->set_selected_skill(0);

	
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	al_install_audio();
	al_init_acodec_addon();

	if(!al_is_font_addon_initialized()){
		  std::cerr << "Font Addon nao foi inicializado!" << std::endl;
	}

	//ALLEGRO_FONT *font = al_load_font("font.ttf", 11, 0);
	ALLEGRO_FONT *fonteFinal = al_load_font("file/font.ttf", 30, 0);	// TODO: Add this const in the class
	ALLEGRO_SAMPLE *musica = NULL;
	ALLEGRO_SAMPLE_INSTANCE *musicaInstancia = NULL;

	al_reserve_samples(10);

	musica = al_load_sample("audios/music.ogg");
	musicaInstancia = al_create_sample_instance(musica);
	al_set_sample_instance_playmode(musicaInstancia, ALLEGRO_PLAYMODE_LOOP);

	al_attach_sample_instance_to_mixer(musicaInstancia, al_get_default_mixer());



	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer)); //adicionando a contagem de tempo na fila
	al_start_timer(timer); //iniciando a contagem de tempo


	al_play_sample_instance(musicaInstancia);
	
	while(!exit){

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue,&ev);

		if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
        }

		
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
		switch(ev.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				exit = true;
				break;		          
			case ALLEGRO_KEY_LEFT:
				if (this->_selected_display_skill.get_x() > 0)
					this->_selected_display_skill.sub_x();
				verify_selected_display_skill(hero);
				break;
			case ALLEGRO_KEY_RIGHT:
				if (this->_selected_display_skill.get_x() < 1)
					this->_selected_display_skill.add_x();
				verify_selected_display_skill(hero);
				break;
			case ALLEGRO_KEY_UP:
				if (this->_selected_display_skill.get_y() > 0)
					this->_selected_display_skill.sub_y();
				verify_selected_display_skill(hero);
				
				break;
			case ALLEGRO_KEY_DOWN:
				if (this->_selected_display_skill.get_y() < 1)
					this->_selected_display_skill.add_y();
				verify_selected_display_skill(hero);
				break;
			case ALLEGRO_KEY_ENTER:
				// TODO: Create attack function
				pressed_enter = true;
				break;
    	}
  	}
		if(redraw && al_is_event_queue_empty(event_queue)){
			redraw = false;
			if(pressed_enter){
				pressed_enter = false;
				hero->get_selected_capimon()->decrement_health(enemy->get_selected_capimon()->get_selected_skill()->select_damage());
				enemy->get_selected_capimon()->decrement_health(hero->get_selected_capimon()->get_selected_skill()->select_damage());
			}
			al_draw_bitmap(_background, 0, 0, 0);
			al_draw_bitmap(_options,0,407,0);


			draw_capimon(hero);
			draw_capimon_status(hero);
			draw_capimon(enemy);
			draw_capimon_status(enemy);

			for(Skill skill : hero->get_selected_capimon()->get_skills())
				draw_skill(&skill);
			draw_cursor();


			if (there_is_a_looser(hero,enemy) && enemy->get_selected_capimon()->get_cur_health() == 0){
				al_clear_to_color(al_map_rgb(0,0,0));
				al_draw_text(fonteFinal, al_map_rgb(255,255,255), 140, 220, ALLEGRO_ALIGN_LEFT, "VOCÊ  FOI  APROVADO!!!!");
				al_flip_display();
				al_rest(5.0);
				exit = true;
				// Player ganhou, NPC perde
			} else if (there_is_a_looser(hero,enemy) && hero->get_selected_capimon()->get_cur_health() == 0)
			{
				al_clear_to_color(al_map_rgb(0,0,0));
				al_draw_text(fonteFinal, al_map_rgb(255,255,255), 140, 220, ALLEGRO_ALIGN_LEFT, "VOCÊ  FOI  REPROVADO!!!!");
				al_flip_display();
				al_rest(5.0);
				exit = true;
				// NPC ganhou, Player perde
			}
			al_flip_display();
		}
	}


	al_destroy_font(fonteFinal);
	al_destroy_sample(musica);
	al_destroy_sample_instance(musicaInstancia);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer); //destrutor para o tempo
	return;
}


// TODO: Creat draw_capimon()
void Battle::draw_capimon(Character *character) {
	Position draw_position = character->get_CAPIMON_DRAW_POSITION();
	al_convert_mask_to_alpha(character->get_selected_capimon()->get_image(), al_map_rgb(255,0,255));
	al_draw_bitmap(character->get_selected_capimon()->get_image(), draw_position.get_x(), draw_position.get_y(), 0);
}

void Battle::draw_capimon_status(Character *character){//alterar ainda
	Position status_position = character->get_CAPIMON_STATUS_POSITION();
	Capimon *selected_capimon = character->get_selected_capimon();
	
	al_convert_mask_to_alpha(this->_health_bar, al_map_rgb(255,0,255));
	al_draw_bitmap(_health_bar, status_position.get_x(), status_position.get_y(), 0);
	al_draw_text(this->_font, al_map_rgb(0,0,0), status_position.get_x() + 14.f, status_position.get_y() + 5.f, ALLEGRO_ALIGN_LEFT, selected_capimon->get_name().c_str() );
	al_draw_scaled_bitmap(this->_colored_bar, 0.f, 0.f, 18.f, 10.f, status_position.get_x() + 78.f, status_position.get_y() + 32.f, ((float)selected_capimon->get_cur_health() / (float)selected_capimon->get_max_health()) * 96.f, 10.f, 0);
}

void Battle::draw_cursor() { //draw cursor and capimon skills 

	al_convert_mask_to_alpha(_cursor, al_map_rgb(255,0,255));
  
  switch (this->_selected_display_skill.get_x()) {
  	case 0:
  		switch (this->_selected_display_skill.get_y()) {
  			case 0:
		  		this->_cursor_position.set_x(30);
  				this->_cursor_position.set_y(420);
  				break;
  			case 1:
		  		this->_cursor_position.set_x(30);
  				this->_cursor_position.set_y(450);
  				break;
  		}
  		break;
  	case 1:
  		switch (this->_selected_display_skill.get_y()) {
  			case 0:
  				this->_cursor_position.set_x(190);
  				this->_cursor_position.set_y(420);
  				break;
  			case 1:
  				this->_cursor_position.set_x(190);
  				this->_cursor_position.set_y(450);
  				break;
  		}
  		break;
  }
	
	al_draw_bitmap(_cursor, this->_cursor_position.get_x(), this->_cursor_position.get_y(), 0);

}

void Battle::draw_skill(Skill* skill) {
	
	int index = skill->get_index();
	
	al_draw_text(this->_font, al_map_rgb(0,0,0), (index == 0 || index == 1) ? 40 : 200, (index == 0 || index == 2) ? 420 : 450, ALLEGRO_ALIGN_LEFT, skill->get_name().c_str());	// TODO: Confirme ternary operator use 
	
}

bool Battle::there_is_a_looser(Player *hero, Npc *enemy) {

	return (hero->get_selected_capimon()->get_cur_health() == 0 || enemy->get_selected_capimon()->get_cur_health() == 0);
}

void Battle::verify_selected_display_skill(Character *character) {
// TODO: Confirm if the skills are correctly selected
	switch (this->_selected_display_skill.get_x()) {
		case 0:
			switch (this->_selected_display_skill.get_y()) {
				case 0:
					character->get_selected_capimon()->set_selected_skill(0);
					break;
				case 1:
					character->get_selected_capimon()->set_selected_skill(1);
					break;
			}
		case 1:
			switch (this->_selected_display_skill.get_y()) {
				case 0:
					character->get_selected_capimon()->set_selected_skill(2);
					break;
				case 1:
					character->get_selected_capimon()->set_selected_skill(3);
					break;
			}
	}
}

