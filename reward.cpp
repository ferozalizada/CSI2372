#include "reward.h"

Reward::Reward(Rubies nRubies) : _rubies(nRubies){}

//what??
Reward::operator int() const{
    return _rubies;
}

std::ostream& operator<<(std::ostream& os, Reward& reward){
    os << reward._rubies << " rubies" << std::endl;
    return os;
}