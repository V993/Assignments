//Leonardo Matone
//CSCI 235
//Project 1
//Bird.HPP

#ifndef BIRD_HPP
#define BIRD_HPP

#include "Animal.cpp"

// Bird class declaration
class Bird : public Animal{
public:
    Bird(); //bird constructor
    Bird(string name, bool domestic, bool predator); //bird constructor with a name provision
    bool isAirborne() const {return airborne;};
    bool isAquatic() const {return aquatic;};
    void setAirborne(bool val){
        airborne = val;
    };
    void setAquatic(bool val){
        aquatic = val;
    };

private:
    bool airborne;
    bool aquatic;
};


#endif