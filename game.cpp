#include "game.h"

int Game::getRound() const{
    return round;
}
    
void Game::nextRound(){
    // increments the round if less than else end of game
    if(round < 7){
       round ++;

       // update all cards to face down
       board.reset();

       // set all players to active status
       resetPlayersStatus();
    }
}

void Game::resetPlayersStatus(){
    for(int i = 0; i < index; i++){
        players[i]->setActive(true);
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
    os << std::endl << game.board << std::endl;
    
    for(int i = 0; i < game.index; i++){
        os << *game.players[i];
    }

    return os;
}


#ifdef DEBUG_GAME
int main(){
    std::cout<< "Testing Game class\n" << std::endl;
    
    return 0;
}
#endif