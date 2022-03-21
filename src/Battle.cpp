/* Battle.cpp */

#include "Battle.hpp"

// TODO: Change construct to the easier way
Battle::Battle(Npc *enemy):
	_enemy(enemy) {};

Battle::~Battle() {}

// TODO: start_battle()
Battle::start_battle() {
	bool exit = false;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *background;
	ALLEGRO_BITMAP *options;
	ALLEGRO_BITMAP *capimonJulio;
	ALLEGRO_BITMAP *capimonAndre;
	ALLEGRO_BITMAP *capimonAliado;
	ALLEGRO_BITMAP *seta;
	ALLEGRO_BITMAP *vida;
	ALLEGRO_BITMAP *bar;

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
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();

	if(!al_is_font_addon_initialized()){
		  std::cerr << "Font Addon nao foi inicializado!" << std::endl;
	}

	ALLEGRO_FONT *font = al_load_font("font.ttf", 11, 0);
	ALLEGRO_FONT *fonteFinal = al_load_font("font.ttf", 30, 0);
	ALLEGRO_SAMPLE *musica = NULL;
	ALLEGRO_SAMPLE_INSTANCE *musicaInstancia = NULL;

	al_reserve_samples(10);

	musica = al_load_sample("audios/musica.ogg");
	musicaInstancia = al_create_sample_instance(musica);
	al_set_sample_instance_playmode(musicaInstancia, ALLEGRO_PLAYMODE_LOOP);

	al_attach_sample_instance_to_mixer(musicaInstancia, al_get_default_mixer());
	
	// Fixo
	background = al_load_bitmap("img/TileBatalla.bmp");
	options = al_load_bitmap("img/DialogBar.bmp");
	vida = al_load_bitmap("img/Vida.bmp");
	bar = al_load_bitmap("img/Bar.bmp");

	Capimon Capivaristo(capimonAliado, "Capivaristo");
	PlayerAttack a;

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	Capimon Julio(capimonJulio, "Julio");

	CapimonStatus Jul(Julio.Get_Vida(), 14.f, 14.f);
	CapimonStatus Cap(Capivaristo.Get_Vida(), 420.f, 350.f);

	Capimon Andre(capimonAndre, "Andre");

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
		              a.selectAttack(ALLEGRO_KEY_LEFT);
		              break;

		          case ALLEGRO_KEY_RIGHT:
		              a.selectAttack(ALLEGRO_KEY_RIGHT);
		              break;

		          case ALLEGRO_KEY_UP:
		              a.selectAttack(ALLEGRO_KEY_UP);
		              break;
		          
		          case ALLEGRO_KEY_DOWN:
		              a.selectAttack(ALLEGRO_KEY_DOWN);
		              break;
		          
		          case ALLEGRO_KEY_ENTER:
		              Cap.decrementHealth(a.ataqueInimigo());
		              Jul.decrementHealth(a.do_attack());
		              break;
		      }
		  }

		  int i=1;
		  al_play_sample_instance(musicaInstancia);
		  al_draw_bitmap(background, 0, 0, 0);
		  al_draw_bitmap(options,0,407,0);

		  a.draw(font, seta);
		  Jul.draw("CHARIZARD",vida,bar,font);
		  Cap.draw("PIKACHU",vida,bar,font);

		  Capivaristo.Mostrar_Capimon();
		  if(i==1){
		      Julio.Mostrar_Capimon();
		  }
		  else{
		      Andre.Mostrar_Capimon();
		  }

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

	al_destroy_bitmap(background);
	al_destroy_font(fonteFinal);
	al_destroy_font(font);
	al_destroy_bitmap(options);
	al_destroy_bitmap(capimonJulio);
	al_destroy_bitmap(capimonAndre);
	al_destroy_bitmap(capimonAliado);
	al_destroy_bitmap(seta);
	al_destroy_sample(musica);
	al_destroy_bitmap(bar);
	al_destroy_bitmap(vida);
	al_destroy_sample_instance(musicaInstancia);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
	return 0;
}
