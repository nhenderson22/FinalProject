#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include "Piece.hpp"


class Board{
    public:
        Board();
        int getBlackScore() const;
        int getWhiteScore() const;
        Piece getPieceAtPosition(const Point pos) const; // Takes the position in and gives you the array
        void print_legal_moves(Point);
        void swap_piece(Point,Point,Piece*);
        bool isKingInCheck(const std::string);
        void set_piece_at_position(Point,Piece);
        void countScore(int&,int&) const;
    private:
        Piece mBoard[8][8]; // This is the board where the logic gets stored
        int mBlackScore;
        int mWhiteScore;
};


#endif