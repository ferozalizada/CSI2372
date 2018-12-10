#ifndef RULES_H
#define RULES_H

#include "game.h"
#include <string>

/*
* Rules class to check whether the player is making valid moves
*/
class Rules{
    
    protected:
        /*
        * member variables
        */

        int index = 0;
    public:

        /*
        * returns true is previous and current card match; false otherwise. 
        * @param Game&
        * @return bool
        */
        bool isValid(const Game&) const;
        
        /*
        * returns true if the number of rounds has reached 7. 
        * @param Game&
        * @return bool
        */
        bool gameOver(const Game&) const;
        
        /*
        * returns true if there is only one active Player left. 
        * @param Game&
        * @return bool
        */
        bool roundOver(const Game&) ;
        
        /*
        *  returns the next player
        * @param Game&
        * @return const Player&
        */
        const Player& getNextPlayer(const Game& ) ;

};
#endif