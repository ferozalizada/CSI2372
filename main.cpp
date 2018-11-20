#include <iostream>
#include "player.h"
#include "card.h"

int main(){
    // std::cout<< "Running Fine!" << std::endl;
    Player p1("Karim");
    Player p2("Jamil");
    p2.setActive(false);

    p1.setSide(Side::BOTTOM);
    // std::cout << "Player Name: " << p1.getName() << "Side: " << p1.positionToString() << std::endl;
    std::cout<< p1 << std::endl;
    std::cout<< p2 << std::endl;

    std::cout<< "creating deck!" << std::endl;
    // Card c = Card()
}