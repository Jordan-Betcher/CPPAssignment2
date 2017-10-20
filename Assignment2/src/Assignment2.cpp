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

	while(running)
	{
		string command;
		cout << "A(Add) | S(Search)| D(Delete) | L(List) | Q(Quit): ";
		cin >> command;

		if(command == "A")
		{
			Passenger test;

			string flightNumber;
			string flightPrompt =  "Enter flight number: ";
			cout << flightPrompt;
			cin >> flightNumber;

			string firstName;
			string firstNamePrompt = "Enter first name: ";
			firstName = getInput(firstNamePrompt, test.isValidFirstName);

			string lastName;
			string lastNamePrompt = "Enter last name: ";
			lastName = getInput(firstNamePrompt, test.isValidLastName);

			string address;
			string addressPrompt = "Enter address: ";
			address = getInput(firstNamePrompt, test.isValidAddress);

			string phoneNumber;
			string phoneNumberPrompt = "Enter phone: ";
			phoneNumber = getInput(firstNamePrompt, test.isValidPhoneNumber);

			// Add to List
			Passenger passenger(firstName, lastName, address, phoneNumber);
			flights[flightNumber].insertFirst(passenger);
		}
		else if(command == "S")
		{
			string firstName, lastName;

			cout << "Enter first name: ";
			cin >> firstName;

			cout << "Enter last name: ";
			cin >> lastName;

			// print information
		}
		else if(command == "D")
		{
			string flightNumber, firstName, lastName;

			cout << "Enter flight number: ";
			cin >> flightNumber;

			cout << "Enter first name: ";
			cin >> firstName;

			cout << "Enter last name: ";
			cin >> lastName;

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
