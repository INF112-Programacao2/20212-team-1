/* Position.hpp */

/*
 * This class is used to store and manipulate positions in the screen (like a matrix)
 */
//Classe para armazenar dados de posição que serão integrados nas demais

#ifndef POSITION_HPP
#define POSITION_HPP

class Position{
    private:
        int _x, _y; //posições x e y 
    public:
        Position(int x, int y); //Construtor de Position
        ~Position(); //Destrutor de Position
        //Métodos para obter as posições e realizar alterações nelas
        
        int get_x();
        int get_y();
        
        void set_x(int value);
        void set_y(int value);
        
        void add_x();
        void add_y();
        void sub_x();
        void sub_y();
        
        void add_x(int value);
        void add_y(int value);
        void sub_x(int value);
        void sub_y(int value);
        
};

#endif /* POSITION_HPP */
