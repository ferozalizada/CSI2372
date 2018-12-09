#include <iostream>
#include <string>
#include <climits>

#include "player.h"
#include "carddeck.h"
#include "game.h"
#include "rules.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;


#if 0
int main(){
    string gameMode = "";
    int numberOfPlayers = 0;

    cout << endl;
    cout << "Welcome to the game Memoarrr!" << endl;
    cout << "Come join the adventure and challenge your friends in this memory card game" << endl << endl;
    cout << "Would you like to play in [N]ormal or [E]xpert mode ?" << endl;
   
    while(gameMode != "N" && gameMode != "E"){
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
    
    Game game;

    // create players
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

    Rules rules;

    cout << game;

    /*if(gameMode == "N"){
        
    } else if(gameMode == "E"){
    } */

    return 0;
}
#endif