//Leonardo Matone
//CSCI 235
//Project 1
//Animal.hpp

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

using namespace std;

//Animal class declaration
class Animal {
public:
    Animal(); //base constructor
    Animal(string name, bool domestic = false, bool predator = false); //constructor with designated name
    bool isDomestic() const{return domestic_;}; //return private data member
    bool isPredator() const{return predator_;}; //return private data member
    string getName() const{return name_;}; //return private data member
    void setDomestic(bool val){ //setting private data member
        domestic_ = val;
    };
    void setPredator(bool val){ //setting private data member
        predator_ = val;
    };
    void setName(string n){ //setting private data member
        name_ = n;
    };

private:
    string name_;
    bool domestic_;
    bool predator_;
};

#endif

