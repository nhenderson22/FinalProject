#include "Piece.hpp"
#include "Board.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Set the point value as well as the type of the pice that it is
Piece::Piece(const int VALUE, const string TYPE, Point start_pos,const string COLOR){
    mType = TYPE;
    mValue = VALUE;
    moved = false;
    mColor = COLOR;
    mCurrPos = start_pos;
}
// Default constructor
Piece::Piece(){
    mType = "Blank";
    mValue = 0;
}

string Piece::getType() const{
    return mType;
}

int Piece::getValue() const{
    return mValue;
}

int Piece::getRow() const{
    return mCurrPos.row;
}

int Piece::getCol() const{
    return mCurrPos.column;
}

string Piece::getColor() const{
    return mColor;
}

void Piece::setCol(const int COL){
    mCurrPos.column = COL;
}
void Piece::setRow(const int ROW){
    mCurrPos.row = ROW;
}

// Populates the vector with the possible moves the pawn could make in a legal scenario
void Piece::get_pawn_attacks(Board* board, vector<Point>& moveVector) const{
    vector<Point> possibleMoves;
    // populate the vector with the possible moves based on the direction the pawn can move
    if(mColor == "White"){
        possibleMoves = {Point {mCurrPos.row + 1, mCurrPos.column},Point {mCurrPos.row + 2, mCurrPos.column},
                        Point {mCurrPos.row + 1, mCurrPos.column + 1},Point {mCurrPos.row + 1, mCurrPos.column - 1}};
    }else{
        possibleMoves ={Point {mCurrPos.row - 1, mCurrPos.column},Point {mCurrPos.row - 2, mCurrPos.column},
                        Point {mCurrPos.row - 1, mCurrPos.column + 1},Point {mCurrPos.row - 1, mCurrPos.column - 1}};
    }
    
    //Loops over the board and will add legal moves to the vector
    for(int i = 0; i<possibleMoves.size();i++){
        Point currPoint = possibleMoves[i];
        if(currPoint.row >= 8 || currPoint.row < 0){
            continue;
        }
        // the column is out of bourds
        if(currPoint.column > 7 || currPoint.column < 0){
            continue;
        }
        // if they clear the checks they are possible
        moveVector.push_back(currPoint);
    }
}

//* A function that will return the vector of all possible moves a piece could make
//* this acts as a helper function for the board class
vector<Point> Piece::getMoves(Board* board) const{
    vector<Point> possibleMoves; // this will get returned at the end
    //* First we need to make a switch to determine what the piece iss
    if(mType == "Pawn"){
        get_pawn_attacks(board,possibleMoves);
    }else if(mType == "Rook"){
        get_rook_attacks(board, possibleMoves);
    }else if(mType == "Bishop"){
        get_bishop_attacks(board,possibleMoves);
    }else if(mType == "Queen"){
        get_queen_attacks(board,possibleMoves);
    }else if(mType == "Knight"){
        get_knight_attacks(board,possibleMoves);
    }else if(mType == "Blank"){
        cout << "This is an empty slot" << endl;
    }
    return possibleMoves;
}

//* Populates a vector with the possible attakcs the rook could make
void Piece::get_rook_attacks(Board* board, vector<Point>& moveVector) const {
    // Check upwards
    for (int row = mCurrPos.row - 1; row >= 0; row--) {
        Piece currPiece = board->getPieceAtPosition(Point{row, mCurrPos.column});
        // Then we check what the pieces in the direction
        if (currPiece.getType() != "Blank") {
            if (currPiece.getColor() != mColor) {
                moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
            }
            break;
        } else if(currPiece.getType() == "Blank") {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
        }
    }

    // Check downwards
    for (int row = mCurrPos.row + 1; row < 8; row++) {
        Piece currPiece = board->getPieceAtPosition(Point{row, mCurrPos.column});
        if (currPiece.getType() != "Blank") {
            if (currPiece.getColor() != mColor) {
                moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
            }
            break;
        } else {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
        }
    }

    // Check to the left
    for (int col = mCurrPos.column - 1; col >= 0; col--) {
        Piece currPiece = board->getPieceAtPosition(Point{mCurrPos.row, col});

        if (currPiece.getType() != "Blank") {
            if (currPiece.getColor() != mColor) {
                moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
            }
            break;
        } else {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
        }
    }

    // Check to the right
    for (int col = mCurrPos.column + 1; col < 8; col++) {
        Piece currPiece = board->getPieceAtPosition(Point{mCurrPos.row, col});
        if (currPiece.getType() != "Blank") {
            if (currPiece.getColor() != mColor) {
                moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
            }
            break;
        } else {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
        }
    }
}

//* Populates vector with possible bishop attacks
void Piece::get_bishop_attacks(Board* board, vector<Point>& moveVector) const {
    Piece currPiece;
    // Check diagonal moves in all directions
    int row = mCurrPos.row + 1, col = mCurrPos.column + 1;
    while (row <= 7 && col <= 7) {
        currPiece = board->getPieceAtPosition(Point{row, col});
        if (currPiece.getType() == "Blank") {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
        } else if (currPiece.getColor() != mColor) {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
            break;
        } else {
            break;
        }
        row++, col++;
    }

    row = mCurrPos.row + 1, col = mCurrPos.column - 1;
    while (row <= 7 && col >= 0) {
        currPiece = board->getPieceAtPosition(Point{row, col});
        if (currPiece.getType() == "Blank") {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
        } else if (currPiece.getColor() != mColor) {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
            break;
        } else {
            break;
        }
        row++, col--;
    }

    row = mCurrPos.row - 1, col = mCurrPos.column + 1;
    while (row >= 0 && col <= 7) {
        currPiece = board->getPieceAtPosition(Point{row, col});
        if (currPiece.getType() == "Blank") {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
        } else if (currPiece.getColor() != mColor) {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
            break;
        } else {
            break;
        }
        row--, col++;
    }

    row = mCurrPos.row - 1, col = mCurrPos.column - 1;
    while (row >= 0 && col >= 0) {
        currPiece = board->getPieceAtPosition(Point{row, col});
        if (currPiece.getType() == "Blank") {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
        } else if (currPiece.getColor() != mColor) {
            moveVector.push_back(Point {currPiece.getRow(),currPiece.getCol()});
            break;
        } else {
            break;
        }
        row--, col--;
    }
}

// Uses the bishop and rook functions to populate the vector as a queen is just a combo of the two
void Piece::get_queen_attacks(Board* board,vector<Point>& moveVec) const{
    get_bishop_attacks(board,moveVec);
    get_rook_attacks(board,moveVec);
}
// Populates the knight attacks vector
void Piece::get_knight_attacks(Board* board, vector<Point>& moveVec) const{
    // Populate the 8 knight moves
    vector<Point> possibleMoves = {Point {mCurrPos.row + 2,mCurrPos.column + 1},Point {mCurrPos.row + 2,mCurrPos.column - 1},
                                   Point {mCurrPos.row + 1,mCurrPos.column + 2},Point {mCurrPos.row + 1,mCurrPos.column - 2},
                                   Point {mCurrPos.row - 2,mCurrPos.column + 1},Point {mCurrPos.row - 2,mCurrPos.column - 1},
                                   Point {mCurrPos.row - 1,mCurrPos.column + 2},Point {mCurrPos.row - 1,mCurrPos.column - 2},};
    // Filter out out of bounds
    for(int i = 0; i<possibleMoves.size();i++){
        Point currPoint = possibleMoves[i];
        if(currPoint.row > 8 || currPoint.row < 0){
            continue;
        }

        if(currPoint.column > 8 || currPoint.column < 0){
            continue;
        }
        // Check what piece is in the poistion that we watn to move to
        Piece currPiece = board->getPieceAtPosition(currPoint);
        if(currPiece.getType() != "Blank"){
            if(currPiece.getColor() != mColor){
                moveVec.push_back(currPoint);
                continue;
            }
        }
        moveVec.push_back(currPoint);
    }
}


// This Function takes a point called end pos and will make a move and return if the move is legal or not
// This is based on if the move puts the king in check
bool Piece::isMoveLegal(Point endPos,Board* board) const{
    // First save the piece at the end pos
    Piece endPiece = board->getPieceAtPosition(endPos);
    // Then we move the piece to the end pos
    board->set_piece_at_position(endPos,*this);
    // Then we need to check whether the king is in check
    bool legal = !board->isKingInCheck(mColor);
    // Then we reset the board
    board->set_piece_at_position(mCurrPos,*this);
    board->set_piece_at_position(endPos, endPiece);
    // tell if a move is legal
    return legal;
}
// This funcion will allow you to move the pice to anywhere you want
// The reason I am not checking legality is beacuase this is an analysis board
void Piece::move(Board* board, Point endPos,fstream& outFile){
    board->swap_piece(mCurrPos,endPos);
    // Now update our file
    outFile << "The " << mColor << " " << mType << " moved to " << mCurrPos.row << "," << mCurrPos.column << "\n";
}