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
	this->mFlightNumbers = flightNumbers;

	for (std::string flightNumber : flightNumbers)
	{
		OrderedLinkedList<Passenger> flight;
		this->mFlights[flightNumber] = flight;
	}

}

void DeltaAirLines::addPassenger()
{
	string flightNumber;
	string flightPrompt = "Enter flight number: ";
	cout << flightPrompt;
	cin >> flightNumber;

	string firstName;
	string firstNamePrompt = "Enter first name: ";
	firstName = getValidInput(firstNamePrompt, mStaticPassenger.isValidFirstName);

	string lastName;
	string lastNamePrompt = "Enter last name: ";
	lastName = getValidInput(lastNamePrompt, mStaticPassenger.isValidLastName);

	string address;
	string addressPrompt = "Enter address: ";
	address = getValidInput(addressPrompt, mStaticPassenger.isValidAddress);

	string phoneNumber;
	string phoneNumberPrompt = "Enter phone: ";
	phoneNumber = getValidInput(phoneNumberPrompt,
	        mStaticPassenger.isValidPhoneNumber);

	Passenger passenger(firstName, lastName, address, phoneNumber);
	mFlights[flightNumber].insert(passenger);
}

void DeltaAirLines::searchForPassenger()
{
	string firstName;
	string firstNamePrompt = "Enter first name: ";
	firstName = getValidInput(firstNamePrompt, mStaticPassenger.isValidFirstName);

	string lastName;
	string lastNamePrompt = "Enter last name: ";
	lastName = getValidInput(lastNamePrompt, mStaticPassenger.isValidLastName);

	Passenger comparablePassenger(firstName, lastName);

	for (string flightNumber : mFlightNumbers)
	{
		if (mFlights[flightNumber].has(comparablePassenger))
		{
			cout << "Flight number: " << flightNumber << endl;
			cout << "First name: "
			        << mFlights[flightNumber].search(comparablePassenger).firstName
			        << endl;
			cout << "Last name: "
			        << mFlights[flightNumber].search(comparablePassenger).lastName
			        << endl;
			cout << "Address: "
			        << mFlights[flightNumber].search(comparablePassenger).address
			        << endl;
			cout << "Phone: "
			        << mFlights[flightNumber].search(comparablePassenger).phoneNumber
			        << endl;

			break;
		}
	}
}

void DeltaAirLines::deletePassenger()
{
	string flightNumber;
	string flightPrompt = "Enter flight number: ";
	cout << flightPrompt;
	cin >> flightNumber;

	string firstName;
	string firstNamePrompt = "Enter first name: ";
	firstName = getValidInput(firstNamePrompt, mStaticPassenger.isValidFirstName);

	string lastName;
	string lastNamePrompt = "Enter last name: ";
	lastName = getValidInput(lastNamePrompt, mStaticPassenger.isValidLastName);

	Passenger passengerToDelete(firstName, lastName);
	mFlights[flightNumber].deleteNode(passengerToDelete);

}

void DeltaAirLines::listPassengers()
{
	string flightNumber;
	cout << "Enter flight number: ";
	cin >> flightNumber;
	cout << mFlights[flightNumber];
}

string DeltaAirLines::getValidInput(string prompt, bool isValid(string))
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
