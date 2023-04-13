#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

class ChessPiece{};

class Board{
    public:
        Board();
        int getBlackScore() const;
        int getWhiteScore() const;
        ChessPiece getPieceAtPosition(const int POSITION[2]) const; // Takes the position in and gives you the array
    private:
        ChessPiece mPosition[8][8];
        std::string msPosition[8][8]; // This array stores the string version of the board for printing
        int mBlackScore;
        int mWhiteScore;
};


#endif