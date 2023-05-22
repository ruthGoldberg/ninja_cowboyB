#include <iostream>
#include <limits>
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
            continue;
        if(!character->isAlive())
            continue;
        if(auto *ninja = dynamic_cast<Ninja *>(character)){
            if(!(target->isAlive())){
                target = toAttack(against);
            }
            if(target == nullptr){
                break;
            }
            ninjaAttack(ninja , target);
        }
    }
    for( auto character :getTeam()){
        if(target == nullptr)
            break;
        if(character == nullptr)
            continue;
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


bool SmartTeam:: checkNinja(){
    for(auto character : getTeam()){
        if(auto *ninja = dynamic_cast<Ninja*>(character))
            return true;
    }
    return false;
}

Character* SmartTeam::toAttack(Team* enemy){
    Character* target = nullptr;
    if(checkNinja()){
        int maxCount = 0, countDistance = 0;
        for(auto candidate : enemy->getTeam()){
            for(auto character : getTeam()){
                if(character == nullptr || !character->isAlive() || !candidate->isAlive())
                    continue;
                if(auto *ninja = dynamic_cast<Ninja*>(character)){
                    if(ninja->distance(candidate) < 1){
                        countDistance++;
                    }
                }
            }
            if(countDistance > maxCount){
                maxCount = countDistance;
                target = candidate;
            }
        }
        if(maxCount)
            return target;
    }
    int minPoints = numeric_limits<int>::max();
    for(auto candidate : enemy->getTeam()){
        if(!candidate->isAlive())
            continue;
        if(candidate->getPoints() < minPoints){
            minPoints = candidate->getPoints();
            target = candidate;
        }
    }
    return target;
}