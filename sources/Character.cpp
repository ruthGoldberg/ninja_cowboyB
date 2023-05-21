#include <iostream>
#include "Character.hpp"
using namespace ariel;
using namespace std;

Character :: Character() : location(Point(0,0)) , name("ruth") , points(0) , inTeam(false){}

Character :: Character(Point local , string name , int points):
location(local),name(name),points(points) , inTeam(false){}

Character :: Character(Character& other) = default;

Character ::Character(Character&& other) noexcept{
     
    this->name = move(other.getName());
    this->location = move(other.getLocation());
    this->points = move(other.getPoints());
    this->inTeam = move(other.getInTeam());

    other.name = "";
    other.location = Point();
    other.points = 0;
    other.inTeam = false;
}

Character &Character::operator=(const Character &other){
    if(this == &other)
        return *this;
    this->name = other.getName();
    this->location = other.getLocation();
    this->points = other.getPoints();
    this->inTeam = other.getInTeam();
    return *this;

}

Character& Character::operator=(Character&& other) noexcept {
        if (this != &other) {
            this->name = move(other.getName());
            this->location = move(other.getLocation());
            this->points = move(other.getPoints());
            this->inTeam = move(other.getInTeam());
        }
        return *this;
    }
bool Character :: isAlive(){
    if(this->points > 0){
        return true;
    }
    return false;
    //return points > 0;
}
double Character :: distance(Character* other){
    return location.distance(other->location);
}
void Character ::hit(int points){
    if(points < 0)
        throw invalid_argument("negative points");
    
    this->points-=points;
    
}
string Character ::getName()const{
    return name;
}
const Point& Character ::getLocation()const{
    return this->location;
}

int Character:: getPoints()const{
    return points;
}

bool Character:: getInTeam()const{
    return inTeam;
}
void Character:: setInTeam(bool inTeam){
    this->inTeam = inTeam;
}

void Character:: setLocation(Point& newLocation){
    this->location = newLocation;
}