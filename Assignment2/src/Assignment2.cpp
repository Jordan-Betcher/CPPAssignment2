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
	bool running = true;

	cout << "***DELTA AITLINES ***" << endl;
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
		}
		else if(command == "S")
		{

		}
		else if(command == "D")
		{

		}
		else if(command == "L")
		{

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
