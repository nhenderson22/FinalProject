#include "Board.hpp"
#include "Blank.hpp"
#include "ChessPiece.hpp"
#include <string>

//TODO Update this john
Board::Board(){
    //* First we need to initialize the board with all the pieces then we need to update the string
    //* from there we will set everything to its starting value
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            msPosition[i][j] = " ";
        }
    }
    mBlackScore = 0;
    mWhiteScore = 0;
}

//*
ChessPiece Board::getPieceAtPosition(const int POSITION[2]) const{
    //* Check if the position given is in range
    //* If it is in range then we can return the peice thats there
}



