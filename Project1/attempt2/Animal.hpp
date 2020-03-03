//Leonardo Matone
//CSCI 235
//Project 1
//Animal.hpp

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
    Animal();
    Animal(std::string name, bool domestic = false, bool predator = false);
    std::string getName() const;
    bool isDomestic() const;
    bool isPredator() const;
    void setName(std::string name);
    void setDomestic();
    void setPredator();
private:
    std::string name_;
    bool domestic_;
    bool predator_;
};

#include "Animal.cpp"
#endif
