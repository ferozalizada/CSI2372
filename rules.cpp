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
        Side s;

        if(i == 0){
            s = Side::top;
        }else if(i == 1){
            s = Side::bottom;
        }else if(i == 2){
            s = Side::left;
        }else if(i == 3){
            s = Side::right;
        }

        if(game.getPlayer(Side::top).isActive()){
            counter++;
        }
    }
    std::cout << "mndao";
    if(counter ==1){
        return true;
    } else {
        return false;
    }
}
const Player& Rules::getNextPlayer(const Game& game) {
    // reset index if index out of range of Side enum
    if(index > 4){
        index = 0;
    }

    return (game.getPlayer((Side)(index++)));
}


#ifdef TEST_RULES_
int main(){
    std::cout<< "Testing Rules class\n" << std::endl;
    
    return 0;
}
#endif