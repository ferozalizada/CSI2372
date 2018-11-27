#ifndef BOARD_H
#define BOARD_H

#include <string>
// #include <vector>
#include "card.h"

enum class Letter{ A, B, C, D, E};
enum class Number{ ONE, TWO, THREE, FOUR, FIVE };

class Board{
    //needs a screen size// 16X20
    static const int row = 16;
    static const int col = 20;
    std::string screen[row][col];

    static const int row_board = 5;
    static const int col_board = 5;
    bool board[row_board][col_board];

    // need to have a board to hold everything in///

    //flag for face to know what
    bool faceUp = false;

    protected:
        bool isFaceUp(const Letter&, const Number&) const;
        
        bool turnFaceUp(const Letter&, const Number&);

        bool turnFaceDown(const Letter&, const Number&);

        Card* getCard(const Letter&, const Number&);

        void setCard(const Letter&, const Number&, Card*);
        
        void reset(); 


};
#endif