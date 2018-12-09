#include "rewarddeck.h"
//needs destructor

RewardDeck& RewardDeck::make_RewardDeck(){
    RewardDeck r;
    return r.createDeck();
}

RewardDeck& RewardDeck::createDeck(){
    static RewardDeck reward_deck;
    reward_deck.add();
    return reward_deck;
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
RewardDeck::~RewardDeck(){
    int i = 0;
    for (std::vector<Reward*>::iterator it = deck.begin() ; it != deck.end(); it++){
        delete *it;
    } 
}
#ifdef DEBUG_REWARDDECK
int main(){
    std::cout<< "Testing Reward class\n" << std::endl;
    Deck<Reward>& a = RewardDeck::make_RewardDeck();
    // Deck<Reward>& p = RewardDeck::createDeck();
    while(!a.isEmpty()){
        // std::cout<< *a.getNext() << std::endl;
    std::cout<< "Reward ONE to int test: " << *a.getNext() << std::endl;
    }
    // std::cout<< "Reward ONE to int test: " << ((int)*r.getNext() == 1? "passed":"failed") << std::endl;
    // std::cout<< "Reward ONE << ostream operator test: " << (*r.getNext() == 1? "passed":"failed") << std::endl;
}

#endif