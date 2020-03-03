//Leonardo Matone
//CSCI 235
//Project 1
//main.cpp

#include <string>
#include <iostream>
#include "Bird.cpp"

using namespace std;

// for Bird testing
void information(Bird bird) {
    //output information about specific bird, tests each function
    cout << bird.getName() << endl;
    if (bird.isDomestic()) {
        cout << "A domestic ";
    }
    else {
        cout << "A non-domestic ";
    }
    if (bird.isPredator()) {
        cout << "predator. ";
    }
    else {
        cout << "non-predator. ";
    }
    if (bird.isAirborne()) {
        cout << "This bird flies, ";
    }
    else {
        cout << "This bird does not fly, ";
    }
    if (bird.isAquatic()) {
        cout << "it swims." << endl;
    }
    else {
        cout << "and it is non-aquatic." << endl;
    }
}

int main(){

    //test of class with a penguin
    Bird penguin("JACK"); //using the name case
    // penguin.setAirborne(0); //testing inputting a false value
    // penguin.setAquatic(1);  //and a truth value into different member mutator functions
    information(penguin); //output information on penguin

}