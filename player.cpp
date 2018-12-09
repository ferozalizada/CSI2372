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
    std::cout<< "Added Rewards" << std::endl;
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
    std::cout<< "Player status setActive test: " << (p.isActive() == true? "passed":"failed") << std::endl;
    std::cout<< "Player status getNRubies test: " << (p.getNRubies() == 0? "passed":"failed") << std::endl;
    std::cout<< "Player status addReward test: Will test in some other file caz of access restrictions " ;
    // << (p.addReward((Reward)1) == 1? "passed":"failed") << std::endl;
    
    
    // p.getNRubies();
    // p.addReward( const Reward& );
    // p.setDisplayMode( bool endOfGame ) ;
    // p.Player::getSide();
    // p.Player::setSide(Side) 
    return 0;
}
#endif