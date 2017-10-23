/*
 * DeltaAirLines.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: Betcher
 */

#include "DeltaAirLines.h"
#include <string>
#include <list>

DeltaAirLines::DeltaAirLines(list<std::string> flightNumbers)
{
	this->flightNumbers = flightNumbers;

	for (std::string flightNumber : flightNumbers)
	{
		OrderedLinkedList<Passenger> flight;
		this->flights[flightNumber] = flight;
	}

}

void DeltaAirLines::addAction()
{
	string flightNumber;
	string flightPrompt = "Enter flight number: ";
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
	phoneNumber = getInput(phoneNumberPrompt,
	        staticPassenger.isValidPhoneNumber);

	Passenger passenger(firstName, lastName, address, phoneNumber);
	flights[flightNumber].insert(passenger);
}

void DeltaAirLines::searchAction()
{
	string firstName;
	string firstNamePrompt = "Enter first name: ";
	firstName = getInput(firstNamePrompt, staticPassenger.isValidFirstName);

	string lastName;
	string lastNamePrompt = "Enter last name: ";
	lastName = getInput(lastNamePrompt, staticPassenger.isValidLastName);

	Passenger comparablePassenger(firstName, lastName);

	for (string flightNumber : flightNumbers)
	{
		if (flights[flightNumber].has(comparablePassenger))
		{
			cout << "Flight number: " << flightNumber << endl;
			cout << "First name: "
			        << flights[flightNumber].search(comparablePassenger).firstName
			        << endl;
			cout << "Last name: "
			        << flights[flightNumber].search(comparablePassenger).lastName
			        << endl;
			cout << "Address: "
			        << flights[flightNumber].search(comparablePassenger).address
			        << endl;
			cout << "Phone: "
			        << flights[flightNumber].search(comparablePassenger).phoneNumber
			        << endl;

			break;
		}
	}
}

void DeltaAirLines::deleteAction()
{
	string flightNumber;
	string flightPrompt = "Enter flight number: ";
	cout << flightPrompt;
	cin >> flightNumber;

	string firstName;
	string firstNamePrompt = "Enter first name: ";
	firstName = getInput(firstNamePrompt, staticPassenger.isValidFirstName);

	string lastName;
	string lastNamePrompt = "Enter last name: ";
	lastName = getInput(lastNamePrompt, staticPassenger.isValidLastName);

	Passenger passengerToDelete(firstName, lastName);
	flights[flightNumber].deleteNode(passengerToDelete);

}

void DeltaAirLines::listAction()
{
	string flightNumber;
	cout << "Enter flight number: ";
	cin >> flightNumber;
	cout << flights[flightNumber];
}

string DeltaAirLines::getInput(string prompt, bool isValid(string))
{
	string input;

	cout << prompt;
	cin >> input;

	while (!isValid(input))
	{
		cout << "The input was not valid." << endl;
		cout << prompt;
		cin >> input;
	}

	return input;

}

DeltaAirLines::~DeltaAirLines()
{
}
