//Leonardo Matone
//CSCI 235
//Project 1
//Mammal.CPP

#include "Mammal.hpp"

using namespace std;

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
Mammal :: Mammal(string name, bool domestic, bool predator)//: Animal(name, domestic, predator){
{
    setName(name);
    if(domestic) setDomestic();
    if(predator) setPredator();
    hair_ = false;
    airborne_ = false;
    aquatic_ = false;
    toothed_ = false;
    fins_ = false;
    tail_ = false;
    int legs = 0;
}

bool Mammal :: hasHair() const {
    return hair_;
}

bool Mammal :: isAirborne() const {
    return airborne_;
}

bool Mammal :: isAquatic() const {
    return aquatic_;
}

bool Mammal :: isToothed() const {
    return toothed_;
}

bool Mammal :: hasFins() const {
    return fins_;
}

bool Mammal :: hasTail() const {
    return  tail_;
}

int Mammal :: legs() const {
    return legs_;
}

void Mammal :: setHair() {
    hair_ = true;
}

void Mammal :: setAirborne() {
    airborne_ = true;
}

void Mammal :: setAquatic() {
    aquatic_ = true;
}

void Mammal :: setToothed() {
    toothed_ = true;
}

void Mammal :: setFins() {
    fins_ = true;
}

void Mammal :: setTail() {
    tail_ = true;
}

void Mammal :: setLegs(int legs) {
    legs_ = legs;
}