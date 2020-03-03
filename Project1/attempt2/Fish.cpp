//Leonardo Matone
//CSCI 235
//Project 1
//Fish.CPP

#include "Fish.hpp"

using namespace std;

//default constructor, using the default constructor for the parent Animal class
Fish :: Fish() {
    venomous_ = 0;
}

//constructor with designated name, calling the parent animal class to designate the private data member of Animal.
Fish :: Fish(string name, bool domestic, bool predator)// : Animal(name, domestic, predator) {
{
    setName(name);
    if (domestic) setDomestic();
    if (predator) setPredator();
    venomous_ = 0;
}
  
bool Fish :: isVenomous() const {
    return venomous_;
}

void Fish :: setVenomous(){
    venomous_ = true;
}