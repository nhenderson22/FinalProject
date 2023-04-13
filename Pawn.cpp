#include "Pawn.hpp"
#include "ChessPiece.hpp"
#include "Blank.hpp"
#include "Board.hpp"

using namespace std;

//This will construct a pawn you pass it the color and an array where the first value is the row and second
// the column 
//TODO Update the constructor to instantiate mgame
Pawn::Pawn(const string COLOR, const int START_POSITION[2]){
    mColor = COLOR;
    mPosition[0] = START_POSITION[0];
    mPosition[1] = START_POSITION[1];
    mMoved = false;

}

int Pawn::getValue() const{
    return mValue;
}
//TODO after I get things working code en passant
//* This function returns whether or not the proposed move is legal for the pawn
bool Pawn::canMove(const int NEW_POS[2]) const{
    //* If the pawn wants to move two spaces up and it hasnt moved
    if(NEW_POS[0] - mPosition[0] == 2 && mMoved == false){
        
    }
}

//* If the Pawn is able to move the new position is set there
void Pawn::move(const int NEW_POSITION[2]){

}

