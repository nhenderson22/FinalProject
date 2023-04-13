#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <string>

class ChessPiece{};

class Bishop:ChessPiece{
    private:
        int mValue;
        std::string mColor;
        int mPosition[2]; // The board deisplays the piece the piece will track where it is
        bool mMoved;
};

#endif