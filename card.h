#ifndef _CARD_H_
#define _CARD_H_

#include<iostream>
#include <string>

enum class FaceAnimal { Crab, Penguin, Octopus, Turtle, Walrus };
enum class FaceBackground {  Red, Green, Purple, Blue, Yellow };

class Card{
    private:
        Card(FaceAnimal, FaceBackground);
    protected:
        static const int m_numberOfRows = 3;
        static const int m_numberOfColumns = 3;
        
        std::string card[m_numberOfRows];
        FaceAnimal m_faceAnimal;
        FaceBackground m_faceBackground;

        // no assignemtn or copy
        Card(const Card&) = delete;
        Card& operator=( const Card& ) = delete;
        
        // Constructor

        std::string operator()(int);
        void createCard(FaceAnimal&, FaceBackground&);
        char getAnimalLetter(FaceAnimal&);
        char getColorLetter(FaceBackground&);
        int getNRows();

        FaceAnimal getAnimal();
        FaceBackground getColour();
        
    public:

        friend std::ostream& operator<<(std::ostream&, Card&);
        operator FaceAnimal() const;
        operator FaceBackground() const;
        friend class CardDeck;
};

#endif