//Leonardo Matone
//CSCI 235
//Project 1
//Bird.cpp

#include "Bird.hpp"

//bird constructor with default values
Bird :: Bird() {
    airborne_ = 0;
    aquatic_ = 0;
};

Bird::Bird(std::string name, bool domestic, bool predator): Animal(name, domestic, predator) {
    airborne_ = 0;
    aquatic_ = 0;
}

//member acessor function to retrieve private data member airborne_ of child class
bool Bird :: isAirborne() const {
    return airborne_;
    }

//member acessor function to retrieve private data member aquatic_ of child class
bool Bird :: isAquatic() const {
    return aquatic_;
    }

//member mutator function to manipulate private data member airborne_ of child class 
void Bird :: setAirborne() {
    airborne_ = true;
    }

//member mutator function to manipulate private data members aquatic_ of child class 
void Bird :: setAquatic() {
    aquatic_ = true;
    }
    