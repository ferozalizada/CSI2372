#ifndef CARDDECK_H
#define CARDDECK_H

#include "deck.h"
#include "card.h"
#include "carddeck.h"

class CardDeck: public Deck<Card>{
    protected:
        void add();
        CardDeck() = default;
        
        
    private:
        FaceAnimal nextAnimal(int);
        // returns the color based on index
        FaceBackground nextColor(int);
        
        //no assignment and copy
        CardDeck(const CardDeck&) = delete;
        CardDeck& operator=(const CardDeck&) = delete;
        
        CardDeck& createDeck();

    public:
        void printDeck();
        static CardDeck& make_CardDeck();
};
#endif