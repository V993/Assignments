//Leonardo Matone
//CSCI 235
//Project 1
//Fish.HPP

#ifndef FISH_HPP
#define FISH_HPP

#include "Animal.cpp"

using namespace std;

//Class declaration of fish
class Fish : public Animal{
public:
    Fish(); //constructor for fish
    Fish(string name, bool domestic, bool predator); //constructor for fish designating the name by going to the parent class and mutating parent class private data
    bool isVenomous() const {return venomous;}; 
    void setVenomous(bool val){
        venomous = val;
    };

private:
    bool venomous;
};

#endif