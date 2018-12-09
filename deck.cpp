#include "deck.h"

template <class C>
void Deck<C>::shuffle(){
    auto rng = std::default_random_engine {};
    std::shuffle(deck.begin(), deck.end(),rng);
}

template <class C>
bool Deck<C>::isEmpty() const{
    return deck.empty();
}
//needs better handling of stack mem
template<class C>
C* Deck<C>::getNext(){
    C* c;
    if( !deck.empty() || deck.size() > 0){
        c =  deck[index++];
        deck.pop_back();
        return c;
    } else {
        return nullptr;
    }
}

// Explicit instantiation
template class Deck<Card>;
template class Deck<Reward>;



#ifdef DEBUG_DECK
int main(){
    std::cout<< "Testing CardDeck class\n" << std::endl;
    std::cout<< "Testing make_createDeck()" << std::endl;
    Deck<Card>& a = CardDeck::make_CardDeck();
    
    while(!a.isEmpty()){
        a.getNext();
    }
    return 0;
}
#endif