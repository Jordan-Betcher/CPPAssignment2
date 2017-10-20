//============================================================================
// Name        : Assignment2.cpp
// Author      : Jordan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include "OrderedLinkedList.h"
#include "Passenger.h"
using namespace std;

void runDeltaAirLines();
string getInput(string, bool isValid(string));

int main()
{
	runDeltaAirLines();

	return 0;
}

void runDeltaAirLines()
{
	map<string, OrderedLinkedList<Passenger>> flights;

	OrderedLinkedList<Passenger> flight100;
	OrderedLinkedList<Passenger> flight200;
	OrderedLinkedList<Passenger> flight300;
	OrderedLinkedList<Passenger> flight400;

	flights["100"] = flight100;
	flights["200"] = flight200;
	flights["300"] = flight300;
	flights["400"] = flight400;

	bool running = true;

	cout << "***DELTA AIRLINES ***" << endl;
	cout << "Please choose an operation:" << endl;
	Passenger staticPassenger;

	while(running)
	{
		string command;
		cout << "A(Add) | S(Search)| D(Delete) | L(List) | Q(Quit): ";
		cin >> command;

		if(command == "A")
		{

			string flightNumber;
			string flightPrompt =  "Enter flight number: ";
			cout << flightPrompt;
			cin >> flightNumber;

			string firstName;
			string firstNamePrompt = "Enter first name: ";
			firstName = getInput(firstNamePrompt, staticPassenger.isValidFirstName);

			string lastName;
			string lastNamePrompt = "Enter last name: ";
			lastName = getInput(lastNamePrompt, staticPassenger.isValidLastName);

			string address;
			string addressPrompt = "Enter address: ";
			address = getInput(addressPrompt, staticPassenger.isValidAddress);

			string phoneNumber;
			string phoneNumberPrompt = "Enter phone: ";
			phoneNumber = getInput(phoneNumberPrompt, staticPassenger.isValidPhoneNumber);

			Passenger passenger(firstName, lastName, address, phoneNumber);
			flights[flightNumber].insert(passenger);
		}
		else if(command == "S")
		{
			Passenger staticPassenger;
			string firstName;
			string firstNamePrompt = "Enter first name: ";
			firstName = getInput(firstNamePrompt, staticPassenger.isValidFirstName);

			string lastName;
			string lastNamePrompt = "Enter last name: ";
			lastName = getInput(lastNamePrompt, staticPassenger.isValidLastName);

			// print information
		}
		else if(command == "D")
		{

			string flightNumber;
			string flightPrompt =  "Enter flight number: ";
			cout << flightPrompt;
			cin >> flightNumber;

			string firstName;
			string firstNamePrompt = "Enter first name: ";
			firstName = getInput(firstNamePrompt, staticPassenger.isValidFirstName);

			string lastName;
			string lastNamePrompt = "Enter last name: ";
			lastName = getInput(lastNamePrompt, staticPassenger.isValidLastName);

			//delete
		}
		else if(command == "L")
		{
			string flightNumber;
			cout << "Enter flight number: ";
			cin >> flightNumber;
			cout << flights[flightNumber];
		}
		else if(command == "Q")
		{
			running = false;
		}
		else
		{
			cout << "I don't have a command: " << command << endl;
			cout << "Please choose an operation:";
		}

		cout << endl;

	}
}

inline string getInput(string prompt, bool isValid(string))
{
	string input;

	cout << prompt;
	cin >> input;

	while(! isValid(input))
	{
		cout << "The input was not valid." << endl;
		cout << prompt;
		cin >> input;
	}

	return input;

}
