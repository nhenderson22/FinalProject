#include "DisplayBoard.hpp"
#include "Piece.hpp"
#include "Board.hpp"


#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(){
    //* So the game loop goes as follows: The user will select a piece
    //* When they select they can either show possible moves check if move is legal or move it
    //* Then its balcks turn and it goes until the player quits
    
    //Instantiate all of our classes
    Board currBoard;
    Piece currPiece;
    DisplayBoard display;
    fstream outFile;
    // Get the file to write to
    string fileLocation;
    cout << "Please enter the location of the file to write to: ";
    cin >> fileLocation;

    outFile.open(fileLocation,fstream::out);

    //This is our main loop
    while(true){
        //* First we need to display the board
        display.show_board();
        //* Then we prompt the user to choose a piece
        int row,col;
        cout << "Please select a piece" << endl;
        cout << "Piece Row: ";
        cin >> row;
        cout << "Piece Col: ";
        cin >> col;

        if(row > 7 || row < 0){
            cout << "Out of Bounds" << endl;
            continue;
        }
        if(col > 7 || row < 0){
            cout << "Out of Bounds" << endl;
            continue;
        }

        int choice;
        cout << "Please pick an option:" << endl;
        cout << "1: Show the possible moves of this piece" << endl;
        cout << "2: Check if a move is legal: " << endl;
        cout << "3: Move a piece" << endl;
        cout << "4: Show the current game score" << endl;
        cout << "5: Quit the game" << endl;
        cout << "Choice: ";
        cin >> choice;


        currPiece = currBoard.getPieceAtPosition(Point {row,col});
        if(choice == 1){
            //* Here we call the show legal moves
            currBoard.show_legal_moves(Point {row,col});
        }else if(choice == 2){
            int endRow,endCol;
            //* Here we need to check if a move is legal
            cout << "Please input the move coordinates: " << endl;
            cout << "Row: ";
            cin >> endRow;
            cout << "Col: ";
            cin >> endCol;
            
            if(row > 7 || row < 0){
                cout << "Out of Bounds" << endl;
                continue;
            }
            if(col > 7 || row < 0){
                cout << "Out of Bounds" << endl;
                continue;
            }

            bool legal = currPiece.isMoveLegal(Point {endRow,endCol},&currBoard);
            if(legal){
                cout << "Move is legal" << endl;
            }else{
                cout << "Move is not legal" << endl;
            }
        }else if(choice == 3){
            int endRow,endCol;
            //* here we need to call the move function on the move
            cout << "Input the move coordinates: " << endl;
            cout << "Row: ";
            cin >> endRow;
            cout << "Col: ";
            cin >> endCol;
            currPiece.move(&currBoard,Point {endRow,endCol},outFile);
            display.move_piece(Point {currPiece.getRow(),currPiece.getCol()},Point {endRow,endCol});
        }else if(choice == 4){
            int whiteScore = 0;
            int blackScore = 0;
            currBoard.countScore(whiteScore,blackScore);
            cout << "White Score: " << whiteScore << endl;
            cout << "Black Score: " << blackScore << endl;
        }else if(choice == 5){
            cout << "Ending the Game!" << endl;
            break;
        }else{
            cout << "not a valid choide" << endl;
        }
    }
    outFile.close();
    return 0;
}