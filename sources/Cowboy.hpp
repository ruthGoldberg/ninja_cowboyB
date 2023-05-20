#pragma once
#include "Character.hpp"
namespace ariel{
    class Cowboy : public Character
    {
    private:
        int bullets;
    public:
        //Cowboy();
        Cowboy(string name, Point location);
        //Cowboy();
        //~Cowboy() override = default;
        void shoot(Character* enemy);
        bool hasboolets();
        void reload();
        int getBullets()const;
        string print() override;
        
    };
}

