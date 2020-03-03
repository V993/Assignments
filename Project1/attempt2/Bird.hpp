//Leonardo Matone
//CSCI 235
//Project 1
//Bird.hpp

#ifndef BIRD_HPP
#define BIRD_HPP

#include "Animal.cpp"

class Bird : public Animal{
public:
    Bird();
    Bird(std::string name, bool domestic = false, bool predator = false);
    bool isAirborne() const;
    bool isAquatic() const;
    void setAirborne();
    void setAquatic();
private:
    bool airborne_;
    bool aquatic_;
};

#endif