#include "board.h"

const char* OutOfRange::what() const throw(){
    return "OutOfRange";
}

bool Board::isFaceUp(const Letter& _letter, const Number& _number) const{
    try{
        if((_letter > Letter::E) && (_number > Number::FIVE)){
            throw OutOfRange();
        }else{
            return (boardFlag[(int)_letter][(int)_number]);
            // updateScreen();
        }
    } catch(OutOfRange e){
        std::cout<< e.what()<< std::endl;
    }
    return (boardFlag[(int)_letter][(int)_number]);
}

bool Board::turnFaceUp(const Letter& _letter, const Number& _number){
    try{
        if((_letter > Letter::E) && (_number > Number::FIVE)){
            throw "OutOfRange";
        }else{
            boardFlag[(int)_letter][(int)_number] = true;
            updateScreen();
            return boardFlag[(int)_letter][(int)_number];

        }
    } catch(...){
        std::cout<< "OutOfRange" << std::endl;
    }

    updateScreen();
    return boardFlag[(int)_letter][(int)_number] = true;
}

bool Board::turnFaceDown(const Letter& _letter, const Number& _number){
    try{
        if((_letter > Letter::E) && (_number > Number::FIVE)){
            throw "OutOfRange";
        }else{
            boardFlag[(int)_letter][(int)_number] = false;
            updateScreen();
            return boardFlag[(int)_letter][(int)_number];
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
            updateScreen();

        }
    } catch(...){
        std::cout<< "OutOfRange" << std::endl;
    }

}

void Board::reset(){
    //std::memset(boardFlag, 1, row_board*col_board);
    for(int i = 0; i < row_board; i++){
        for(int j = 0; j < col_board; j++){
            boardFlag[i][j] = 0;
        }
    }
    updateScreen();
}

Board::Board(){
    mydeck1.shuffle();
    try{
        // mydeck1.getNext();
        for(int i = 0; i < row_board; i++){
            for(int j = 0; j < col_board; j++){
                // if(i == j && i == 2) {
                //     std::cout<< mydeck1.getNext();
                if(mydeck1.isEmpty()){
                    throw "NoMoreCards";
                } else{
                    deckBoard[i][j] = mydeck1.getNext();
                }
            }
        }

        setScreen();
        reset();
        
    } catch(...){
        std::cout<< "NoMoreCards"<< std::endl;
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
    updateScreen();
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
    std::cout<< "Testing Rules class\n" << std::endl;
    Board board = Board();
    // std::cout << board << std::endl;
    std::cout << "printing of Board and Construction passed" << std::endl;
    std::cout << board << std::endl;
    std::cout<< "testing isFaceUp()" << (board.isFaceUp(Letter::A, Number::ONE) == 0? "Passed":"Failed" ) << std::endl;
    // std::cout << board << std::endl;
    std::cout<< "testing turnFaceUp()" << (board.turnFaceUp(Letter::A, Number::ONE) == 1? "Passed":"Failed" ) << std::endl;
    std::cout << board << std::endl;
    std::cout<< "testing turnFaceUp()" << (board.turnFaceUp(Letter::A, Number::TWO) == 1? "Passed":"Failed" ) << std::endl;
    std::cout << board << std::endl;
    std::cout<< "testing turnFaceUp()" << (board.turnFaceUp(Letter::A, Number::THREE) == 1? "Passed":"Failed" ) << std::endl;
    std::cout << board << std::endl;
    std::cout<< "testing turnFaceUp()" << (board.turnFaceUp(Letter::A, Number::FOUR) == 1? "Passed":"Failed" ) << std::endl;
    std::cout << board << std::endl;
    std::cout<< "testing turnFaceUp()" << (board.turnFaceUp(Letter::A, Number::FIVE) == 1? "Passed":"Failed" ) << std::endl;
    std::cout << board << std::endl;
    std::cout<< "testing turnFaceDown()" << (board.turnFaceDown(Letter::A, Number::ONE) == 0? "Passed":"Failed" ) << std::endl;
    std::cout<< "testing reset()"<<  std::endl;
    board.reset();
    std::cout << board << std::endl;



    // std::cout<< "Testing is roundOver(): no active player " <<(rule.roundOver(game)  == false? "passed": "failed")<< std::endl;
    // std::cout<< "Testing is GameOver(): " <<(rule.gameOver(game) == 0? "passed": "failed" )<< std::endl;
    // std::cout<< "Testing is isValid(): " <<(game.getCurrentCard()== game.getCurrentCard()? "passed": "failed") << std::endl;
    // std::cout<< "Testing is isValid(): " <<(game.getCurrentCard() == game.getPreviousCard()? "passed": "failed") << std::endl;
    // std::cout<< "Testing is getNextPlayer(): " <<(rule.getNextPlayer(game) )<< std::endl;
    // std::cout<< "Testing is getNextPlayer(): " <<(rule.getNextPlayer(game) )<< std::endl;
    // std::cout<< "Testing is getNextPlayer(): " <<(rule.getNextPlayer(game) )<< std::endl;
    // std::cout<< "Testing is getNextPlayer(): " <<(rule.getNextPlayer(game) )<< std::endl;
    // std::cout<< "Testing is isValid(): " <<(rule.isValid(game) == 1? "passed": "failed") << std::endl;
    // p3.setActive(true);
    // std::cout<< "Testing is roundOver(): " <<(rule.roundOver(game)  == true? "passed": "failed")<< std::endl;

    
    return 0;
}
#endif