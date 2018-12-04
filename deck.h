#ifndef DECK_H_
#define DECK_H_

#include "card.h"
#include "reward.h"
#include <vector>
#include <algorithm>
#include <random>


enum class DeckType { Card, Reward };


template <class C>
class Deck{
    private:
        int index = 0;

        virtual Deck<C>& createDeck() = 0;
    protected:
        std::vector<C*> deck;
        //can be any other function...
        //where does it say to include a virtual func?
        virtual void add() = 0;

    public:
        void shuffle(); 
        C* getNext() ;
        bool isEmpty() const;
};
#endif
