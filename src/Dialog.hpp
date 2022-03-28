/* Dialog.hpp */

#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <string>

class Dialog {
	private:
		std::string _speak;
		std::string _answer;
	public:
		Dialog(std::string speak, std::string answer);
		~Dialog();
		std::string get_speak();
		std::string get_answer();
		void set_speak(std::string speak);
		void set_answer(std::string answer);
};

#endif /* D_HPP */
