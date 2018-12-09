#ifndef REWARDDECK_H
#define REWARDDECK_H

#include "reward.h"
#include "deck.h"


class RewardDeck: public Deck<Reward>{
    protected:
        /*
        * Default Constructor RewardDeck 
        */ 
        RewardDeck() = default;
        /*
        * Adds the card to the deck
        */ 
        void add();
        /*
        * Destructor for the deck
        */ 
        ~RewardDeck();
        /*
        * Deleted assignment operator
        */ 
        RewardDeck& operator=( const RewardDeck&) = delete;
        /*
        * Deleted copy constructor
        */ 
        RewardDeck(const RewardDeck&) = delete;
        /*
        * Virtual function to create deck
        */ 
        RewardDeck& createDeck();
    public:
        /*
        * Static function for deck
        */ 
        static RewardDeck& make_RewardDeck();

};



#endif