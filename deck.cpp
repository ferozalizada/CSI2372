#include "deck.h"

template <class C>
void Deck<C>::shuffle(){
    auto rng = std::default_random_engine {};
// std::shuffle(std::begin(cards_), std::end(cards_), rng);
    std::shuffle(deck.begin(), deck.end(),rng);
}

template <class C>
bool Deck<C>::isEmpty() const{
    return (deck.empty());
}

template<class C>
C* Deck<C>::getNext(){
    if( !deck.empty() || deck.size() > 0){
        return deck[index++];
    } else {
        return nullptr;
    }
}

// Explicit instantiation
template class Deck<Card>;
template class Deck<Reward>;