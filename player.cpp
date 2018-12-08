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
//why?
    //side m_Position
    //getsided() 
std::string Player::positionToString() const{
    switch(m_Position){
        case Side::TOP:
            return "top";
        case Side::BOTTOM:
            return "bottom";
        case Side::RIGHT:
            return "right";
        case Side::LEFT:
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