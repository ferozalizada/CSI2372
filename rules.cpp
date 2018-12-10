#include"rules.h"


bool Rules::isValid(const Game& game) const{
    return game.getCurrentCard() == game.getPreviousCard();    
}

bool Rules::gameOver(const Game& game) const{
    return game.getRound() > 6 ;
}
bool Rules::roundOver(const Game& game)  {
   int counter = 0;
   for(int i =0; i< index; i++){
       if( (getNextPlayer(game)).isActive()){
           counter ++;
       }
   }
   return counter == 1;
}
 const Player& Rules::getNextPlayer(const Game& game) {
    // reset index if index out of range of Side enum
    if(index > 3){
        index = 0;
    }
    return (game.getPlayer((Side)(index++)));
    // return (game.board.getNextPlayer());
}


#ifdef TEST_RULES_
int main(){
    std::cout<< "Testing Rules class\n" << std::endl;
    Game game = Game();
    Rules rule = Rules();
    Player p = Player("Feroz");
    Player p1 = Player("Feroz1");
    Player p2 = Player("Feroz2");
    Player p3 = Player("Feroz3");
    p1.setSide(Side::bottom);
    p2.setSide(Side::left);
    p3.setSide(Side::right);
    p.setActive(false);
    p1.setActive(false);
    p2.setActive(false);
    p3.setActive(false);
    game.addPlayer(p);
    game.addPlayer(p1);
    game.addPlayer(p2);
    game.addPlayer(p3);
    std::cout<< "Testing is roundOver(): no active player " <<(rule.roundOver(game)  == false? "passed": "failed")<< std::endl;
    std::cout<< "Testing is GameOver(): " <<(rule.gameOver(game) == 0? "passed": "failed" )<< std::endl;
    std::cout<< "Testing is isValid(): " <<(game.getCurrentCard()== game.getCurrentCard()? "passed": "failed") << std::endl;
    std::cout<< "Testing is isValid(): " <<(game.getCurrentCard() == game.getPreviousCard()? "passed": "failed") << std::endl;
    std::cout<< "Testing is getNextPlayer(): " <<(rule.getNextPlayer(game) )<< std::endl;
    std::cout<< "Testing is getNextPlayer(): " <<(rule.getNextPlayer(game) )<< std::endl;
    std::cout<< "Testing is getNextPlayer(): " <<(rule.getNextPlayer(game) )<< std::endl;
    std::cout<< "Testing is getNextPlayer(): " <<(rule.getNextPlayer(game) )<< std::endl;
    std::cout<< "Testing is isValid(): " <<(rule.isValid(game) == 1? "passed": "failed") << std::endl;
    p3.setActive(true);
    std::cout<< "Testing is roundOver(): " <<(rule.roundOver(game)  == true? "passed": "failed")<< std::endl;

    
    return 0;
}
#endif