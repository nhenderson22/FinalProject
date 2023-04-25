#ifndef DISPLAYBOARD_HPP
#define DISPLAYBOARD_HPP

#include <string>
#include "Point.hpp"

// The purpose of this class is to maintain an internal array that
// we can use to display the status of our game it is the aesthetic
// board so to speak
class DisplayBoard{
    private:
        std::string mBoard[8][8]; // This is the array we wil print
    public:
        DisplayBoard();
        void show_board();//display the board
        void move_piece(Point start_pos, Point end_pos); //move a piece;
        void take_piece(Point start_pos, Point end_pos);
};

#endif