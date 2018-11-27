#ifndef REWARDDECK_H
#define REWARDDECK_H

#include "reward.h"
#include "deck.h"


class RewardDeck: public Deck<Reward>{
    protected:
        // RewardDeck rewardDeck;
        RewardDeck() = default;
        void add();
    private:
        //no assignment or copy
        RewardDeck& operator=( const RewardDeck&) = delete;
        RewardDeck(const RewardDeck&) = delete;
    public:
        static RewardDeck& make_RewardDeck();

};



#endif