#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <algorithm>
#include<iostream>
#include<sstream>
// #include <vector>
#include "card.h"
#include "carddeck.h"
#include "deck.h"

enum class Letter{ A, B, C, D, E};
enum class Number{ ONE, TWO, THREE, FOUR, FIVE };

class Board{
    static const int row = 19;
    static const int col = 19;
    
    std::string screen[row];
    
    std::string text;
    std::string sample;

    static const int row_board = 5;
    static const int col_board = 5;
    Deck<Card>& mydeck1 = CardDeck::make_CardDeck();

    bool boardFlag[row_board][col_board];
    Card* deckBoard[row_board][col_board];
    //create deck
    
    public:

    void setScreen();
    void updateScreen();
    void setBoard();
    void print();

        Board() = default;

    // protected:
        bool isFaceUp(const Letter&, const Number&) const;
        bool turnFaceUp(const Letter&, const Number&);
        bool turnFaceDown(const Letter&, const Number&);
        Card* getCard(const Letter&, const Number&);
        void setCard(const Letter&, const Number&, Card*);
        void reset(); 

        friend std::ostream& operator<<(std::ostream&, Board);


};
#endif