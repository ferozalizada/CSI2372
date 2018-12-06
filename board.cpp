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
    std::cout<< "restting() \n" << std::endl;
    memset(boardFlag, 0, row_board*col_board);
    //throws seg fault
}

void Board::setBoard(){
    std::cout<<"Setting Board\n" <<std::endl;
    // std::string mystr = 
     for(int i = 0; i < row_board; i++){
        for(int j = 0; j < col_board; j++){
            deckBoard[i][j] = mydeck1.getNext();
            // std::cout<< *(deckBoard[i][j]);
            //   getline (std::cout, mystr);

            // std::ostream;

        }
    }
}
void Board::updateScreen(){
    std::cout<< "Updating Screen!\n" << std::endl;;
    memset(screen,'z',16*16);
    
     (*deckBoard[0][0]).print();
    // std::cout<< "enum value: "<< (int)((FaceAnimal) (*deckBoard[0][0])) << std::endl;;
    // std::cout<< "enum value: "<< (int)((FaceBackground) (*deckBoard[0][0])) << std::endl;;

    // for (int i =0; i < row; i++){
    //     for(int j =0; j < col; j++){
    //         std::cout << screen[i][j];
    //     }
    //     std::cout <<"\n"<< std::endl;
    // }
}

#if 1
int main(){
    Board b = Board();
    b.setBoard();
    b.updateScreen();
    std::cout<< "before"<< std::endl;
    b.turnFaceUp(Letter::A, Number::ONE);
    b.turnFaceUp(Letter::A, Number::TWO);
    // b.print();
    b.reset();
    // b.print();
}

#endif