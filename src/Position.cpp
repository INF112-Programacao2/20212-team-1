/* Position.cpp */

#include <iostream>
#include "Position.hpp"

Position::Position(int x, int y){
    this->_x = x;
    this->_y = y;
}

Position::~Position(){}

int Position::get_x(){
    return this->_x;
}

int Position::get_y(){
    return this->_y;
}

void Position::set_x(int value) {
	this->_x = value;
}

void Position::set_y(int value) {
	this->_y = value;
}

void Position::add_x(){
    this->_x++;
}

void Position::add_y(){
    this->_y++;
}

void Position::sub_x(){
    this->_x--;
}

void Position::sub_y(){
    this->_y--;
}

void Position::add_x(int value){
    this->_x += val;
}

void Position::add_y(int value){
    this->_y += val;
}

void Position::sub_x(int value){
    this->_x -= val;
}

void Position::sub_y(int value){
    this->_y -=val;
}

Position Position::up() {
	Position p;
	p.set_x(this->_x++)
	p.set_y(this->y);

	return p;
}

Position Position::right() {
	Position p;
	p.set_x(this->_x)
	p.set_y(this->y++);

	return p;
}

Position Position::down() {
	Position p;
	p.set_x(this->_x--)
	p.set_y(this->y);

	return p;
}

Position Position::left() {
	Position p;
	p.set_x(this->_x)
	p.set_y(this->y--);

	return p;
}
