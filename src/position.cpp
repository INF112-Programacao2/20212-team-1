#include <iostream>
#include "position.hpp"

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

void Position::add_x(int val){
    this->_x += val;
}

void Position::add_y(int val){
    this->_y += val;
}

void Position::sub_x(int val){
    this->_x -= val;
}

void Position::sub_y(int val){
    this->_y -=val;
}