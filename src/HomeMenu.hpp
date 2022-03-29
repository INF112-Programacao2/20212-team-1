#ifndef MENU_INICIAL_HPP
#define MENU_INICIAL_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include <string>

class HomeMenu{
    private:
        ALLEGRO_BITMAP *menu1;
        ALLEGRO_BITMAP *menu2;
    public:
        HomeMenu(std::string enderecoMenu1, std::string enderecoMenu2);
        ~HomeMenu();
        void initMenu();
};
#endif