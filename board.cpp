#include "board.h"

void Board::print(){
    for(int i = 0; i < row_board; i++){
        for(int j = 0; j< col_board; j++){
            std::cout<< boardFlag[i][j];
        }
        std::cout<< std::endl;
    }
}

bool Board::isFaceUp(const Letter& _letter, const Number& _number) const{
    return (boardFlag[(int)_letter][(int)_number]);
}

bool Board::turnFaceUp(const Letter& _letter, const Number& _number){
    return boardFlag[(int)_letter][(int)_number] = true;
}

bool Board::turnFaceDown(const Letter& _letter, const Number& _number){
    return boardFlag[(int)_letter][(int)_number] = false;
}

Card* Board::getCard(const Letter& _letter, const Number& _number){
    // return cardDeck[(int)_letter][(int)_number] ;
}

void Board::setCard(const Letter& _letter, const Number& _number, Card* card){
    // cardDeck[(int)_letter][(int)_number] = &card;
}

void Board::reset(){
    // shuffle
    std::cout<< "restting()" << std::endl;
}

int main(){
    Board b = Board();
    std::cout<< "before"<< std::endl;
    b.print();
    b.turnFaceUp(Letter::A, Number::ONE);
    b.turnFaceDown(Letter::A, Number::THREE);
    std::cout<< "after"<< std::endl;
    b.print();
    std::cout<< "position 1 is face: "<< static_cast<bool>(b.isFaceUp(Letter::A, Number::ONE) )<< std::endl;
    std::cout<< "position 2 is face: "<< (static_cast<bool>(b.isFaceUp(Letter::A, Number::TWO) ))<< std::endl;
}

