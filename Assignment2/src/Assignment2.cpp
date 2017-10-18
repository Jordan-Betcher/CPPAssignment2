//============================================================================
// Name        : Assignment2.cpp
// Author      : Jordan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	string flights[4] = {"100", "200", "300", "400"};



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
			string flightNumber, firstName, lastName, address, phoneNumber;

			cout << "Enter flight number: ";
			cin >> flightNumber;

			cout << "Enter first name: ";
			cin >> firstName;

			cout << "Enter last name: ";
			cin >> lastName;

			cout << "Enter address: ";
			cin >> address;

			cout << "Enter phone: ";
			cin >> phoneNumber;

			// Add to List
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

	return 0;
}
