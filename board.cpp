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
    memset(boardFlag, 0, row_board*col_board);
}

void Board::setBoard(){
    std::cout<<"Setting Board and making the string rep of the Cards\n" <<std::endl;
    // std::stringstream buffer;
    // std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());    
     for(int i = 0; i < row_board; i++){
        for(int j = 0; j < col_board; j++){
            deckBoard[i][j] = mydeck1.getNext();
            // (*deckBoard[i][j]).print();
        }
    }
    // text = buffer.str();
    // std::replace(text.begin(), text.end(), '\n', ' ');
    // std::cout.rdbuf(old);
}

void Board::setScreen(){
    int counter = 0;
    for (int i = 0; i < row; i++){
        counter ++;
            screen[i] = "zzz zzz zzz zzz zzz";
        if (counter != 4 ){
        }else{
            counter = 0;
            screen[i] = "                   ";
        }
    }
}

void Board::updateScreen(){
    
    for(int i = 0; i < row_board; i++){
        for(int j = 0; j < col_board; j++){
            // std:: cout << boardFlag[i][j];
            // "rrr rCr rrr "
            if(boardFlag[i][j] == true){
                std::stringstream buffer;
                std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());    
                (*deckBoard[i][j]).print();
                std::string text = buffer.str();

                std::replace(text.begin(), text.end(), '\n', ' ');
                sample = text;
                screen[(i*4)+0].replace(j*4, 3, text.substr(0, 3));
                screen[(i*4)+1].replace(j*4, 3, text.substr(4, 3));
                screen[(i*4)+2].replace(j*4, 3, text.substr(8, 3));
                buffer.str("");
                std::cout.rdbuf(old);
            }
        }
        // std::cout<< std::endl;
    }
    // std::cout<<"Here is my shit" <<text << std:: endl;
}

void Board::print(){
    // (*deckBoard[0][0]).print();
    // (*deckBoard[0][1]).print();
    for(int i = 0; i < row; i++){
        std::cout<< screen[i] << std::endl;
    }
    // std::cout<< "\'"<< sample<< "\'" << std::endl;
}
#if 1
int main(){
    Board b = Board();
    b.setBoard();;
    b.setScreen();
    b.turnFaceUp(Letter::A, Number::ONE);
    b.turnFaceUp(Letter::B, Number::ONE);
    b.turnFaceUp(Letter::C, Number::ONE);
    b.turnFaceUp(Letter::D, Number::ONE);
    b.turnFaceUp(Letter::E, Number::ONE);
    b.turnFaceUp(Letter::E, Number::FIVE);
    b.turnFaceUp(Letter::D, Number::THREE);
    b.updateScreen();
    b.print();
    b.reset();
}

#endif