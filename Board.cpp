#include "Board.hpp"
#include "Piece.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Board::Board(){
   mBlackScore = 39;
   mWhiteScore = 39;

   //First we instatiate the board with blanks
   for(int i = 0; i<8 ; i++){
    for(int j = 0;j<8;j++){
        mBoard[i][j] = Piece(0,"Blank",Point {i,j}, "white");
    }
   }

   //* first set up the pawns
   for(int i = 0;i<8;i++){
        mBoard[1][i] = Piece(1,"Pawn",Point {1,i},"White");
   }
   for(int i = 0;i<8;i++){
        mBoard[6][i] = Piece(1,"Pawn",Point {6,i},"Black");
   }

   // Then we set the actual pieces
   //* Rooks
   mBoard[0][0] = Piece(5,"Rook",Point {0,0},"White");
   mBoard[0][7] = Piece(5,"Rook",Point {0,7},"White");
   mBoard[7][0] = Piece(5,"Rook",Point {7,0},"Black");
   mBoard[7][7] = Piece(5,"Rook",Point {7,7},"Black");
   //* Horses
   mBoard[0][1] = Piece(3,"Knight", Point {0,1},"White");
   mBoard[0][6] = Piece(3,"Knight", Point {0,6},"White");
   mBoard[7][1] = Piece(3,"Knight", Point {7,1},"Black");
   mBoard[7][6] = Piece(3,"Knight", Point {7,6},"Black");
   //* Bishops
   mBoard[0][5] = Piece(3,"Bishop", Point {0,5},"White");
   mBoard[0][2] = Piece(3,"Bishop", Point {0,2},"White");
   mBoard[7][5] = Piece(3,"Bishop", Point {7,5},"Black");
   mBoard[7][2] = Piece(3,"Bishop", Point {7,2},"Black");
   //* Queens
   mBoard[0][3] = Piece(9,"Queen", Point {0,3},"White");
   mBoard[7][4] = Piece(9,"Queen", Point {7,4},"Black");
   //* kings
   mBoard[0][4] = Piece(0,"King", Point {0,4},"White");
   mBoard[7][3] = Piece(0,"King", Point {7,3},"Black");
}

//* returns the piece at the pint that is passed to it
Piece Board::getPieceAtPosition(const Point pos) const{
    return mBoard[pos.row][pos.column];
}

// Prints all the mvoes a could make in a legal game 
void Board::print_legal_moves(Point pos){
    Piece currPiece = mBoard[pos.row][pos.column];
    vector<Point> moveVec = currPiece.getMoves(this); // Get the possible moves from the piece
    // Now we print ( make sure to denote if it is a capture or not)s
    for(int i = 0;i< moveVec.size();i++){
        Point currPoint = moveVec[i];
        if(getPieceAtPosition(currPoint).getType() != "Blank"){
            cout << "(" << currPoint.row << "," << currPoint.column << ")" << " (Capture)"<< endl;
        }else{
            cout << "(" << currPoint.row << "," << currPoint.column << ")" << endl;
        }
        
    }
}

// Used in piece movement 
void Board::swap_piece(Point originalPos, Point newPos, Piece* currPiece){
    // Piece& currPiece = mBoard[originalPos.row][originalPos.column];
    currPiece->setCol(newPos.column);
    currPiece->setRow(newPos.row);

    mBoard[newPos.row][newPos.column] = *currPiece;
    mBoard[originalPos.row][originalPos.column] = Piece();
}

//Checks for checks by getting all moves on the board and seeing if the king sqare is being attacked
bool Board::isKingInCheck(const string COLOR){
    // Find the king's position
    Point kingPos;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Piece currPiece = getPieceAtPosition(Point{row, col});
            if (currPiece.getType() == "King" && currPiece.getColor() == COLOR) {
                kingPos.row = row;
                kingPos.column = col;
                break;
            }
        }
    }

    // Check if any opponent pieces can attack the king's position
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Piece currPiece = getPieceAtPosition(Point{row, col});
            if (currPiece.getType() != "Blank" && currPiece.getColor() != COLOR) {
                // Check if this piece can move to the king's position
                vector<Point> moves = currPiece.getMoves(this);
                for (auto move : moves) {
                    if (move.row == kingPos.row && move.column == kingPos.column) {
                        return true; // King is in check
                    }
                }
            }
        }
    }

    return false; // King is not in check
}

// This is used in some of the functions for piece movement
void Board::set_piece_at_position(Point pos,Piece newPiece){
    // set the piece at the given position to be a blank
    mBoard[pos.row][pos.column] = newPiece;
}

// loops over the board and counts up the score of all the pices on the boards
void Board::countScore(int& whiteScore, int& blackScore) const {
    // Loop over all pieces on the board
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Piece currPiece = getPieceAtPosition(Point{row, col});
            if (currPiece.getType() != "Blank") {
                // Add the piece's value to the appropriate player's score
                if (currPiece.getColor() == "White") {
                    whiteScore += currPiece.getValue();
                } else {
                    blackScore += currPiece.getValue();
                }
            }
        }
    }
}


