#include "rewarddeck.h"

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
    for (std::vector<Reward*>::iterator it = deck.begin() ; it != deck.end(); it++){
        delete *it;
    } 
}
#ifdef TEST_REWARDDECK_
int main(){
    std::cout<< "Testing RewardDeck class\n" << std::endl;
    Deck<Reward>& a = RewardDeck::make_RewardDeck();
    int i = 0;
    std::cout<< "Reward ONE to int test: " << ((int)*a.getNext() == 1? "passed":"failed") << std::endl;
    std::cout<< "Reward ONE to int test: " << ((int)*a.getNext() == 1? "passed":"failed") << std::endl;
    std::cout<< "Reward ONE to int test: " << ((int)*a.getNext() == 1? "passed":"failed") << std::endl;
    std::cout<< "Reward TWO to int test: " << ((int)*a.getNext() == 2? "passed":"failed") << std::endl;
    std::cout<< "Reward TWO to int test: " << ((int)*a.getNext() == 2? "passed":"failed") << std::endl;
    std::cout<< "Reward THREE to int test: " << ((int)*a.getNext() == 3? "passed":"failed") << std::endl;
    std::cout<< "Reward FOUR to int test: " << ((int)*a.getNext() == 4? "passed":"failed") << std::endl;
    if(a.getNext() == nullptr){
        std::cout<< "boi" << std::endl;
    }
    return 0;
}
#endif