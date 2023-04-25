#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>
#include "Point.hpp"
#include <vector>
#include <fstream>


class Board;

// This is a class for a general chess piece the class will store the type the point value
class Piece{
    private:
        int mValue; // Store the pices point total
        std::string mType; // Store a string for the type of piece Bishop queen etc
        bool moved;
        Point mCurrPos; // store the current position
        std::string mColor;
    public:
        Piece(const int VALUE, const std::string TYPE, Point start_pos, const std::string COLOR);
        Piece();
        std::string getType() const;
        int getValue() const;
        int getRow() const;
        int getCol() const;
        std::string getColor() const;
        void setCol(const int COL);
        void setRow(const int ROW);
        std::vector<Point> getMoves(Board*) const;
        void get_rook_attacks(Board*, std::vector<Point>&) const;
        void get_bishop_attacks(Board*, std::vector<Point>&) const;
        bool isMoveLegal(Point, Board*) const;
        void get_pawn_attacks(Board*,std::vector<Point>&) const;
        void get_queen_attacks(Board*,std::vector<Point>&) const;
        void get_knight_attacks(Board*,std::vector<Point>&) const;
        void move(Board*,Point,std::fstream&);
};

#endif