//Leonardo Matone
//CSCI 235
//Project 1
//Mammal.HPP

#ifndef MAMMAL_HPP
#define MAMMAL_HPP

#include "Animal.cpp"

using namespace std; 

class Mammal : public Animal{
public:
    Mammal(); //default constructor
    Mammal(string name, bool domestic, bool predator); //constructor accessing private data members of parent function to assign name
    //accessor functions
    bool hasHair() const{return hair;};
    bool isAirborne() const{return airborne;};
    bool isAquatic() const{return aquatic;};
    bool isToothed() const{return toothed;};
    bool hasFins() const{return fins;};
    bool hasTail() const{return tail;};
    int legCount() const{return legs;};
    //manipulator functions
    void setHair(bool val){
        hair = val;
    }
    void setAquatic(bool val){
        aquatic = val;
    };
    void setToothed(bool val){
        toothed = val;
    };
    void setFins(bool val){
        fins = val;
    };
    void setTail(bool val){
        tail = val;
    };
    void setLegs(int num){
        legs = num;
    };

private:
    bool hair;
    bool airborne;
    bool aquatic;
    bool toothed;
    bool fins;
    bool tail;
    int legs;
};

#endif