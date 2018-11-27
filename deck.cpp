#include "deck.h"

template <class C>
void Deck<C>::shuffle(){
    random_shuffle(deck.begin(), deck.end());
}
template <class C>
bool Deck<C>::isEmpty() const{
    return (deck.isEmpty());
}


template<class C>
C* Deck<C>::getNext(){
    if( !deck.isEmpty() || deck.size() > 0){
        return deck[index++];
    } else {
        return nullptr;
    }
}

// template <class C>
// void Deck<C>::add(){
//     return;
// }
//can't i just make it virtual???? call it in the stupid shit

template <class C>
Deck<C>* Deck<C>::createDeck(DeckType& type){
    if(type == DeckType::Card){
        // return new CardDeck();
        return;
    } else if(type == DeckType::Reward){
        // return new RewardDeck();
        return;
    }
}
