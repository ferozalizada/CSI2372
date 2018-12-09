#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "board.h"
#include "player.h"

/*
* Game class to create a board and keep a refernce to it
*/
class Game{
    protected:
        /*
        * Member Variables
        */
        static const int num = 4;
        int index = 0;
        
        // needs to be static
        /*
        * board refernce 
        */
        int round = 0;
        Board board;
        
        /*
        * pointers to players and cards
        */
        const Player* players[num];
        const Card* currentCard;
        const Card* previousCard;
    
    public:
        
        /*
        * helper function to return the number of round that is being played
        * @return int
        */
        int getRound() const;
        
        /*
        * helper function to increment round
        */
        void nextRound();

        /*
        * adds player to the game
        * @param reference of the player
        */
        void addPlayer(const Player&);

        /*
        * Getter for the player using the side as a parameter
        * @param Enum side
        * @return Player reference
        */
        const Player& getPlayer(Side) const;

        /*
        * Getter for the previous selected card
        * @return const Card*
        */
        const Card* getPreviousCard() const;
        
        /*
        * Getter for the current selected card
        * @return const Card*
        */
        const Card* getCurrentCard() const;

        /*
        * Setter for the card
        * @param const Card*
        */
        void setCurrentCard( const Card*);

        /*
        * Getter for the card by enums
        * @param letter enum
        * @param number enum
        * @return  Card*
        */
        Card* getCard( const Letter&, const Number& );
        
        /*
        * Setter for the selected card using letter and number enums and a pointer to cards
        * @param Letter
        * @param Number
        * @param Card*
        */
        void setCard( const Letter&, const Number&, Card* );
        
        /*
        * default constructor
        */
        Game() = default;
        // Game(Board&);

        /*
        * friend ostream to print the game state
        */
        friend std::ostream& operator<<(std::ostream&, Game&);
};
#endif
