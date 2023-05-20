#include <limits>
#include <iostream>
#include "Team.hpp"
using namespace ariel;
using namespace std;
 

Team ::Team(Character* leader): leader(leader){
    if(leader == nullptr)
        throw invalid_argument("nullptr");
    if(!leader->isAlive()){
        throw invalid_argument("leader is dead");
    }
    if(!leader->getInTeam()){
        leader->setInTeam(true);
        this->leader = leader;
        team.push_back(leader);
        players=1;
    }else{
        throw runtime_error("Character is already in a team");
    }
}

Team :: ~Team(){
    for(auto character : team){
        if(character != nullptr){
            delete character;
            character = nullptr;
        }
    }
}

void Team ::add(Character* player){
    if(player == nullptr)
        throw invalid_argument("nullptr");
    if(player->getInTeam())
        throw runtime_error("player already in a team");
    if(players == 10)
        throw runtime_error("10 players per team");
    team.push_back(player);
    players++;
    player->setInTeam(true);
}

void Team ::attack(Team* against ){
    if(against == nullptr){
        throw invalid_argument("nullptr - team is empty");
    }
    if(against->stillAlive() == 0)
        throw runtime_error("The team is dead");
    if(leader == nullptr)
            throw runtime_error("leader in nullptr");
    if(!leader->isAlive()){
        replaceLeader();
        if(leader == nullptr)
            throw runtime_error("All team members are dead");
    }
    Character* target = toAttack(against);
    for(auto character : team){
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
    for( auto character :team){
        if(character == nullptr)
            continue;
        if(!character->isAlive())
            continue;
        if(auto *ninja = dynamic_cast<Ninja *>(character)){
            if(!target->isAlive()){
                target = toAttack(against);
            }
            if(target == nullptr)
                break;
            ninjaAttack(ninja , target);
        }
    }
}
int Team ::stillAlive(){
    int alive = 0;
    for(auto character : team){
        if(character == nullptr)
            continue;
        if(character->isAlive())
            alive++;
    }
    return alive;
}
void Team ::print(){
    for(auto character : team){
        if(auto *cowboy = dynamic_cast<Cowboy *>(character)){
            cout << cowboy->print() << endl;
        }
    }
    for(auto character : team){
        if(auto *ninja = dynamic_cast<Ninja *>(character)){
            cout << ninja->print() << endl;
        }
    }
}
Character* Team:: getLeader()const{
    return leader;
}
void Team:: replaceLeader(){
    double minDistance=numeric_limits<double>::max();
    Character* candidate = nullptr;
    for(auto character : team){
        if(character == nullptr)
            continue;
        if(character->isAlive()){
            double distance = character->distance(leader);
            if( distance < minDistance){
                minDistance = distance;
                candidate = character;
            }
        }
    }
    setLeader(candidate);
}

Character* Team:: toAttack(Team * enemy){
    double minDistance=numeric_limits<double>::max();
    Character* target = nullptr;
    for(auto character : enemy->getTeam()){
        if(character == nullptr)
            continue;
        if(character->isAlive()){
            double distance = character->distance(leader);
            if( distance < minDistance){
                minDistance = distance;
                target = character;
            }
        }
    }
    return target;
}

void Team ::cowboyAttack(Cowboy* cowboy , Character* target){
    if(target == nullptr){
        throw invalid_argument("nullptr - cowboy attack");
    }
    if(!target->isAlive()){
        throw runtime_error("The target is dead");
    }
    if(cowboy == nullptr)
        throw runtime_error("The attacker is nullptr");
    if(cowboy->isAlive()){
        if(cowboy->getBullets() == 0)
            cowboy->reload();
        else
            cowboy->shoot(target);
            
    }else{
        throw runtime_error ("The attacker is dead");
    }
}
void  Team:: ninjaAttack(Ninja* ninja , Character* target){
    if(target == nullptr){
        throw invalid_argument("nullptr - ninja attack");
    }
    if(!target->isAlive()){
        throw runtime_error("The target is dead");
    }
    if(ninja == nullptr)
        throw runtime_error("The attacker is nullptr");
    if(ninja->isAlive()){
        if(ninja->distance(target) < 1)
            ninja->slash(target);
        else
            ninja->move(target);
    }else
        throw runtime_error ("The attacker is dead");
    
}

std::vector<Character*> Team:: getTeam() const {
    return team;
}
int Team:: getPlayers() const{
    return players;
}
void Team:: setLeader(Character* newLeader){
    this->leader = newLeader;
}