#include "player.h"

Player::Player(std::string name)
    : m_Name(name), m_Status(true), m_NRubies(0), m_EndOfGame(false)
{}

std::string Player::getName() const{
    return m_Name;
}
bool Player::isActive() const{
    return m_Status;
}
void Player::setActive(bool status){
    m_Status = status;
}

int Player::getNRubies() const{
    return m_NRubies;
}

void Player::addReward(const Reward& reward) {
    m_NRubies += reward;
}

void Player::setDisplayMode( bool endOfGame ){
    m_EndOfGame = endOfGame;
}

Side Player::getSide() const{
    return m_Position;
}

void Player::setSide(Side side){
    m_Position = side;
}

std::string Player::positionToString() const{
    switch(m_Position){
        case Side::top:
            return "top";
        case Side::bottom:
            return "bottom";
        case Side::right:
            return "right";
        case Side::left:
            return "left";
        default:
            break;
    }
}

std::ostream& operator<<(std::ostream& os, const  Player& player){
    if(player.m_EndOfGame){
        os << player.getName() << ": " << player.getNRubies()<<  " rubies"<<std::endl;
    } else {
        os << player.getName() <<": " << player.positionToString()
        << " (" << (player.m_Status ? "active":"inactive") << ")"<< std::endl;
    }
    return os;
}


#ifdef DEBUG_PLAYER
int main(){

    std::cout<< "Testing Player class\n" << std::endl;
    std::string name = "Ali";
    Player p(name);

    std::cout<< "Player construction test: " << (name == p.getName()? "passed":"failed") << std::endl;
    std::cout<< "Player status isActive test: " << (p.isActive() == true? "passed":"failed") << std::endl;
    p.setActive(false);
    std::cout<< "Player status setActive test: " << (p.isActive() == false? "passed":"failed") << std::endl;
    p.setActive(true);
    std::cout<< "Player setActive test: " << (p.isActive() == true? "passed":"failed") << std::endl;
    std::cout<< "Player getNRubies test: " << (p.getNRubies() == 0? "passed":"failed") << std::endl;
    std::cout<< "\nPlayer addReward test: access restrictions will test in another file" << std::endl ;
    // << (p.addReward((Reward)1) == 1? "passed":"failed") << std::endl;
    //cant create reward 
    // p.addReward( const Reward& );
    p.setDisplayMode( true ) ;
    std::cout<< "Player setDisplayMode test ON: " << p;
    p.setDisplayMode( false ) ;
    std::cout<< "Player setDisplayMode test OFF: " << p;
    std::cout<< "Player getSide test (automatically top): " << (p.getSide() == Side::top? "passed":"failed") << std::endl;
    p.setSide(Side::bottom) ;
    std::cout<< "Player setSide(Side::bottom) test: " << (p.getSide() == Side::bottom? "passed":"failed") << std::endl;
    p.setSide(Side::left) ;
    std::cout<< "Player setSide(Side::left) test: " << (p.getSide() == Side::left? "passed":"failed") << std::endl;
    p.setSide(Side::right) ;
    std::cout<< "Player setSide(Side::right) test: " << (p.getSide() == Side::right? "passed":"failed") << std::endl;
    return 0;
}
#endif