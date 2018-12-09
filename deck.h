#ifndef DECK_H_
#define DECK_H_

#include "card.h"
#include "reward.h"
#include <vector>
#include <algorithm>
#include <random>



/*
* Template class to create a deck, stores it in a vector
*/
template <class C>
class Deck{
    protected:
        /*
        * reprensents the top of deck
        */      
        int index = 0;

        /*
        * abstract factory method
        */
        virtual Deck<C>& createDeck() = 0;
        std::vector<C*> deck;
        
        /*
        * Virtual add method to add cards to the deck
        */
        virtual void add() = 0;

    public:

        /*
        * Helper function to shuffle the deck elements
        */
        void shuffle(); 

        /*
        * helper function to get the next element in the deck
        * @returns pointer to the item
        */
        C* getNext() ;

        /*
        * helper fucntion to see status of deck
        * @return true if empty else false
        */
        bool isEmpty() const;
};
#endif
