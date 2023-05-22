#pragma once
#include "Team.hpp"
#include <array>
namespace ariel{
    // In this team we will find the character from the enemy team whos surrounded 
    // by most ninjas because ninja drops the highest amount of points
    class SmartTeam : public Team{
        
    public:
        SmartTeam(Character * leader);  
        void attack(Team* against ) override;
        void print() override;
        Character* toAttack(Team * enemy) override;
        bool checkNinja();
    };
}