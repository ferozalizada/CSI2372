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

            if(i == 0){
                player = game.getPlayer(Side::top);
               
            }else if(i == 1){
                player = game.getPlayer(Side::bottom);
            }else if(i == 2){
                player = game.getPlayer(Side::left);
            }else if(i == 3){
                player = game.getPlayer(Side::right);
            }

            cout << endl << "Cards in front of " << player.getName() << endl;

        }

    }

    /*if(gameMode == "N"){
        
    } else if(gameMode == "E"){
    } */

    return 0;
}
#endif