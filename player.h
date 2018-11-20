#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <iostream>
#include "reward.h"

enum class Side { TOP, BOTTOM, LEFT, RIGHT };

class Player{
    //stated for better readibility
    private:
        bool m_EndOfGame;
        bool m_Status;
        Side m_Position;
        std::string m_Name;
        int m_NRubies;
        std::string positionToString() const ;

    public:
        Player() = default;
        Player(std::string name);
        std::string getName() const;
        void setActive(bool);
        bool isActive();
        int getNRubies() const;
        void addReward( const Reward& );
        void setDisplayMode( bool endOfGame );
        Side getSide();
        void setSide(Side);
        friend std::ostream& operator<<(std::ostream& os, const Player& player);
};
#endif