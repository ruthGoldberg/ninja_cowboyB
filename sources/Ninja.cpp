#include <iostream>
#include "Ninja.hpp"
using namespace ariel;
using namespace std;

Ninja :: Ninja(string name , Point location , int speed , int points):
Character(location , name , points) , speed(speed){}

void Ninja :: move(Character* enemy){
    Point newLocation = Point::moveTowards(this->getLocation() ,enemy->getLocation() ,speed);
    setLocation( newLocation );
}
void Ninja ::slash(Character* enemy){
    if(enemy == nullptr){
        throw runtime_error("nullptr");
    }
    if(enemy == this)
        throw runtime_error("Can not slash its self");
    if(!enemy->isAlive()){
        throw runtime_error("Enemy is dead");
    }
    if(!isAlive()){
        throw runtime_error("Character is dead");
    }
    if(this->getLocation().distance(enemy->getLocation()) < 1){
        enemy->hit(40);
    }
}
int Ninja :: getSpeed()const{
    return speed;
}
string Ninja:: print(){
     string output = "N ("+this->getName()+") location: "+ this->getLocation().print();
    if(isAlive()){
        output +=" points: "+to_string(this->getPoints());
    }
    return output;
}