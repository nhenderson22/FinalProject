#include "DisplayBoard.hpp"
#include <string>
#include <iostream>

using namespace std;

// First we need to instatiate the board
// p = pawn, r = rook b = bishop ,h = horsey,q = queen k=king
DisplayBoard::DisplayBoard(){
    for(int i =0;i<8;i++){
        for(int j = 0; j<8;j++){
            mBoard[i][j] = " x";
        }
    }
    // Set the pawns up
    for(int i = 0; i<8;i++){
        mBoard[1][i] = "wp"; // white pawns
    }
    for(int i = 0;i<8;i++){
        mBoard[6][i] = "bp";
    }

    // Set up white rooks
    mBoard[0][0] = "wr";
    mBoard[0][7] = "wr";
    //Black rooks
    mBoard[7][0] = "br";
    mBoard[7][7] = "br";
    //Set up the horsey
    mBoard[0][1] = "wh";
    mBoard[0][6] = "wh";
    //now black
    mBoard[7][1] = "bh";
    mBoard[7][6] = "bh";
    // Set up bishop
    mBoard[0][5] = "wb";
    mBoard[0][2] = "wb";
    //black
    mBoard[7][5] = "bb";
    mBoard[7][2] = "bb";
    // Now we set up the queen
    mBoard[0][3] = "wq";
    mBoard[7][4] = "bq";
    //finally we do kings
    mBoard[0][4] = "wk";
    mBoard[7][3] = "bk";
}

// This will display the board
void DisplayBoard::show_board(){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << mBoard[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
