#include "carddeck.h"

CardDeck& CardDeck::make_CardDeck(){
    CardDeck cardDeck;
    return cardDeck.createDeck();
}

CardDeck& CardDeck::createDeck(){
    static CardDeck cardDeck;
    cardDeck.add();
    return cardDeck;
}

void CardDeck::add(){
    if(deck.empty()){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                FaceAnimal a = nextAnimal(i);
                FaceBackground c = nextColor(j);
                //no delete???
                Card* newCard = new Card(a, c);
                deck.push_back(newCard);
                // for debug?
                // std::cout << *(newCard) << std::endl;
            }
        // std::cout << std::endl;
        }
    }
}

FaceAnimal CardDeck::nextAnimal(int i){
    FaceAnimal animal;

    if(i == 0){
        animal = FaceAnimal::Crab;
    }else if(i == 1){
        animal = FaceAnimal::Penguin;
    }else if(i == 2){
        animal = FaceAnimal::Octopus;
    }else if(i == 3){
        animal = FaceAnimal::Turtle;
    }else if(i == 4){
        animal = FaceAnimal::Walrus;
    }

    return animal;
}

FaceBackground CardDeck::nextColor(int i){
    FaceBackground color;

    if(i == 0){
        color = FaceBackground::Red;
    }else if(i == 1){
        color = FaceBackground::Green;
    }else if(i == 2){
        color = FaceBackground::Purple;
    }else if(i == 3){
        color = FaceBackground::Blue;
    }else if(i == 4){
        color = FaceBackground::Yellow;
    }
    return color;
}

#ifdef DEBUG_CARDDECK
int main(){
    std::cout<< "Testing CardDeck class\n" << std::endl;
    std::cout<< "Testing make_createDeck()" << std::endl;
    Deck<Card>& a = CardDeck::make_CardDeck();
    Deck<Card>& b = CardDeck::make_CardDeck();
    std::cout<< "Address of deck a:"<< &a << "\nAddress of deck b:"<< &b 
            << "\nTest status: "<< ((&a == &b)? "passed": "failed")<< std::endl;
    while(!a.isEmpty()){
        a.getNext();
    }
    std::cout<<"pointer of a:  after emptying: " << a.getNext() <<std::endl;
    std::cout<<"pointer of b:                : " << b.getNext() <<std::endl;
    if(a.getNext() == b.getNext()){
        std::cout<< "both decks are emptied "<< std::endl;
    }
    return 0;
}
#endif