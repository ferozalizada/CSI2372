#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "reward.h"

/*
* Enums Side to limit the number of players
*/
enum class Side { top, bottom, left, right };

/*
* Player class to create a player with a given name
*/
class Player{
    private:
        /*
        * Member variables
        */
        bool m_EndOfGame;
        bool m_Status;
        Side m_Position;
        std::string m_Name;
        int m_NRubies;
        /*
        * Function to change the enum to string
        */
        std::string positionToString() const ;
    public:
        /*
        * default constructor
        */
        Player() = default;
        /*
        * Creates a Player with a given string as the input parameter
        * @param string name of the player
        */
        Player(std::string name);
        /*
        * getter method for the name of the player
        */
        std::string getName() const;
        /*
        * setter for the status of the player
        * @param boolean value to change the status of the player to
        */
        void setActive(bool);
        /*
        * getter method for the status of the player
        */
        bool isActive() const;
        /*
        * getter method for the number rubies of the player
        */
        int getNRubies() const;
        /*
        * Method to create and add reward 
        * @param refernce of a reward object
        */
        void addReward( const Reward& );
        /*
        * setter method for the printing of the player
        * @param bool for to set to.
        */
        void setDisplayMode( bool endOfGame );
        /*
        * getter method for the position/side of the player
        * @returns side
        */
        Side getSide() const;
        /*
        * Setter method for the side of the player
        */
        void setSide(Side);
        /*
        * operation overload to print the player object
        */
        friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif