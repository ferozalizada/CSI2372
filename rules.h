#ifndef RULES_H
#define RULES_H

#include "game.h"

class Rules{
    // Game game;
    int index = 0;
    public:
        bool isValid(const Game&) const;
        bool gameOver(const Game&) const;
        bool roundOver(const Game&) const;
        const Player& getNextPlayer(const Game& ) ;

};
#endif