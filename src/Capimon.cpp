/* Capimon.cpp */

#include "Capimon.hpp"

#include <iostream>
#include <cstdlib>

int Capimon::AMOUNT_SKILLS = 4;

Capimon::Capimon(std::string name, ALLEGRO_BITMAP *image, int max_health, Skill skills[]){
	this->_name = name;
	this->_image = image;
	this->_max_health = max_health;
	this->_cur_health = max_health;
	
	for (int i = 0; i < this->AMOUNT_SKILLS; i++)
		this->_skills.push_back(skills[i]);
}

Capimon::~Capimon(){}

std::string Capimon::get_name() {
	return this->_name;
}

int Capimon::get_max_health() {
	return this->_max_health;
}

int Capimon::get_cur_health() {
	return this->_cur_health;
}

std::vector<Skill> Capimon::get_skills() {
	return this->_skills;
}

Skill Capimon::get_skill(int index) {
	return this->_skills.at(index);
}

void Capimon::decrement_health(int damage){
	if (damage > this->_cur_health)
		this->_cur_health = 0;
	else
		this->_cur_health -= damage;
}

void Capimon::heal_health(){ // funcao que ira restaurar a vida de um capimon pos batalha
	this->_cur_health = this->_max_health;
}

ALLEGRO_BITMAP* Capimon::get_image(){
	return this->_image;
}

void Capimon::select_skill() {
	srand(time(NULL));
	this->_selected_skill = &(this->_skills.at(rand() % this->AMOUNT_SKILLS));
}

Skill* Capimon::get_selected_skill() {
	return this->_selected_skill;
}

void Capimon::set_selected_skill(Skill *selected_skill) {
	this->_selected_skill = selected_skill;
}

void Capimon::set_selected_skill(int index) {
	this->_selected_skill = &(this->_skills.at(index));
}
