#ifndef INF112_POSITION_HPP
#define INF112_POSITION_HPP

class Position{
    private:
        int _x, _y;
    public:
        Position(int x, int y);
        ~Position();
        int get_x();
        int get_y();
        void add_x();
        void add_y();
        void sub_x();
        void sub_y();

        void add_x(int val);
        void add_y(int val);
        void sub_x(int val);
        void sub_y(int val);
};
#endif
