#ifndef CARDDECK_H
#define CARDDECK_H

#include "deck.h"
#include "card.h"

/*
* CardDeck class to create a deck of card derived from Deck class
*/
class CardDeck: public Deck<Card>{
    protected:
        /*
        * Helper function which creates the cards to add to deck
        */
        void add();
       
        /*
        * default constructor 
        */
        CardDeck() = default;
        
        /*
        * conversion operator to get the animal enum
        * @return FaceAnimal of the card based on index
        */
        FaceAnimal nextAnimal(int);
       
        /*
        * conversion operator to get the animal enum
        * @return FaceBackground of the card based on index
        */
        FaceBackground nextColor(int);
        
        /*
        * deleted copy constructor
        */
        CardDeck(const CardDeck&) = delete;
       
        /*
        * deleted assignment operator
        */
        CardDeck& operator=(const CardDeck&) = delete;
        
        /*
        * Abstract factory method to create deck of Card derived from parent
        */
        CardDeck& createDeck();

    public:
        /*
        * static method to create a deck of cards
        * @return reference
        */

        static CardDeck& make_CardDeck();
};
#endif