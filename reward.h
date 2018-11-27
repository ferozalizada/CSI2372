#ifndef _REWARD_H_
#define _REWARD_H_

#include <iostream>

enum Rubies {
   ZERO, ONE, TWO, THREE, FOUR
};

class Reward{
    Rubies _rubies;
        Reward(Rubies);
    
    private:
        Reward(const Reward&) = delete;
        void operator=(const Reward&) = delete;
        
    protected:
        friend std::ostream& operator<<(std::ostream& os, Reward& reward);
        friend class RewardDeck;
        operator int() const;
};
#endif