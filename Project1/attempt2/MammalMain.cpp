//Leonardo Matone
//CSCI 235
//Project 1
//Mammal.CPP

#include <iostream>
#include <string>
#include "Mammal.cpp"

using namespace std;

// for Mammal testing
void information(Mammal mammal) {
    cout << mammal.getName() << endl; //using the getnName() function to get the private data member of the parent class
    bool predator = mammal.isPredator(); //testing accessor function
    bool domestic = mammal.isDomestic(); //testing accessor function
    // testing output
    if (domestic) {
        cout << "A domestic ";
    }
    else {
        cout << "A non-domestic ";
    }

    if (predator) {
        cout << "predator." ;
    }
    else {
        cout << "non-predator." ;
    }

    if (mammal.hasHair()) {
        cout << " The mammal has hair, ";
    }
    else {
        cout << " The mammal does not have hair, ";
    }
    if (mammal.isAquatic()) {
        cout << "is aquatic, ";
    }
    else {
        cout << "is not aquatic, ";
    }
    if (mammal.hasFins()) {
        cout << "has fins, ";
    }
    else {
        cout << "does not have fins, "; 
    }
    if (mammal.isToothed()) {
        cout << "and has teeth." << endl;
    }
    else {
        cout << "and does not have teeth." << endl;
    }
}

int main() {

    //test of a dolphin mammal
    Mammal dolphin;
    dolphin.setName("HENRY THE DOLPHIN"); //testng setName()
    //playing with some private data
    dolphin.setAquatic(1);
    dolphin.setToothed(1);
    dolphin.setFins(1);
    dolphin.setTail(1);
    dolphin.setPredator(1);
    //outputting information to test if accurate
    information(dolphin);

    //testing interactions between classes with a declaration which mutates parent class private data
    Mammal bear("JACK THE BEAR");
    bear.setToothed(1);
    bear.setPredator(1);
    information(bear);

}
