/*
    Group Members: Annie Dutta, Anuska Sharma, Arman Kabir, David Li, Dibba Roy, Huiyang Lin, Justin Kuang, Leonardo Matone, Maninder Singh, Qiao Gan Chen, Umar Arshad, William Chan.
    Our implementation utilizes the collaborating classes of DoublyLinkedList and DoubleNode in order to properly impliment a Contact Tracing element with the goal of managing the
    number of currently infected, in addition to those who have been in contact with infected individuals.

    We decided the implement using a doubly linked list and double nodes, as to make traversing the contacts easier from any direction, to better track those infected, and those 
    who have been in contact with an infectedIndividual.

*/

#include "DoublyLinkedList.hpp"
#include <string>
#include <vector>


class covid_19_outbreak { 
	public:

            // Unusual conditions: 
            /* For all adding methods: the methods will return true if preconditions are met. false if they fail to be met, and false if there is not enough room, or the entry is out of range.
                For all acessor methods: the methods will return -1 if an entry does not exist, and otherwise will return if the preconditions are met. If they are not, it will throw an error.
            
                Additionally, some mutator functions may be missing. They are so rudamentary that it was thought that we should focus on our main ideas instead of the smaller details which 
                are easier to implement.
            */

        // note, our doublenode and doublylinked list classes would need to be modified to account for the ages, names, and other data fields of individuals it tracks. This implementation is assumed in this program.
        //@returns the doubleNode containing all of the data for a particular individual
        //@post returns the information of the individual
        DoubleNode<string> returnIndividual;

        // note, we realize it would be better to implement this in an InfectedIndividual class, but our implementation includes this here as a demonstration of our plan.
        // @returns the list of individuals in the contact of an infected individual
        // @post list is returned in a doublylinked list with the goal of 
        DoublyLinkedList<string> contactsOfIndividual();

        // @param a doublenode of an individual in contact with an InfectedIndividual
        // @return a bool of the success of adding this contact to the doublylinked list of contacts
        // @pre the contact must be a DoubleNode string with the name of the contact
        // @post the doublenode is added to the doubly linked list.
        bool addContact(DoubleNode<string> contact);

        //@return the rate of infection in new cases
        //@post returns the rate as an percent value.
        double rateOfCases();

        //@return the number of individuals recovered
        //@post returns the integer of those infected.
        int numRecoveries();

        //@return the number of deaths to the day
        //@post returns the integer deaths.
        int numDeaths();

		//@return the number infected
		//@post returns the number infected stored in private data member
		int getNumInfected();

		//@return bool of whether or not the country has the virus
		//@param takes input of a country to test in the vector
		//@pre country must be a string, testable by our string vector
		//@post returns true/false whether it is in the country
		bool isInCountry(std::string country);

		// @return the vector string of all known transmission methods
		// @post returns the transmission methods
		vector<std::string> getTransmissionMethods();

		// @return returns mean age
		// @post computes and returns mean age
		int getMeanAge();

		// @return computes and returns percent infected
		// @post computes and returns
		int getPercentInfected();

		// @return returns a bool of whether it was successfully added
		// @param the number of infected to be added to total
		// @pre number is an integer
		// @post the number infected will be modified 
		bool addNumInfected(int number);

		// @return returns a bool of whether the country was successfully added
		// @param the country to be added
		// @pre the country to be added must be a string
		// @post the country will be added to the vector string of all countries infected
		bool addInfectedCountry(std::string country );

		// @return bool of whether or not the method was added
		// @param the transmission method string to be added
		// @pre the method must be a string
		// @post the method will be added to the vector string of all methods
		bool addTransmissionMethod(std::string transmissionMethod);

		// @return bool of whether it was added
		// @param the mean age to be computed into the total
		// @pre the age must be an integer
		// @post the age will be computed into the total
		bool addMeanAge(int meanAge);
        
	private: 
		int num_infected;
		int tests;
		std::string how_transmitted;
		int mean_age;
		vector<std::string> countries;
        double infection_rate;
        int num_dead;

        // note, our doublenode and doublylinked list classes would need to be modified to account for the ages, names, and other data fields of individuals it tracks. This implementation is assumed in this program.
        DoubleNode<string> individual;

        // note, we realize it would be better to implement this in an InfectedIndividual class, but our implementation includes this here as a demonstration of our plan.
        DoublyLinkedList<string> contactsOfIndividual();

};