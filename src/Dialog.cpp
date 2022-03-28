/* Dialog.cpp */

#include "Dialog.hpp"

Dialog::Dialog(std::string speak, std::string answer) :
	_speak(speak), _answer(answer) {};
	
Dialog::~Dialog() {}

std::string Dialog::get_speak() {
	return this->_speak;
}

std::string Dialog::get_answer() {
	return this->_answer;
}

void Dialog::set_speak(std::string speak) {
	this->_speak = speak;
}

void Dialog::set_answer(std::string answer) {
	this->_answer = answer;
}
