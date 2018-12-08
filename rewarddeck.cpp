#include "rewarddeck.h"
//needs destructor

RewardDeck& RewardDeck::createDeck(){
    static RewardDeck rewardDeck;
    rewardDeck.add();
    return rewardDeck;
}
RewardDeck& RewardDeck::make_RewardDeck(){
    static RewardDeck rewardDeck;
    rewardDeck.createDeck();
    return rewardDeck;
}


void RewardDeck::add(){
    if(deck.empty()){
        // 3 cards with one ruby
        Reward* r1 = new Reward(Rubies::ONE);
        Reward* r2 = new Reward(Rubies::ONE);
        Reward* r3 = new Reward(Rubies::ONE);

        // 2 cards with 2 rubies
        Reward* r4 = new Reward(Rubies::TWO);
        Reward* r5 = new Reward(Rubies::TWO);

        // 1 card with 3 rubies
        Reward* r6 = new Reward(Rubies::THREE);

        // 1 card with 4 rubies
        Reward* r7 = new Reward(Rubies::FOUR);

        deck.push_back(r1);
        deck.push_back(r2);
        deck.push_back(r3);
        deck.push_back(r4);
        deck.push_back(r5);
        deck.push_back(r6);
        deck.push_back(r7);          
    }
}
