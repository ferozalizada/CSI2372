#include <iostream>
#include <string>
#include <climits>

#include "player.h"
#include "carddeck.h"
#include "game.h"
#include "rules.h"
#include "board.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


#if 1
int main(){
    string gameMode = "";
    int numberOfPlayers = 0;

    cout << endl;
    cout << "Welcome to the game Memoarrr!" << endl;
    cout << "Come join the adventure and challenge your friends in this memory card game" << endl << endl;
    cout << "Would you like to play in [N]ormal or [E]xpert mode ?" << endl;
    gameMode.erase(std::remove_if(gameMode.begin(), gameMode.end(), ::isspace), gameMode.end());
    std::transform(gameMode.begin(), gameMode.end(), gameMode.begin(), ::tolower);
    while(gameMode != "n" && gameMode != "e"){
        // keep asking if input invalid
        cout << "Enter [N] or [E] to start playing: ";
        getline(cin, gameMode);
        cout << endl;
    }

    cout << "How many players will join the adventure ?" << endl;

    while( cin.fail() || numberOfPlayers < 2 || numberOfPlayers > 4 ){
        // keep asking if input invalid
        cout << "Enter a number between 2 and 4: ";
        cin >> numberOfPlayers;
        cin.ignore(); // discard key enter pressed after entering number in console

        if(cin.fail()){
            // invalid input
            cin.clear();
            cin.ignore();
        }
    }

    cout << endl;
    
    // create game
    Game game;

    // create players and add them to game
    for(int i = 0; i < numberOfPlayers; i++){
        string pname;

        cout << "Enter the name of player " << std::to_string(i+1) << ": ";
        getline(cin, pname);
        
        Player newPlayer(pname);

        if(i == 0){
            newPlayer.setSide(Side::top);
        }else if(i == 1){
            newPlayer.setSide(Side::bottom);
        }else if(i == 2){
            newPlayer.setSide(Side::left);
        }else if(i == 3){
            newPlayer.setSide(Side::right);
        }
        
        game.addPlayer(newPlayer);
    }

    // create rules
    Rules rules;

    // display game
    cout << game;

    while( !rules.gameOver(game) ){
        game.nextRound();

        cout << endl << "Round " << game.getRound() << endl;

        // Temporarily reveal 3 cards directly in front of the player
        for(int i = 0; i < numberOfPlayers; i++){
            Player player;
            Card* card1;
            Card* card2;
            Card* card3;
            string l1, l2, l3;
            string n1, n2, n3;

            if(i == 0){ 
                player = game.getPlayer(Side::top);
                l1 = l2 = l3 = "A";
                n1 = "2";
                n2 = "3";
                n3 = "4";

                card1 = game.getCard(Letter::A, Number::TWO);
                card2 = game.getCard(Letter::A, Number::THREE);
                card3 = game.getCard(Letter::A, Number::FOUR);

            }else if(i == 1){
                player = game.getPlayer(Side::bottom);
                l1 = l2 = l3 = "E";
                n1 = "2";
                n2 = "3";
                n3 = "4";

                card1 = game.getCard(Letter::E, Number::TWO);
                card2 = game.getCard(Letter::E, Number::THREE);
                card3 = game.getCard(Letter::E, Number::FOUR);

            }else if(i == 2){
                player = game.getPlayer(Side::left);
                l1 = "B";
                l2 = "C";
                l3 = "D";
                n1 = n2 = n3 = "1";

                card1 = game.getCard(Letter::B, Number::ONE);
                card2 = game.getCard(Letter::C, Number::ONE);
                card3 = game.getCard(Letter::D, Number::ONE);

            }else if(i == 3){
                player = game.getPlayer(Side::right);
                l1 = "B";
                l2 = "C";
                l3 = "D";
                n1 = n2 = n3 = "5";

                card1 = game.getCard(Letter::B, Number::FIVE);
                card2 = game.getCard(Letter::C, Number::FIVE);
                card3 = game.getCard(Letter::D, Number::FIVE);
            }

            cout << endl << player.getName() << " take a look at these 3 cards before game starts" << endl << endl;
            
            card1->print(); 
            cout << endl << l1 << n1 << endl << endl;
            cout << "-------------" << endl << endl;

            card2->print();
            cout << endl << l2 << n2 << endl << endl;
            cout << "-------------" << endl << endl;

            card3->print();
            cout << endl << l3 << n3 << endl << endl;
        }

    }

    /*if(gameMode == "N"){
        
    } else if(gameMode == "E"){
    } */

    return 0;
}
#endif