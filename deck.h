#ifndef _DECK_H_
#define _DECK_H_

#include <vector>
#include <algorithm>

enum class DeckType { Card, Reward };


template <class C>
class Deck<C>

void shuffle(); 

C* getNext() ;

bool isEmpty() const;

#endif