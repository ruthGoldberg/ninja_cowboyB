#pragma once
#include "Team.hpp"
#include <array>
namespace ariel{
    class Team2 : public Team{
        
    public:
    Team2 (Character* leader);
    void attack(Team* against ) override;
    void print() override ;

    };
}