#ifndef RULES_H
#define RULES_H

#include "game.h"
class Rules{
    protected:
        bool isValid(const Game&);
        bool gameOver(const Game&);
        bool roundOver(const Game&);
        const Player& getNextPlayer(const Game& );

};
#endif