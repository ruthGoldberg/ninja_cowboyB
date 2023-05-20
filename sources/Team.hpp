#pragma once
#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>

namespace ariel{
    class Team
    {
    private:
        std::vector<Character *> team;
        Character* leader;
        int players = 0;
    public:
        Team(Character* leader);
        virtual ~Team();
        Team& operator=(const Team&) = delete;
        Team (Team& other) = delete;
        Team (Team&& other) = delete;
        Team& operator=(const Team&&) = delete;
        void add(Character* player);
        virtual void attack(Team* against );
        int stillAlive();
        virtual void print();
        Character* getLeader()const;
        void replaceLeader();
        virtual Character* toAttack(Team * enemy);
        void cowboyAttack(Cowboy* cowboy , Character* target);
        void ninjaAttack(Ninja* cowboy , Character* target);
        std::vector<Character*> getTeam()const;
        int getPlayers() const;
        void setLeader(Character* newLeader);
    };
    
}