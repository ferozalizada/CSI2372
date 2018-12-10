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

    // flip card face up
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            Letter L;
            Number N;

            if(i == 0){
                L = Letter::A;
            }else if(i == 1){
                L = Letter::B;
            }else if(i == 2){
                L = Letter::C;
            }else if(i == 3){
                L = Letter::D;
            }else{
                L = Letter::E;
            }

            if(j == 0){
                N = Number::ONE;
            }else if(j == 1){
                N = Number::TWO;
            }else if(j == 2){
                N = Number::THREE;
            }else if(j == 3){
                N = Number::FOUR;
            }else{
                N = Number::FIVE;
            }

            Card* c = getCard(L, N);

            if(&card == &c){
                board.turnFaceUp(L, N);
            }
        }
    }
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