#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "board.h"
#include "player.h"

class Game{
    // private:

    public:
    //const
        static const int num = 4;
        int index = 0;
    //create array of players
        Player players[num];
        const Card* currentCard;
        Card* previousCard;
        // Card handCard;

        // needs to be static
         int round;
        // needs to be static
         Board board;
        
        int getRound();
        
        void nextRound();
        void addPlayer(const Player&);
        Player& getPlayer(Side);

        const Card* getPreviousCard();
        const Card* getCurrentCard();
        void setCurrentCard( const Card*);

        Card* getCard( const Letter&, const Number& );
        void setCard( const Letter&, const Number&, Card* );
    
    public:
        Game() = default;
        // Game(Board&);
        friend std::ostream& operator<<(std::ostream&, Game&);
};
#endif
