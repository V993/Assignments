//Leonardo Matone
//CSCI 235
//Project 1
//Animal.cpp

#include "Animal.hpp"

using namespace std;

//Base constructor, empty string for the name and false domestic/predator default
Animal :: Animal() {
    domestic_ = false;
    predator_ = false;
}

//Constructor with designated name, false domestic/predator default
Animal :: Animal(std::string name, bool domestic, bool predator) {
    domestic_ = domestic;
    predator_ = predator;
    name_ = name;
}

std::string Animal :: getName() const {
    return name_;
}

bool Animal :: isDomestic() const {
    return domestic_;
}

bool Animal :: isPredator() const {
    return predator_;
}

void Animal :: setName(std::string name){
    name_ = name;
}

void Animal :: setDomestic(){
    domestic_ = true;
}

void Animal :: setPredator(){
    predator_ = true;
}