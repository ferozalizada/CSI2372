#include "game.h"

int Game::getRound(){
    return round;
}
    
void Game::nextRound(){
    // increments the round if less than else end of game
    if(round != 6){
        round ++;
    } 
}

void Game::addPlayer(const Player& player){
    for(int i = 0; i < num; i++){
        const Player p = players[i];
        if( &p  == &player){
            std::cout<< "already added"<< std::endl;
        } else{
            players[index++] = player;
            break;
        }
    }
}

Player& Game::getPlayer(Side side){
    for (int i = 0; i< num; i ++){
        if(players[i].getSide() == side){
            return players[i];
        };
    }
}

const Card* Game::getPreviousCard(){
    return previousCard;
}
const Card* Game::getCurrentCard(){
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

#if 0
#endif