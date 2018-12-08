#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "board.h"
#include "player.h"

class Game{
    // private:

    // public:
    //const
        static const int num = 4;
        int index = 0;
    //create array of players const
        const Player* players[num];
        const Card* currentCard;
        const Card* previousCard;

        // needs to be static
        int round = 0;
        // needs to be static
        Board board;
    
    public:
        
        int getRound() const;
        
        void nextRound();
        void addPlayer(const Player&);
        const Player& getPlayer(Side) const;

        const Card* getPreviousCard() const;
        const Card* getCurrentCard() const;
        void setCurrentCard( const Card*);

        Card* getCard( const Letter&, const Number& );
        void setCard( const Letter&, const Number&, Card* );
        Game() = default;
        // Game(Board&);
        friend std::ostream& operator<<(std::ostream&, Game&);
};
#endif
