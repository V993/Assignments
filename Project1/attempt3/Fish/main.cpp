
//Leonardo Matone
//CSCI 235
//Project 1
//Fish.CPP

#include <string>
#include <iostream>
#include "Fish.cpp"

using namespace std;

//information function to test outputs for different fish
void information(Fish fish) {
    cout << fish.getName() << endl; //testing the ability of the inheriting function to take data from the parent function
    if (fish.isVenomous()) {
        cout << "Venomous fish." << endl;
    }
    else {
        cout << "Non-venomous fish." << endl;
    }
}

int main() {
    Fish salmon("PERCY"); //testing the ability of the inhertiant class to assign data to a private data member of the parent class
    salmon.setVenomous(true); //manipulating private data of the inherited class
    information(salmon); //call to test
}