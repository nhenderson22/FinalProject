#ifndef ROOK_HPP
#define ROOK_HPP

#include <string>

class ChessPiece{};

class Rook:ChessPiece{
    private:
        int mValue;
        std::string mColor;
        int mPosition[2]; // The board deisplays the piece the piece will track where it is
        bool mMoved;
    public:
    
};


#endif