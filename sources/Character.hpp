#pragma once
#include <string>
#include "Point.hpp"
using namespace std;
namespace ariel{
class Character
{
    private:
        Point location;
        int points;
        string name;
        bool inTeam;
    public:
        Character();
        Character(Point local , string name ,  int points);
        Character(Character& other);
        Character(Character&& other) noexcept;
        Character& operator=(const Character &other);
        Character& operator=(Character&& other) noexcept;
        virtual ~Character() = default;
        bool isAlive() const;
        double distance(Character* other);
        void hit(int points);
        string getName()const;
        const Point& getLocation() const;
        void setLocation(Point& newLocation);
        virtual string print() = 0;
        int getPoints()const;
        bool getInTeam()const;
        void setInTeam(bool inTeam);
    };
}


