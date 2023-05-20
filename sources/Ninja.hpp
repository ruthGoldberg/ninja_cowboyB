#pragma once
#include "Character.hpp"
namespace ariel{
    class Ninja: public Character
    {
    private:
        int speed;
    public:
        Ninja(string name , Point location , int speed , int points);
        //~Ninja() override = default;
        virtual void move(Character* enemy);
        virtual void slash(Character* enemy);
        string print() override;
        int getSpeed()const;
    };
    
}