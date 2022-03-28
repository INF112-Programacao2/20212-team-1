/* Position.hpp */

#ifndef POSITION_HPP
#define POSITION_HPP

class Position{
    private:
        int _x, _y;
    public:
        Position(int x, int y);
        ~Position();
        
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
