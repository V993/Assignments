//Leonardo Matone
//CSCI 235
//Project 1
//Bird.cpp

#include "Bird.hpp"

using namespace std;

//bird constructor with default values
Bird :: Bird() : Animal(),
    airborne_ (false),
    aquatic_ (false) 
    {};

Bird::Bird(string name, bool domestic, bool predator){
    setName(name);
    if (domestic) setPredator();
    if (predator) setPredator();
}


bool Bird :: isAirborne() const {
    return airborne_;
    }

bool Bird :: isAquatic() const {
    return aquatic_;
    }

void Bird :: setAirborne() {
    airborne_ = true;
    }

void Bird :: setAquatic() {
    aquatic_ = true;
    }
    