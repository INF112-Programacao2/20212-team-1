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

	

	//ALLEGRO_DISPLAY *display = NULL; //rever isso, pois já existe uma tela criada
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	//ALLEGRO_BITMAP *background;
	//ALLEGRO_BITMAP *options;
	//ALLEGRO_BITMAP *selector;
	//ALLEGRO_BITMAP *bar;
	
	/* Fixo */
	//background = al_load_bitmap("img/battle/TileBatalla.bmp");
	//options = al_load_bitmap("img/battle/PlayerAttackBox.bmp");

	/*
	//Inicio do programa
	if(!al_init())
		  return -1;
	*/
	
	/*
	display = al_create_display(SCREEN_W,SCREEN_H);

	if(!display)
		  return -1;
	*/

	// TODO: Check if there is somethig repeated
	//al_init_font_addon();
	//al_init_ttf_addon();
	//al_install_keyboard();
	//al_init_image_addon();
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

	//Capimon Capivaristo(capimonAliado, "Capivaristo");
	//PlayerAttack a;

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer)); //adicionando a contagem de tempo na fila
	al_start_timer(timer); //iniciando a contagem de tempo
	//Capimon Julio(capimonJulio, "Julio");

	//CapimonStatus Jul(Julio.Get_Vida(), 14.f, 14.f);
	//CapimonStatus Cap(Capivaristo.Get_Vida(), 420.f, 350.f);

	//Capimon Andre(capimonAndre, "Andre");

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
				draw_cursor();
				break;
			case ALLEGRO_KEY_RIGHT:
				if (this->_selected_display_skill.get_x() < 1)
					this->_selected_display_skill.add_x();
				verify_selected_display_skill(hero);
				draw_cursor();
				break;
			case ALLEGRO_KEY_UP:
				if (this->_selected_display_skill.get_y() > 0)
					this->_selected_display_skill.sub_y();
				verify_selected_display_skill(hero);
				draw_cursor();
				break;
			case ALLEGRO_KEY_DOWN:
				if (this->_selected_display_skill.get_y() < 1)
					this->_selected_display_skill.add_y();
				verify_selected_display_skill(hero);
				draw_cursor();
				break;
			case ALLEGRO_KEY_ENTER:
				// TODO: Create attack function
				pressed_enter = true;
				break;
    	}
  	}
		if(redraw && al_is_event_queue_empty(event_queue)){
			redraw = false;
			//int i=1;
			if(pressed_enter){
				pressed_enter = false;
				hero->get_selected_capimon()->decrement_health(enemy->get_selected_capimon()->get_selected_skill()->select_damage());
				enemy->get_selected_capimon()->decrement_health(hero->get_selected_capimon()->get_selected_skill()->select_damage());
			}
			//al_play_sample_instance(musicaInstancia);
			al_draw_bitmap(_background, 0, 0, 0);
			al_draw_bitmap(_options,0,407,0);

			//a.draw(font, selector);
			//Jul.draw("CHARIZARD",vida,bar,font);
			//draw_npc_status(selected_npc_capimon);
			//Cap.draw("PIKACHU",vida,bar,font);
			//draw_player_status(selected_player_capimon);

			draw_capimon(hero);
			draw_capimon_status(hero);
			draw_capimon(enemy);
			draw_capimon_status(enemy);

			for(Skill skill : hero->get_selected_capimon()->get_skills())
				draw_skill(&skill);
			
			draw_cursor();

			//   Capivaristo.Mostrar_Capimon();
			//   if(i==1){
			//       Julio.Mostrar_Capimon();
			//   }
			//   else{
			//       Andre.Mostrar_Capimon();
			//   }

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

	//al_destroy_bitmap(background);
	al_destroy_font(fonteFinal);
	//al_destroy_font(font);
	//al_destroy_bitmap(options);
	// al_destroy_bitmap(capimonJulio);
	// al_destroy_bitmap(capimonAndre);
	// al_destroy_bitmap(capimonAliado);
	//al_destroy_bitmap(selector);
	al_destroy_sample(musica);
	//al_destroy_bitmap(bar);
	// al_destroy_bitmap(vida);
	al_destroy_sample_instance(musicaInstancia);
	al_destroy_event_queue(event_queue);
	//al_destroy_display(display);
	al_destroy_timer(timer); //destrutor para o tempo
	return;
}


// TODO: Creat draw_capimon()
void Battle::draw_capimon(Character *character) {
	//character->get_select_capimon();
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


/*
void Battle::draw_player_capimon(Capimon *capimon){ //alterar para pegar a imagem do capimon certo
	al_convert_mask_to_alpha(capimonPlayer->get_image(), al_map_rgb(255,0,255));
	al_draw_bitmap(capimonPlayer->get_image(), 200, 295, 0); 	// TODO: Add right values in image position
}

void Battle::draw_npc_capimon(Capimon *capimon){ //alterar para pegar a imagem do capimon certo
	al_convert_mask_to_alpha(capimonNpc->get_image(), al_map_rgb(255,0,255));
	al_draw_bitmap(capimonNpc->get_image(), 200, 295, 0); 	// TODO: Add right values in image position (considering this is an Capimon's NPC)
}
*/

/*
void Battle::draw_player_status(Capimon *capimon){ //alterar ainda
	al_convert_mask_to_alpha(this->_health_bar, al_map_rgb(255,0,255));
	al_draw_bitmap(this->_health_bar, this->_x_bar_player, this->_y_bar_player, 0);
	al_draw_text(this->_font, al_map_rgb(0,0,0), this->_x_bar_player + 14.f, this->_y_bar_player + 5.f, ALLEGRO_ALIGN_LEFT, c_str(capimonPlayer->get_name()));
	al_draw_scaled_bitmap(this->_colored_bar, 0.f, 0.f, 18.f, 10.f, this->_x_bar_player + 78.f, this->_y_bar_player + 32.f, ((float)capimonPlayer->get_cur_health() / (float)capimonPlayer->get_max_health()) * 96.f, 10.f, 0);
}

void Battle::draw_npc_status(Capimon *capimon){//alterar ainda
	al_convert_mask_to_alpha(this->_health_bar, al_map_rgb(255,0,255));
	al_draw_bitmap(this->_health_bar, this->_x_bar_npc, this->_y_bar_npc, 0);
	al_draw_text(this->_font, al_map_rgb(0,0,0), this->_x_bar_npc + 14.f, this->_y_bar_npc + 5.f, ALLEGRO_ALIGN_LEFT, c_str(capimonNpc->get_name()));
	al_draw_scaled_bitmap(this->_colored_bar, 0.f, 0.f, 18.f, 10.f, this->_x_bar_npc + 78.f, this->_y_bar_npc + 32.f, ((float)capimonNpc->get_cur_health() / (float)capimonNpc->get_max_health()) * 96.f, 10.f, 0);
}
*/

/* PLAYER_ATTACK_HPP FUNCTIONS - BEGIN */
void Battle::draw_cursor() { //draw cursor and capimon skills 
	// ALLEGRO_FONT *font = al_load_font("file/font.ttf");
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
	//     break;
		
		
		
		/*
		for (int s = 0; s < capimon.AMOUNT_SKILLS; s++) {
			capimon.skill[s].draw_skill_in_battle();
		}
		*/
	//al_draw_text(font, al_map_rgb(0,0,0), 40, 420, ALLEGRO_ALIGN_LEFT, "CHOQUE DO TROVÃO"); // 0
	//al_draw_text(font, al_map_rgb(0,0,0), 40, 450, ALLEGRO_ALIGN_LEFT, "ATAQUE RÁPIDO"); // 1
	//al_draw_text(font, al_map_rgb(0,0,0), 200, 420, ALLEGRO_ALIGN_LEFT, "INVESTIDA DO TROVÃO"); // 2
	//al_draw_text(font, al_map_rgb(0,0,0), 200, 450, ALLEGRO_ALIGN_LEFT, "CAUDA DE FERRO"); // 3

	// for(Skill skill : hero->get_selected_capimon()->get_skills())
	// 	draw_skill(&skill);

}
// int select_enemy_attack(); //int ataqueInimigo();
// int select_player_attack(); //void selectAttack(int key);
// int do_attack();
/* PLAYER_ATTACK_HPP FUNCTIONS - END */

/* SKILL FUNCTIONS - BEGIN */
void Battle::draw_skill(Skill* skill) {
	//ALLEGRO_FONT* font = al_load_font("file/font.ttf", 11, 0); // TODO: Unificate fonts
	
	int index = skill->get_index();
	
	al_draw_text(this->_font, al_map_rgb(0,0,0), (index == 0 || index == 1) ? 40 : 200, (index == 0 || index == 2) ? 420 : 450, ALLEGRO_ALIGN_LEFT, skill->get_name().c_str());	// TODO: Confirme ternary operator use 
	
	//al_destroy_font(font);	// TODO: Remove when unificate fonts
}
/* SKILL FUNCTIONS - END */

/* NEW FUNCTIONS - BEGIN */
bool Battle::there_is_a_looser(Player *hero, Npc *enemy) {
	// unsigned int player_capimon_health = hero->get_select_capimon()->get_cur_health();
	// unsigned int npc_capimon_health = enemy->get_select_capimon()->get_cur_health();
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
/* NEW FUNCTIONS - END */
