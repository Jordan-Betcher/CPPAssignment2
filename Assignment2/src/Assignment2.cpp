//============================================================================
// Name        : Assignment2.cpp
// Author      : Jordan Betcher
// Date	       : 10/23/2017
// Description : Assignment2 for C++ class, create and modify an OrderedLinkedList
//============================================================================

#include <iostream>
#include <map>
#include "OrderedLinkedList.h"
#include "Passenger.h"
#include "DeltaAirLines.h"
#include <list>
using namespace std;

void runDeltaAirLines();

int main()
{
	runDeltaAirLines();
	return 0;
}

//Runs Delta AirLines
void runDeltaAirLines()
{
	list<string> flightNumbers = { "100", "200", "300", "400" };
	DeltaAirLines airLines(flightNumbers);

	bool running = true;

	cout << "***DELTA AIRLINES ***" << endl;
	cout << "Please choose an operation:" << endl;

	while (running)
	{
		string command;
		cout << "A(Add) | S(Search)| D(Delete) | L(List) | Q(Quit): ";
		cin >> command;

		if (command == "A")
		{
			airLines.addPassenger();
		}
		else if (command == "S")
		{
			airLines.searchForPassenger();
		}
		else if (command == "D")
		{
			airLines.deletePassenger();
		}
		else if (command == "L")
		{
			airLines.listPassengers();
		}
		else if (command == "Q")
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
