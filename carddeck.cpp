#include "carddeck.h"

CardDeck& CardDeck::make_CardDeck(){
    static CardDeck cardDeck;
    cardDeck.add();
    return cardDeck;
}
//not neededdededed
//why wa sit virtual again?
void CardDeck::add(){
    if(deck.empty()){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                FaceAnimal a = nextAnimal(i);
                FaceBackground c = nextColor(i);
                //no delete???
                Card* newCard = new Card(a, c);
                deck.push_back(newCard);
            }
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
