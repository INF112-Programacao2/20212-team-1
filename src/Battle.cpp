/* Battle.cpp */

#include "Battle.hpp"

// TODO: Change construct to the easier way
Battle::Battle(std::string background_directory) {
	this->_health_bar = al_load_bitmap("img/battle/health_bar.bmp");
	this->_colored_bar = al_load_bitmap("img/battle/colored_bar.bmp");
	this->_font = al_load_font("font.ttf", 11, 0);
	this->background = al_load_bitmap(background_directory);
	this->options = al_load_bitmap(options_directory);
	
	this->_selected_player_capimon = nullptr;
	this->_selected_player_skill = nullptr;
	this->_selected_npc_capimon = nullptr;
	this->_selected_npc_skill = nullptr;
}

Battle::~Battle() {
	al_destroy_bitmap(this->_health_bar);
	al_destroy_bitmap(this->_color_bar);
	al_destroy_font(this->_font);
	al_destroy_bitmap(this->background);
	al_destroy_bitmap(this->options);
}

// TODO: start_battle()
Battle::start_battle(Player *hero , NPC *enemy) {
	bool exit = false;

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

	musica = al_load_sample("audios/musica.ogg");
	musicaInstancia = al_create_sample_instance(musica);
	al_set_sample_instance_playmode(musicaInstancia, ALLEGRO_PLAYMODE_LOOP);

	al_attach_sample_instance_to_mixer(musicaInstancia, al_get_default_mixer());

	//Capimon Capivaristo(capimonAliado, "Capivaristo");
	PlayerAttack a;

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//Capimon Julio(capimonJulio, "Julio");

	//CapimonStatus Jul(Julio.Get_Vida(), 14.f, 14.f);
	//CapimonStatus Cap(Capivaristo.Get_Vida(), 420.f, 350.f);

	//Capimon Andre(capimonAndre, "Andre");

	
	_selected_player_skill_index_position[0] = 0;
	_selected_player_skill_index_position[1] = 0;
	while(!exit){

		  ALLEGRO_EVENT ev;
		  al_wait_for_event(event_queue,&ev);

		  if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
		      switch(ev.keyboard.keycode)
		      {
		          case ALLEGRO_KEY_ESCAPE:
		              exit = true;
		              break;		          
					case ALLEGRO_KEY_LEFT:
						(_selected_player_skill_index_position[0] == 1) ? _selected_player_skill_index_position[0]--;
						break;
					case ALLEGRO_KEY_RIGHT:
						(_selected_player_skill_index_position[0] == 0) ? _selected_player_skill_index_position[0]++;
						break;
					case ALLEGRO_KEY_UP:
						(_selected_player_skill_index_position[1] == 1) ? (_selected_player_skill_index_position[1]--);
						break;
					case ALLEGRO_KEY_DOWN:
						(_selected_player_skill_index_position[1] == 0) ? _selected_player_skill_index_position[1]++;
						break;
					case ALLEGRO_KEY_ENTER:
						selected_player_capimon->decrementHealth(selected_npc_skill->select_damage()); //criar algo para pegar um skill aleatoria
						selected_npc_capimon->decrement_health(selected_player_skill->select_damage()); //criar algo para selecionar a skill ainda
						break;
		      }
		  }
		  
		  // TODO: Confirm if the skills are correctly selected
			switch (selected_player_skill_index[0]) {
				case 0:
					switch (selected_player_skill_index[1]) {
						case 0:
							selected_player_skill = selected_player_capimon -> get.skill(0);
							break;
						case 1:
							selected_player_skill = selected_player_capimon -> get.skill(1);
							break;
					}
						
				case 1:
					switch (selected_player_skill_index[1]) {
						case 0:
							selected_player_skill = selected_player_capimon -> get.skill(2);
							break;
						case 1:
							selected_player_skill = selected_player_capimon -> get.skill(3);
							break;
					}
			}

		  int i=1;
		  al_play_sample_instance(musicaInstancia);
		  al_draw_bitmap(background, 0, 0, 0);
		  al_draw_bitmap(options,0,407,0);

		  //a.draw(font, selector);
		  //Jul.draw("CHARIZARD",vida,bar,font);
		  draw_npc_status(selected_npc_capimon);
		  //Cap.draw("PIKACHU",vida,bar,font);
		  draw_player_status(selected_player_capimon);

		  draw_capimon(hero);
		  draw_capimon(enemy);

		//   Capivaristo.Mostrar_Capimon();
		//   if(i==1){
		//       Julio.Mostrar_Capimon();
		//   }
		//   else{
		//       Andre.Mostrar_Capimon();
		//   }

		  if (Jul.looser())
		  {
		      al_clear_to_color(al_map_rgb(0,0,0));
		      al_draw_text(fonteFinal, al_map_rgb(255,255,255), 140, 220, ALLEGRO_ALIGN_LEFT, "VOCÊ  FOI  APROVADO!!!!");
		      al_flip_display();
		      al_rest(5.0);
		      exit = true;
		      // Julio ganhou, Capivaristo perde
		  } else if (Cap.looser())
		  {
		      al_clear_to_color(al_map_rgb(0,0,0));
		      al_draw_text(fonteFinal, al_map_rgb(255,255,255), 140, 220, ALLEGRO_ALIGN_LEFT, "VOCÊ  FOI  REPROVADO!!!!");
		      al_flip_display();
		      al_rest(5.0);
		      exit = true;
		      // Capivaristo ganhou, Julio perde
		  }

		  al_flip_display();
	}

	//al_destroy_bitmap(background);
	al_destroy_font(fonteFinal);
	//al_destroy_font(font);
	//al_destroy_bitmap(options);
	al_destroy_bitmap(capimonJulio);
	al_destroy_bitmap(capimonAndre);
	al_destroy_bitmap(capimonAliado);
	//al_destroy_bitmap(selector);
	al_destroy_sample(musica);
	//al_destroy_bitmap(bar);
	al_destroy_bitmap(vida);
	al_destroy_sample_instance(musicaInstancia);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	return 0;
}


// TODO: Creat draw_capimon()
void Battle::draw_capimon(Character *character) {
	character->get_select_capimon();
	Position draw_position = character->get_CAPIMON_DRAW_POSITION();
	al_convert_mask_to_alpha(character->get_selected_capimon()->get_image(), al_map_rgb(255,0,255));
	al_draw_bitmap(character->get_selected_capimon()->get_image(), draw_position.x, draw_position.y, 0);
}

void Battle::draw_player_capimon(Capimon *capimon){ //alterar para pegar a imagem do capimon certo
	al_convert_mask_to_alpha(capimonPlayer->get_image(), al_map_rgb(255,0,255));
	al_draw_bitmap(capimonPlayer->get_image(), 200, 295, 0); 	// TODO: Add right values in image position
}

void Battle::draw_npc_capimon(Capimon *capimon){ //alterar para pegar a imagem do capimon certo
	al_convert_mask_to_alpha(capimonNpc->get_image(), al_map_rgb(255,0,255));
	al_draw_bitmap(capimonNpc->get_image(), 200, 295, 0); 	// TODO: Add right values in image position (considering this is an Capimon's NPC)
}

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

/* PLAYER_ATTACK_HPP FUNCTIONS - BEGIN */
void draw_cursor() { //draw cursor and capimon skills 
	ALLEGRO_FONT *font = al_load_font("file/font.ttf");
	ALLEGRO_BITMAP *cursor = al_load_bitmap("img/cursor.bmp");
	al_convert_mask_to_alpha(cursor, al_map_rgb(255,0,255));
  
	switch (_selected)
	{
	case 0:
		al_draw_bitmap(cursor, 30, 420, 0);
		break;
	case 1:
		al_draw_bitmap(cursor, 30, 450, 0);
		break;
	case 2:
		al_draw_bitmap(cursor, 190, 420, 0);
		break;
	case 3:
		al_draw_bitmap(cursor, 190, 450, 0);
		break;
	// default:
	//     break;
		}
		
		
		/*
		for (int s = 0; s < capimon.AMOUNT_SKILLS; s++) {
			capimon.skill[s].draw_skill_in_battle();
		}
		*/
	//al_draw_text(font, al_map_rgb(0,0,0), 40, 420, ALLEGRO_ALIGN_LEFT, "CHOQUE DO TROVÃO"); // 0
	//al_draw_text(font, al_map_rgb(0,0,0), 40, 450, ALLEGRO_ALIGN_LEFT, "ATAQUE RÁPIDO"); // 1
	//al_draw_text(font, al_map_rgb(0,0,0), 200, 420, ALLEGRO_ALIGN_LEFT, "INVESTIDA DO TROVÃO"); // 2
	//al_draw_text(font, al_map_rgb(0,0,0), 200, 450, ALLEGRO_ALIGN_LEFT, "CAUDA DE FERRO"); // 3

	for(Skill skill : hero->get_selected_capimon()->get_skills())
		draw_skill(&skill);


}
int select_enemy_attack(); //int ataqueInimigo();
int select_player_attack(); //void selectAttack(int key);
int do_attack();
/* PLAYER_ATTACK_HPP FUNCTIONS - END */

/* SKILL FUNCTIONS - BEGIN */
void Battle::draw_skill(Skill* skill) {
	ALLEGRO_FONT* font = al_load_font("file/font.ttf", 11, 0); // TODO: Unificate fonts
	
	int index = skill->get_index();
	
	al_draw_text(font, al_map_rgb(0,0,0), (index == 0 || index == 1) ? 40 : 200, (index == 0 || index == 2) ? 420 : 450, ALLEGRO_ALIGN_LEFT, this->_name);	// TODO: Confirme ternary operator use 
	
	al_destroy_font(font);	// TODO: Remove when unificate fonts
}
/* SKILL FUNCTIONS - END */

/* NEW FUNCTIONS - BEGIN */
bool there_is_a_looser() {
	unsigned int player_capimon_health = this->_select_player_capimon->get_cur_health;
	unsigned int npc_capimon_health = this->_select_npc_capimon->get_cur_health;
	return (player_capimon_health == 0 || npc_capimon_health == 0);
}


Capimon* Battle::get_selected_player_capimon() {
	return this->_selected_player_capimon;
}

Skill* Battle::get_selected_player_skill() {
	return this->_selected_player_capimon;
}

void Battle::set_selected_npc_capimon(Capimon* selected_npc_capimon) {
	this->_selected_npc_capimon = selected_npc_capimon;
}

void Battle::set_selected_npc_skill(Skill* selected_npc_skill) {
	this->_selected_npc_capimon = selected_npc_skill;
}

Capimon* Battle::get_selected_npc_capimon() {
	return this->_selected_npc_capimon;
}

Skill* Battle::get_selected_npc_skill() {
	return this->_selected_npc_capimon;
}

void Battle::set_selected_npc_capimon(Capimon* selected_npc_capimon) {
	this->_selected_npc_capimon = selected_npc_capimon;
}

void Battle::set_selected_npc_skill(Skill* selected_npc_skill) {
	this->_selected_npc_capimon = selected_npc_skill;
}
/* NEW FUNCTIONS - END */
