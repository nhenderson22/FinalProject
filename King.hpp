#ifndef KING_HPP
#define KING_HPP

#include <string>
class ChessPiece{};

class King:ChessPiece{
    private:
        int mValue;
        std::string mColor;
        int mPosition[2]; // The board deisplays the piece the piece will track where it is
        bool mMoved;
};

#endif