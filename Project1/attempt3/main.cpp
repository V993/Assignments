//Leonardo Matone
//CSCI 235
//Project 1
//main.cpp

//#include <string>
#include "Animal.cpp"
#include <iostream>

using namespace std;

// for Animal testing
void information(Animal animal) {
    cout << animal.getName() << endl;           //testing function getName
    bool predator = animal.isPredator();        //testing function isPredator
    bool domestic = animal.isDomestic();        //testing function isDomestic

    //if/else statements to determine if the bool returns are accurate
    if (domestic) {
        cout << "A domestic ";
    }
    else {
        cout << "A non-domestic ";
    }

    if (predator) {
        cout << "predator." << endl;
    }
    else {
        cout << "non-predator." << endl;
    }
}

int main() {
    //test of Animal class with a mouse
    Animal mouse;
    string name = "MOUSE";
    mouse.setName(name); //setting name test
    information(mouse);  //use information function to output our class example

    Animal hawk("HAWK");
    ; //testing by designating name
    // hawk.setPredator(1); //testing predator set
    // hawk.setDomestic(0); //testing domestic set
    information(hawk);   //use information function to output our class example
}

