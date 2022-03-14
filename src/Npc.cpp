/* Npc.cpp */

#include "Npc.hpp"

Npc::Npc(std::string name, ALLEGRO_BITMAP *image, int x, int y, ALLEGRO_BITMAP *dialog_image, std::string *file_directory) {
	Personagem(name, image, x, y);
	this->_dialog_image = dialog_image;
	for (std::string i : file_directory)
		this->_interactions.push_back(&(Interaction(i));
}
	
Npc::~Npc() {}

// TODO: interact();
void Npc::interact();

// TODO: Change place of typedef struct
typedef struct DRAW_CUSTOM_LINE_EXTRA {
   const ALLEGRO_FONT *font;
   float x;
   float y;
   int tick;
   float line_height;
   int flags;
} DRAW_CUSTOM_LINE_EXTRA;

// TODO: Press I to interact
// TODO: Draw interact screen
// TODO: Show interaction
// TODO: Exit interaction screen
void show_interaction() {
	// TODO: Change consts' place
	ALLEGRO_FONT *font;
	float max_width;
	bool al_do_multiline_text_cb (int line_num, const char *line, int size, void *extra) {
		DRAW_CUSTOM_LINE_EXTRA *s = (DRAW_CUSTOM_LINE_EXTRA *) extra;
		 float x, y;
		 ALLEGRO_USTR_INFO info;
		 ALLEGRO_COLOR c =
		 	al_color_hsv(fmod(360.0 * (float)line_num / 5.0 + s->tick, 360.0), 1.0, 1.0);
		 x  = s->x + 10 + sin(line_num + s->tick * 0.05) * 10;
		 y  = s->y + (s->line_height * line_num);
		 al_draw_ustr(s->font, c, x, y, 0, al_ref_buffer(&info, line, size));
		 return (line_num < 5);
	}
	
	DRAW_CUSTOM_LINE_EXTRA extra;
	extra.font = font;
	extra.x = 0;	// TODO: change text position (x)
	extra.y = 0;	// TODO: change text position (y)
	extra.line_height = al_get_font_line_height(font);
	
	// TODO: Change place
	// Font definitions
	font = al_init_font_addon();
	al_create_builtin_font();
   if (!font) {
      abort_example("Error creating builtin font\n");
   }

	Interaction* interaction = this->_interactions.back();
	this->_interactions.pop_back();
	
	int dialog_length = interaction->get_dialog_length();
	int size = interaction->SIZE;
	for (int d = 0; d < dialog_length; d++) {
		std::string* dialog = interaction->get_dialog(d);
		for (int i = 0; i < size; i++) {
			const char *text[] = dialog[i];
			al_do_multiline_text(font, max_width, text, al_do_multiline_text_cb, (void *)&extra);
		}
	}
}
