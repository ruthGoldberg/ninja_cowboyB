#pragma once
#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name , Point location);
       //~TrainedNinja() override = default;
    };
    
}