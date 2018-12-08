#include "board.h"
#define TEST_BOARD_

// constructor


const char* OutOfRange::what() const throw(){
    return "OutOfRange";
}

bool Board::isFaceUp(const Letter& _letter, const Number& _number) const{
    try{
        if((_letter > Letter::E) && (_number > Number::FIVE)){
            throw "OutOfRange";
        }else{
            return (boardFlag[(int)_letter][(int)_number]);
        }
    } catch(...){
        std::cout<< "OutOfRange" << std::endl;
    }
    return (boardFlag[(int)_letter][(int)_number]);
}

bool Board::turnFaceUp(const Letter& _letter, const Number& _number){
    try{
        if((_letter > Letter::E) && (_number > Number::FIVE)){
            throw "OutOfRange";
        }else{
            return boardFlag[(int)_letter][(int)_number] = true;
        }
    } catch(...){
        std::cout<< "OutOfRange" << std::endl;
    }
    return boardFlag[(int)_letter][(int)_number] = true;
}

bool Board::turnFaceDown(const Letter& _letter, const Number& _number){
    try{
        if((_letter > Letter::E) && (_number > Number::FIVE)){
            throw "OutOfRange";
        }else{
            return boardFlag[(int)_letter][(int)_number] = false;
        }
    } catch(...){
        std::cout<< "OutOfRange" << std::endl;
    }
    return boardFlag[(int)_letter][(int)_number] = false;
}

Card* Board::getCard(const Letter& _letter, const Number& _number){
     try{
        if((_letter > Letter::E) && (_number > Number::FIVE)){
            throw "OutOfRange";
        }else{
            return deckBoard[(int)_letter][(int)_number];
        }
    } catch(...){
        std::cout<< "OutOfRange" << std::endl;
    }
    return deckBoard[(int)_letter][(int)_number];
}

void Board::setCard(const Letter& _letter, const Number& _number, Card* card){
    try{
        if((_letter > Letter::E) && (_number > Number::FIVE)){
            throw "OutOfRange";
        }else{
            deckBoard[(int)_letter][(int)_number] = card;
        }
    } catch(...){
        std::cout<< "OutOfRange" << std::endl;
    }
}

void Board::reset(){
    std::memset(boardFlag, 1, row_board*col_board);
}

Board::Board(){
    mydeck1.shuffle();
    // mydeck1.getNext();
    for(int i = 0; i < row_board; i++){
        for(int j = 0; j < col_board; j++){
            // if(i == j && i == 2) {
            //     std::cout<< mydeck1.getNext();
                deckBoard[i][j] = mydeck1.getNext();
            // } else{
            // }
        }
    }
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
    screen[8] = "zzz zzz     zzz zzz";
    screen[9] = "zzz zzz     zzz zzz";
    screen[10]= "zzz zzz     zzz zzz";
}

void Board::updateScreen(){
    for(int i = 0; i < row_board; i++){
        for(int j = 0; j < col_board; j++){
            if(boardFlag[i][j] == true){
                std::stringstream buffer;
                std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());    
                (*deckBoard[i][j]).print();
                std::string text = buffer.str();
                std::replace(text.begin(), text.end(), '\n', ' ');
                screen[(i*4)+0].replace(j*4, 3, text.substr(0, 3));
                screen[(i*4)+1].replace(j*4, 3, text.substr(4, 3));
                screen[(i*4)+2].replace(j*4, 3, text.substr(8, 3));
                buffer.str("");
                std::cout.rdbuf(old);
            }
        }
    }
}

std::ostream& operator<<(std::ostream& os, Board board){
    char coordinate = 'A';
    for(int i = 0; i < board.row; i++){ 
        if( ((i+3)%4 == 0) ){
            os<< coordinate++ << "  " <<board.screen[i] << std::endl;
        }else{
            os<< "   " << board.screen[i] << std::endl;
        }
    }
    std::cout << "\n    1   2   3   4   5" << std::endl;
    return os;
}
#ifdef TEST_BOARD_
int main(){
    Board b = Board();
    b.reset();
    // b.setBoard();
    b.setScreen();
    // b.turnFaceUp(Letter::A, Number::ONE);
    // b.turnFaceUp(Letter::B, Number::ONE);
    // b.turnFaceUp(Letter::C, Number::ONE);
    // b.turnFaceUp(Letter::D, Number::ONE);
    // b.turnFaceUp(Letter::E, Number::ONE);
    // b.turnFaceUp(Letter::E, Number::FIVE);
    // b.turnFaceUp(Letter::D, Number::THREE);
    // b.turnFaceUp(Letter::C, Number::THREE);
    b.updateScreen();
    std::cout<< b;
    b.reset();
    b.isFaceUp(Letter::F, Number::Six);
}

#endif