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
#include "DeltaAirLines.h"
#include <list>
using namespace std;

void runDeltaAirLines();

int main()
{
	runDeltaAirLines();
	return 0;
}

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
			airLines.addAction();
		}
		else if (command == "S")
		{
			airLines.searchAction();
		}
		else if (command == "D")
		{
			airLines.deleteAction();
		}
		else if (command == "L")
		{
			airLines.listAction();
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
