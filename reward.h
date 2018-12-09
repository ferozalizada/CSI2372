#ifndef _REWARD_H_
#define _REWARD_H_

#include <iostream>
/*
*enums to represent limited rubies
*/
enum Rubies { ONE = 1, TWO, THREE, FOUR};
/*
* Creates an object of reward that hold a reward
*/
class Reward{
    protected:
        /*
        * member variables
        */
        Rubies m_rubies;
       
        /*
        * Constructor
        */
        Reward(Rubies);
      
        /*
        * deleted copy constructor
        */
        Reward(const Reward&) = delete;
      
        /*
        * deleted assignment operator
        */
        void operator=(const Reward&) = delete;

    public:
        /*
        * gives friend access to Reward Deck
        */
        friend class RewardDeck;
       
        /*
        * converstion operator
        */
        operator int() const;
       
        /*
        * friend access to ostream to print Reward
        * @param std::ostream&
        * @param Reward&
        */
        friend std::ostream& operator<<(std::ostream& os, Reward& reward);
};
#endif