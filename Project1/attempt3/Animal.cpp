//Leonardo Matone
//CSCI 235
//Project 1
//Animal.cpp

#include "Animal.hpp"

//Base constructor, empty string for the name and false domestic/predator default
Animal :: Animal() {
    domestic_ = false;
    predator_ = false;
}

//Constructor with designated name, false domestic/predator default
Animal :: Animal(std::string name, bool domestic, bool predator) {
    name_ = name;
    domestic_ = domestic;
    predator_ = predator;
}

//member acessor function to retrieve private data member name_ of class
std::string Animal :: getName() const {
    return name_;
}

//member acessor function to retrieve private data member domestic_ of class
bool Animal :: isDomestic() const {
    return domestic_;
}

//member acessor function to retrieve private data member predator_ of class
bool Animal :: isPredator() const {
    return predator_;
}

//member mutator function to manipulate private data member name_ of class from input string
void Animal :: setName(std::string name){
    name_ = name;
}

//member mutator function to manipulate private data member domestic_ of class 
void Animal :: setDomestic(){
    domestic_ = true;
}

//member mutator function to manipulate private data member predator_ of class 
void Animal :: setPredator(){
    predator_ = true;
}