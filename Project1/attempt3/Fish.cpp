//Leonardo Matone
//CSCI 235
//Project 1
//Fish.cpp

#include "Fish.hpp"

//default constructor, using the default constructor for the parent Animal class
Fish :: Fish() {
    venomous_ = 0;
}

//constructor with designated name, calling the parent animal class to designate the private data member of Animal.
Fish :: Fish(std::string name, bool domestic, bool predator): Animal(name, domestic, predator) {
    venomous_ = 0;
}

//member acessor function to retrieve private data member venomous_ of child class
bool Fish :: isVenomous() const {
    return venomous_;
}
//member mutator function to manipulate private data member venomous_ of child class 
void Fish :: setVenomous(){
    venomous_ = true;
}