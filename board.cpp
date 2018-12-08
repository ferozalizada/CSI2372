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
    // std::cout<< "\nrestting() \n" << std::endl;
    memset(boardFlag, 0, row_board*col_board);
}

void Board::setBoard(){
    std::cout<<"Setting Board and making the string rep of the Cards\n" <<std::endl;
    std::stringstream buffer;
    std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());    
     for(int i = 0; i < row_board; i++){
        for(int j = 0; j < col_board; j++){
            deckBoard[i][j] = mydeck1.getNext();
            // (*deckBoard[i][j]).print();
        }
    }
    text = buffer.str();
    std::replace(text.begin(), text.end(), '\n', ' ');
    std::cout.rdbuf(old);
}

void Board::setScreen(){
    int counter = 0;
    for (int i = 0; i < row; i++){
        counter ++;
        if (counter != 4 ){
            screen[i] = "zzz zzz zzz zzz zzz";
        }else{
            counter = 0;
            screen[i] = "                   ";
        }
    }
}

void Board::updateScreen(){
    int counter = 0;
    for (int i = 0; i < row_board; i++){
        for (int j = 0; j < col_board; j++){
            if(boardFlag[i][j] == true){
                // std::cout<< i << j <<std::endl;
                screen[i].replace(0,3, "AAA");
                screen[i+1].replace(0,3, "AXA");
                screen[i+2].replace(0,3, "AAA");
            }
        }
    }
}

void Board::print(){
    int counter = 0;
    char coordinates = ' ';
    for(int i = 0; i< row; i++){
        counter ++;
        std::cout<< coordinates << screen[i] << std::endl;  
    }
}

#if 1
int main(){
    Board b = Board();
    b.setBoard();
    // std::cout<< "back to console!";
    b.setScreen();
    b.turnFaceUp(Letter::A, Number::ONE);
    b.turnFaceUp(Letter::A, Number::TWO);
    b.turnFaceUp(Letter::A, Number::THREE);
    b.updateScreen();
    b.print();
    b.reset();
}

#endif