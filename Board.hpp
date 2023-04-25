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
        void show_legal_moves(Point);
        void swap_piece(Point,Point);
        bool isKingInCheck(const std::string);
        void set_piece_at_position(Point,Piece);
        bool isKingInCheckmate(const std::string) const;
        void countScore(int&,int&) const;
    private:
        Piece mBoard[8][8]; // This is the board where the logic gets stored
        int mBlackScore;
        int mWhiteScore;
};


#endif