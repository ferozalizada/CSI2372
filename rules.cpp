#include"rules.h"


bool Rules::isValid(const Game& game) const{
    return game.getCurrentCard() == game.getPreviousCard();    
}

bool Rules::gameOver(const Game& game) const{
    return game.getRound() > 6 ;
}
bool Rules::roundOver(const Game& game) const {
    int counter = 0;
    for(int i =0; i < 4; i++){
        if(game.getPlayer((Side)i).isActive()){
            counter ++;
        }
    }
    if(counter ==1){
        return true;
    } else {
        return false;
    }
}
const Player& Rules::getNextPlayer(const Game& game) {
    return (game.getPlayer((Side)(index++)));
}


#ifdef DEBUG_RULES
int main(){
    std::cout<< "Testing Rules class\n" << std::endl;
    
    return 0;
}
#endif