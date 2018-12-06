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
FaceAnimal Card::getAnimal(){
    return m_faceAnimal;
}
FaceBackground Card::getColour(){
    return m_faceBackground;
}
    
void Card::print(){
     Card c(FaceAnimal::Penguin, FaceBackground::Red);
    for(int row = 0; row < c.getNRows(); ++row){
        std::string rowString = c(row);
        std::cout << rowString << std::endl;
    }
}



Card::operator FaceAnimal() const {
    return m_faceAnimal;
}

Card::operator FaceBackground() const {
    return m_faceBackground;
}