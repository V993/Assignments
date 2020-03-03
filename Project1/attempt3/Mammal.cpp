//Leonardo Matone
//CSCI 235
//Project 1
//Mammal.cpp

#include "Mammal.hpp"

//default settings of mammal class constructor
Mammal :: Mammal() {
    hair_ = false;
    airborne_ = false;
    aquatic_ = false;
    toothed_ = false;
    fins_ = false;
    tail_ = false;
    int legs = 0;
}

//default settings of mammal class constructor accessing private data members of parent function to assign name
Mammal :: Mammal(std::string name, bool domestic, bool predator): Animal(name, domestic, predator){
    hair_ = false;
    airborne_ = false;
    aquatic_ = false;
    toothed_ = false;
    fins_ = false;
    tail_ = false;
    int legs = 0;
}

                //Accessors:

//member acessor function to retrieve private data member hair_ of child class
bool Mammal :: hasHair() const {
    return hair_;
}

//member acessor function to retrieve private data member airborne_ of child class
bool Mammal :: isAirborne() const {
    return airborne_;
}

//member acessor function to retrieve private data member aquatic_ of child class
bool Mammal :: isAquatic() const {
    return aquatic_;
}

//member acessor function to retrieve private data member toothed_ of child class
bool Mammal :: isToothed() const {
    return toothed_;
}

//member acessor function to retrieve private data member fins_ of child class
bool Mammal :: hasFins() const {
    return fins_;
}

//member acessor function to retrieve private data member tail_ of child class
bool Mammal :: hasTail() const {
    return  tail_;
}

//member acessor function to retrieve private data member legs_ of child class
int Mammal :: legs() const {
    return legs_;
}

                //Mutators:

//member mutator function to manipulate private data member hair_ of child class 
void Mammal :: setHair() {
    hair_ = true;
}

//member mutator function to manipulate private data member airborne_ of child class 
void Mammal :: setAirborne() {
    airborne_ = true;
}

//member mutator function to manipulate private data member aquatic_ of child class 
void Mammal :: setAquatic() {
    aquatic_ = true;
}

//member mutator function to manipulate private data member toothed_ of child class 
void Mammal :: setToothed() {
    toothed_ = true;
}

//member mutator function to manipulate private data member fins_ of child class 
void Mammal :: setFins() {
    fins_ = true;
}

//member mutator function to manipulate private data member tail_ of child class 
void Mammal :: setTail() {
    tail_ = true;
}

//member mutator function to manipulate private data member legs_ of child class 
void Mammal :: setLegs(int legs) {
    legs_ = legs;
}