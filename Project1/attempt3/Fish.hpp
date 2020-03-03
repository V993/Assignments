//Leonardo Matone
//CSCI 235
//Project 1
//Fish.hpp

#include "Animal.hpp"

class Fish : public Animal{
    public:
        //default constructor
        Fish();
        //constructor for name and domestic/predator specifications.
        Fish(std::string name, bool domestic = false, bool predator = false);
        bool isVenomous() const;
        void setVenomous();
    private:
        bool venomous_;
};

