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
    for (int i = 0; i< num; i ++){
        if((*players[i]).getSide() == side){
            return *players[i];
        };
    }
    
}

const Card* Game::getPreviousCard() const{
    return previousCard;
}
const Card* Game::getCurrentCard() const{
    return currentCard;
}
void Game::setCurrentCard( const  Card* card){
    currentCard = card;

    // board.getCard()
    //flip here
    // board.

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


#ifdef TEST_GAME_
int main(){
    std::cout<< "Testing Rules class\n" << std::endl;
    Game game = Game();
    // Rules rule = Rules();
    Player p = Player("Feroz");
    game.addPlayer(p);
    p.setSide(Side::top);
    std::cout<< "Testing is getRound = 0: " <<(game.getRound()  == 0? "passed": "failed")<< std::endl;
    std::cout<< game << std::endl;
    game.nextRound();
    std::cout<< "Testing is nextRound = 1: " <<(game.getRound()  == 1? "passed": "failed")<< std::endl;
    
    std::cout<< "getPlayer " <<game.getPlayer(Side::top)<< std::endl;
    // (*game.getCurrentCard()).print();
    game.getCard(Letter::A, Number::ONE);
    // Card* c = (game.getCurrentCard());
    // game.setCard(Letter::A, Number::ONE, c);
    // std::cout<< *game.getCurrentCard() << std::endl;
    
    return 0;
}
#endif