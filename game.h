#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "iostream"
#include "player.h"

class Game{
    // private:
    protected:
    static Board board;
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
        friend std::ostream& operator<<(std::ostream&, Game&);
};
#endif
