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



#ifdef TEST_DECK_
#include "carddeck.h"
int main(){
    std::cout<< "Testing DecK class\n" << std::endl;
    // std::cout<< "Testing make_createDeck()" << std::endl;
    Deck<Card>& a = CardDeck::make_CardDeck();
    std::cout<< "Testing isEmpty on full deck a: "<< ((a.isEmpty() == false)? "passed": "failed")<< std::endl;
    Card* p = a.getNext();
    std::cout<< "Testing getNext() to get fisrt element: " << std::endl;
    (*p).print();
    p = a.getNext();
    std::cout<< "Testing getNext() to get fisrt element: " << std::endl;
    (*p).print();
    std::cout<< "Testing shuffle() so" << std::endl;
    a.shuffle();
    std::cout<< "Testing getNext() to get fisrt element: " << std::endl;
    (*p).print();
    while(!a.isEmpty()){
        Card* p = a.getNext();
    }
    if(a.getNext() == nullptr){
        std::cout<< "Deck is empty pointing to null " << std::endl;
    }

    return 0;
}
#endif