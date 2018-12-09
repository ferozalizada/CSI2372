#include "game.h"

int Game::getRound() const{
    return round;
}
    
void Game::nextRound(){
    // increments the round if less than else end of game
    if(round != 6){
       round ++;
    } 
}

void Game::addPlayer(const Player& player){
    if(index < num){
        Player* p = new Player(player.getName());
        p->setSide(player.getSide());

        players[index++] = p;
    }
}

const Player& Game::getPlayer(Side side) const {
    // Player p;
    for (int i = 0; i< num; i ++){
        if((*players[i]).getSide() == side){
            return *players[i];
        };
    }
    // return p;
    // return players[(int)side];
}

const Card* Game::getPreviousCard() const{
    return previousCard;
}
const Card* Game::getCurrentCard() const{
    return currentCard;
}
void Game::setCurrentCard( const  Card* card){
    currentCard = card;
}

Card* Game::getCard( const Letter& _letter, const Number& _number){
    return board.getCard(_letter, _number);

}
void Game::setCard( const Letter& _letter, const Number& _number, Card* _card){
    board.setCard( _letter, _number , _card);
}

std::ostream& operator<<(std::ostream& os, Game& game){
    os<< game.board << std::endl;
    for(int i =0; i< game.num; i++){
        os << *game.players[i];

    }

    return os;
}


#if 0
int main(){
    Game g = Game();

    
    return 0;
}

#endif