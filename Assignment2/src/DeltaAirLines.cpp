//============================================================================
// Name        : DeltaAirLines.cpp
// Author      : Jordan Betcher
// Date	       : 10/23/2017
// Description : DeltaAirLines class dealing with passengers
//============================================================================

#include "DeltaAirLines.h"
#include <string>
#include <list>

//Creates DeltaAirLines
DeltaAirLines::DeltaAirLines(list<std::string> flightNumbers)
{
	this->mFlightNumbers = flightNumbers;

	for (std::string flightNumber : flightNumbers)
	{
		OrderedLinkedList<Passenger> flight;
		this->mFlights[flightNumber] = flight;
	}

}

//Adds a Passenger to your flight
void DeltaAirLines::addPassenger()
{
	string flightNumber;
	string flightPrompt = "Enter flight number: ";
	cout << flightPrompt;
	cin >> flightNumber;

	string firstName;
	string firstNamePrompt = "Enter first name: ";
	firstName = getValidInput(firstNamePrompt, msStaticPassenger.isValidFirstName);

	string lastName;
	string lastNamePrompt = "Enter last name: ";
	lastName = getValidInput(lastNamePrompt, msStaticPassenger.isValidLastName);

	string address;
	string addressPrompt = "Enter address: ";
	address = getValidInput(addressPrompt, msStaticPassenger.isValidAddress);

	string phoneNumber;
	string phoneNumberPrompt = "Enter phone: ";
	phoneNumber = getValidInput(phoneNumberPrompt,
	        msStaticPassenger.isValidPhoneNumber);

	Passenger passenger(firstName, lastName, address, phoneNumber);
	mFlights[flightNumber].insertNode(passenger);
}

//Searches for a passenger in your flight
void DeltaAirLines::searchForPassenger()
{
	string firstName;
	string firstNamePrompt = "Enter first name: ";
	firstName = getValidInput(firstNamePrompt, msStaticPassenger.isValidFirstName);

	string lastName;
	string lastNamePrompt = "Enter last name: ";
	lastName = getValidInput(lastNamePrompt, msStaticPassenger.isValidLastName);

	Passenger comparablePassenger(firstName, lastName);

	for (string flightNumber : mFlightNumbers)
	{
		if (mFlights[flightNumber].hasNode(comparablePassenger))
		{
			cout << "Flight number: " << flightNumber << endl;
			cout << "First name: "
			        << mFlights[flightNumber].searchForNode(comparablePassenger).firstName
			        << endl;
			cout << "Last name: "
			        << mFlights[flightNumber].searchForNode(comparablePassenger).lastName
			        << endl;
			cout << "Address: "
			        << mFlights[flightNumber].searchForNode(comparablePassenger).address
			        << endl;
			cout << "Phone: "
			        << mFlights[flightNumber].searchForNode(comparablePassenger).phoneNumber
			        << endl;

			break;
		}
	}
}

//Deletes a passenger from your flight
void DeltaAirLines::deletePassenger()
{
	string flightNumber;
	string flightPrompt = "Enter flight number: ";
	cout << flightPrompt;
	cin >> flightNumber;

	string firstName;
	string firstNamePrompt = "Enter first name: ";
	firstName = getValidInput(firstNamePrompt, msStaticPassenger.isValidFirstName);

	string lastName;
	string lastNamePrompt = "Enter last name: ";
	lastName = getValidInput(lastNamePrompt, msStaticPassenger.isValidLastName);

	Passenger passengerToDelete(firstName, lastName);
	mFlights[flightNumber].deleteNode(passengerToDelete);

}

//Lists Passengers in your flight
void DeltaAirLines::listPassengers()
{
	string flightNumber;
	cout << "Enter flight number: ";
	cin >> flightNumber;
	cout << mFlights[flightNumber];
}

//Takes a Prompt and Check if it is valid
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

//Deletes Delta Air Lines
DeltaAirLines::~DeltaAirLines()
{
}
