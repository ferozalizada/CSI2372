#ifndef _CARD_H_
#define _CARD_H_

#include<iostream>
#include <string>
/*
* Enums to limit the creation of the faceAnimal
*/
enum class FaceAnimal { Crab, Penguin, Octopus, Turtle, Walrus };
/*
* Enums to limit the creation of FaceBackgroud for the card
*/
enum class FaceBackground {  Red, Green, Purple, Blue, Yellow };

/*
* Card class to represent a Card in the game
*/
class Card{
    /*
    * Protected Member Variables
    */
    protected:
        /*
        * const size of the array representation of the card
        */
        static const int m_numberOfRows = 3;
        static const int m_numberOfColumns = 3;
        
        /*
        * Array of string to represent card
        */  
        std::string card[m_numberOfRows];
        
        /*
        * The type of animal the card has
        */
        FaceAnimal m_faceAnimal;
        
        /*
        * The type of background the card has
        */
        FaceBackground m_faceBackground;

        /*
        * Deleted copy constructor
        */
        Card(const Card&) = delete;
        
        /*
        * Deleted assignment constructor
        */
        Card& operator=( const Card& ) = delete;
        
        /*
        * Constructor for the card
        * @param FaceAnimal of type enum
        * @param FaceBackground Enum
        */
        Card(FaceAnimal, FaceBackground);

        /*
        * override operator for the operator()
        * @param int
        * @returns a string from the card string array at that index
        */
        std::string operator()(int);

        /*
        * Creates a card given a reference to FaceAnimal and FaceBackground
        * @param FaceAnimal Enum
        * @param FaceBackground Enum
        */
        void createCard(FaceAnimal&, FaceBackground&);
       
        /*
        * Getter for the type of Animal the card is
        * @param FaceAnimal Enum
        * @return char of type of animal the card is 
        */
        char getAnimalLetter(FaceAnimal&);
       
        /*
        * Getter for the type of Color the card is
        * @param FaceBackground Enum
        * @return char of type of Color the card is 
        */
        char getColorLetter(FaceBackground&);
       
        /*
        * Getter for the type of Animal the card is
        * @return number of rows
        */
        int getNRows();
       
    public:
        /*
        * Helper method to print a card
        */
        void print();

        /*
        * Conversion operator for the type of Animal the card is
        * @return a enum of the FaceAnimal
        */
        operator FaceAnimal() const;
       
        /*
        * Conversion operator for the type of FaceBackground the card is
        * @return a enum of the FaceBackground
        */
        operator FaceBackground() const;
       
        /*
        * friend access to CardDeck
        */
        friend class CardDeck;
};

#endif