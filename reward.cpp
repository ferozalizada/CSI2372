#include "reward.h"
#include "rewarddeck.h"

Reward::Reward(Rubies rubies) : m_rubies(rubies){}

Reward::operator int() const{
    return (int) m_rubies;
}

std::ostream& operator<<(std::ostream& os, Reward& reward){
    os << reward.m_rubies << " rubies" << std::endl;
    return os;
}


#ifdef DEBUG_REWARD
int main(){
    std::cout<< "Testing Reward class\n" << std::endl;
    Deck<Reward>& r = RewardDeck::make_RewardDeck();
    // std::cout<< &r.getNext() << std::endl;
    
    // std::cout<< "Reward ONE to int test: " << (name == p.getName()? "passed":"failed") << std::endl;
    // std::cout<< "Reward << test: " << (name == p.getName()? "passed":"failed") << std::endl;
    // std::cout<< "Player status isActive test: " << (p.isActive() == true? "passed":"failed") << std::endl;
    // p.setActive(false);
}
#endif