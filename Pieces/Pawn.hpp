#ifndef PAWN_HPP
#define PAWN_HPP
#include <string>

class ChessPiece{};
class Board{};

class Pawn : ChessPiece{
    private:
        int mValue;
        std::string mColor;
        int mPosition[2]; // The board deisplays the piece the piece will track where it is
        bool mMoved;
        Board mGame;// the current game this belongs too makes the code easier to read if i store this
    public:
        Pawn(const std::string COLOR, const int START_POSITION[2]);
        int getValue() const;
        void move(const int NEW_POSITION[2]);
        bool canMove(const int MOVE_POS[2]) const;
};

#endif