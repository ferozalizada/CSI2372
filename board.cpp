#include "board.h"

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
    return deckBoard[(int)_letter][(int)_number];
}

void Board::setCard(const Letter& _letter, const Number& _number, Card* card){
    deckBoard[(int)_letter][(int)_number] = card;
}

void Board::reset(){
    std::cout<< "restting()" << std::endl;
    memset(boardFlag, 0, row_board*col_board);
    //throws seg fault
}

void Board::setBoard(){
    std::cout<<"Setting Board" <<std::endl;
     for(int i = 0; i < row_board; i++){
        for(int j = 0; j< col_board; j++){
            deckBoard[i][j] = mydeck1.getNext();
            std::cout<< (*deckBoard[i][j]);
        }
        // std::cout << std::endl;
    }
}
void Board::updateScreen(){
    memset(screen,'z',16*16);
    std::cout<< "screen updating";
    for (int i =0; i< row; i++){
        for(int j =0; j < col; j++){
            std::cout << screen[i][j];
        }
        std::cout<< std::endl;
    }
}

void Board::print(){
    for(int i = 0; i < row_board; i++){
        for(int j = 0; j< col_board; j++){
                std::cout<< boardFlag[i][j];
            // if(boardFlag[i][j] == 0){
            // }else{
            //     screen[i][j] = "X";
            //     // screen[i][j] = *deckBoard[i][j];
            // }
            // std::cout<< "\t"; 
        }
        std::cout<< std::endl;
    }
}

#if 0
int main(){
    Board b = Board();
    b.setBoard();
    b.updateScreen();
    std::cout<< "before"<< std::endl;
    b.turnFaceUp(Letter::A, Number::ONE);
    b.turnFaceUp(Letter::A, Number::TWO);
    std::cout<< b.print() << std::endl;
    b.print();
    b.reset();
    b.print();

    b.turnFaceDown(Letter::A, Number::THREE);
    std::cout<< "after"<< std::endl;
    b.print();
    std::cout<< "position 1 is face: "<< static_cast<bool>(b.isFaceUp(Letter::A, Number::ONE) )<< std::endl;
    std::cout<< "position 2 is face: "<< (static_cast<bool>(b.isFaceUp(Letter::A, Number::TWO) ))<< std::endl;
}

#endif