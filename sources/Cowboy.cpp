#include <iostream>
#include "Cowboy.hpp"
using namespace ariel;
using namespace std;

Cowboy :: Cowboy(string name, Point location):
Character(location,name,110) ,bullets(6){}

void Cowboy:: shoot(Character* enemy){
    if(enemy == this)
        throw runtime_error("Can not shoot is self");
    if(enemy == nullptr){
        throw runtime_error("nullptr");
    }
    if(!enemy->isAlive()){
        throw runtime_error("Enemy is dead");
    }
    if(isAlive() ){
        if( hasboolets()){
            enemy->hit(10);
            bullets--;
        }
    }else{
        throw runtime_error("Character is dead");
    }
    
}
bool Cowboy:: hasboolets(){
    return bullets > 0;
}
void Cowboy:: reload(){
    if(!isAlive())
        throw runtime_error("cowboy is dead");
    bullets = 6;
}
int Cowboy :: getBullets()const{
    return bullets;
}
//TODO: print function
string Cowboy ::print(){
    string output = "C ("+this->getName()+") location: "+ this->getLocation().print();
    if(isAlive()){
        output +=" points: "+to_string(this->getPoints());
    }
    return output;
}