#include <iostream>
#include "SmartTeam.hpp"
#include "Team.hpp"
using namespace ariel;
using namespace std;

SmartTeam :: SmartTeam(Character* leader): Team(leader){}

void SmartTeam:: attack(Team* against ) {
    if(against == nullptr)
        throw invalid_argument("nullptr");
    if(against->stillAlive() == 0)
        throw invalid_argument("team is dead");
    if(getLeader() == nullptr)
        throw runtime_error("leader is nullptr");
    if(!(getLeader()->isAlive())){
        replaceLeader();
        if(getLeader() == nullptr)
            throw runtime_error("All team members are dead");
    }
    Character* target = toAttack(against);
    for(auto character : getTeam()){
        if(character == nullptr)
            throw runtime_error("character is nullptr");
        if(!character->isAlive())
            continue;
        if(auto *cowboy = dynamic_cast<Cowboy *>(character)){
            if(!target->isAlive()){
                target = toAttack(against);
            }
            if(target == nullptr)
                break;
            cowboyAttack(cowboy , target);
        }
        else if(auto *ninja = dynamic_cast<Ninja *>(character)){
            if(character == nullptr)
                throw runtime_error("character is nullptr");
            if(!target->isAlive()){
                target = toAttack(against);
            }
            if(target == nullptr)
                break;
            ninjaAttack(ninja , target);
        }
    }
}
void SmartTeam:: print(){
    for(auto character : getTeam()){
        if(auto *cowboy = dynamic_cast<Cowboy *>(character)){
            cout << cowboy->print() << endl;
        }
        else if(auto *ninja = dynamic_cast<Ninja *>(character)){
            cout << ninja->print() << endl;
        }
    }
}

Character* SmartTeam:: toAttack(Team * enemy){
    int maxCount = 0;
    Character * candidate = nullptr;
    for(auto character : enemy->getTeam()){
        if(character == nullptr || !character->isAlive())
            continue;
        if(checkNinja()){
                int countDistance = 0;
            for(auto teamate : getTeam()){
                if(teamate == nullptr || !teamate->isAlive())
                    continue;
                if(auto *ninja = dynamic_cast<Ninja*>(teamate)){
                    if(teamate->distance(character) < 1){
                        countDistance++;
                    }
                }
            }
            if(countDistance > maxCount){
                maxCount = countDistance;
                candidate = character;
            }
        }else{
            
        }
        return candidate;
    }
}

bool SmartTeam:: checkNinja(){
    for(auto character : getTeam()){
        if(auto *ninja = dynamic_cast<Ninja*>(character))
            return true;
    }
    return false;
}