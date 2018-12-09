#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <algorithm>
#include<iostream>
#include<sstream>
#include <exception>
#include "carddeck.h"

/*
* Enums to represent numbers and letters and limit choices
*/
enum class Letter{ A, B, C, D, E};
/*
* Enums to represent numbers and letters and limit choices
*/
enum class Number{ ONE, TWO, THREE, FOUR, FIVE};

/*
* Class OutOfRange: Type of exception to throw if wrong input is given
*/
class OutOfRange: public std::exception{
  virtual const char* what() const throw();
  friend class Board;
};

/*
* Class Board to represnet the deck in a series of strings and store and view the cards
*/
class Board{
    private:
        /*
        * Member varibles for compile time size of arrays
        */
        static const int row = 19;
        static const int col = 19;
        static const int row_board = 5;
        static const int col_board = 5;
        
        /*
        * Member varibles screen representation of the board
        */
        std::string screen[row];
        
        /*
        * Member varibles for Deck of Cards
        */
        Deck<Card>& mydeck1 = CardDeck::make_CardDeck();
        
        /*
        * Member varibles for representing status of the card. i.e face up or down
        */
        bool boardFlag[row_board][col_board];
        
        /*
        * pointers to cards popped from the deck
        */
        Card* deckBoard[row_board][col_board];
        
        /*
        * helper function to set the screen to zzz zzz zzz zzz zzz
        */
        void setScreen();
        
        /*
        * updates the screen based on the face up array representation
        */
        void updateScreen();

    public:
        /*
        * Constructor to make the board
        */
        Board();
       
        /*
        * Helper function to see the status of the cards
        * @param letter representing row
        * @param number representing column
        * @returns true if face is up
        */
        bool isFaceUp(const Letter&, const Number&) const;
       
        /*
        * Helper function to set the status of the cards
        * @param letter representing row
        * @param number representing column
        * @returns true if face is up or if the face is not up then turns it up
        */
        bool turnFaceUp(const Letter&, const Number&);
      
        /*
        * Helper function to set the status of the cards
        * @param letter representing row
        * @param number representing column
        * @returns true if face is up or if the face is not down then turns it down
        */
        bool turnFaceDown(const Letter&, const Number&);
       
        /*
        * Helper function to get the card at the coordinate
        * @param letter representing row
        * @param number representing column
        * @returns pointer to the card at the coordinates of the board
        */
        Card* getCard(const Letter&, const Number&);
       
        /*
        * Helper function to get the card at the coordinate
        * @param letter representing row
        * @param number representing column
        */
        void setCard(const Letter&, const Number&, Card*);
       
        /*
        * Helper function to reset the faces to down
        */
        void reset(); 
       
        /*
        * friend ostream to print the board object
        */
        friend std::ostream& operator<<(std::ostream&, Board);
};
#endif