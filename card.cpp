#include "card.h"

Card::Card(FaceAnimal faceAnimal, FaceBackground faceBackground)
    : m_faceAnimal(faceAnimal), m_faceBackground(faceBackground){
    createCard( faceAnimal, faceBackground);
}

char Card::getAnimalLetter(FaceAnimal& animal){
    if(animal == FaceAnimal::Crab){
        return 'C';
    }else if(animal == FaceAnimal::Penguin){
        return 'P';
    }else if(animal == FaceAnimal::Octopus){
        return 'O';
    }else if(animal == FaceAnimal::Turtle){
        return 'T';
    // }else if(animal == FaceAnimal::Walrus){
    //     return 'W';
    } else{
        return 'W';
    }
}

char Card::getColorLetter(FaceBackground& color){
    if(color == FaceBackground::Red){
        return 'r';
    }else if(color == FaceBackground::Green){
        return 'g';
    }else if(color == FaceBackground::Purple){
        return 'p';
    }else if(color == FaceBackground::Blue){
        return 'b';
    // }else if (color == FaceBackground::Yellow){
    //     return 'y';
    }else{
        return 'y';
    }
}

int Card::getNRows(){
    return m_numberOfRows;
}

std::string Card::operator()(int row){
    return card[row];
}

void Card::createCard(FaceAnimal& animal, FaceBackground& color){
    char a = getAnimalLetter(animal);
    char c = getColorLetter(color);

    for(int i = 0; i < m_numberOfRows; i++){
        for(int j = 0; j < m_numberOfColumns; j++){
            if(i == 1 && j == 1){
                // insert animal letter in the middle of card
                card[i] += a;
            }else {
                // insert color letter in the middle of card
                card[i] += c;
            }
        }
    }
}

void Card::print(){
    // Card c(FaceAnimal::Penguin, FaceBackground::Red);
    for(int row = 0; row < this->getNRows() ; ++row){
        std::string rowString = (*this)(row);
        std::cout << rowString << std::endl;
    }
}

Card::operator FaceAnimal() const {
    return m_faceAnimal;
}

Card::operator FaceBackground() const {
    return m_faceBackground;
}

#ifdef TEST_CARD_
#include "carddeck.h"
int main(){
    std::cout<< "Testing Card class\n" << std::endl;
    Deck<Card>& a = CardDeck::make_CardDeck();
    std::cout<< "Printing the cards from the deck\n" << std::endl;
    Card* p = a.getNext();
    
    std::cout<< "Card is\n" << std::endl;
    (*p).print();
    std::cout<< "print() passed" << std::endl;
    std::cout<< "testing card FaceAnimal C is 0 enum: " << ((int)((FaceAnimal)*(p)))<< std::endl;
    std::cout<< "testing card FaceAnimal: " << ((int)((FaceAnimal)*(p)) == 0? "passed":"failed" )<< std::endl;
    std::cout<< "testing card FaceBackground r is 0: " << ((int)((FaceBackground)*(p))) << std::endl;
    std::cout<< "testing card FaceBackground r is 0: " << ((int)((FaceBackground)*(p)) == 0? "passed":"failed") << std::endl;
    std::cout<< "Getting next Card \n" << std::endl;
    p = a.getNext();
    (*p).print();
    std::cout<< "print() passed" << std::endl;
    std::cout<< "testing card FaceAnimal C is 0 enum: " << ((int)((FaceAnimal)*(p)))<< std::endl;
    std::cout<< "testing card FaceAnimal: " << ((int)((FaceAnimal)*(p)) == 0? "passed":"failed" )<< std::endl;
    std::cout<< "testing card FaceBackground g is 1: " << ((int)((FaceBackground)*(p))) << std::endl;
    std::cout<< "testing card FaceBackground g is 1: " << ((int)((FaceBackground)*(p)) == 1? "passed":"failed") << std::endl;
    // (int)((FaceBackground)*(p));
    // while(!a.isEmpty()){
        // (*a.getNext()).print();
    // }
    // std::cout<< "Printing" << std::endl;

    // std::cout<<  << std::endl;
    
    return 0;
}
#endif