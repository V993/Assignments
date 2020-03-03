#include <string>

#include "Animal.cpp"

class Fish : public Animal{
public:
    Fish();
    Fish(std::string name, bool domestic = false, bool predator = false);
    bool isVenomous() const;
    void setVenomous();
private:
    bool venomous_;
};

