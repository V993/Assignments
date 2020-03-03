//Leonardo Matone
//CSCI 235
//Project 1
//Bird.hpp

#ifndef BIRD_HPP
#define BIRD_HPP

#include "Animal.hpp"

//class definition for Bird, inherits from Animal.
class Bird : public Animal{
    public:
        //default constructor
        Bird();
        //constructor for name and domestic/predator specifications.
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