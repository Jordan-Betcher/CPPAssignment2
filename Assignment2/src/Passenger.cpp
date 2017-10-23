//============================================================================
// Name        : Passenger.cpp
// Author      : Jordan Betcher
// Date	       : 10/23/2017
// Description : Passenger class that holds firstName, lastName, address, phoneNumber
//============================================================================

#include "Passenger.h"
#include <iostream>

//Creates Passenger with empty members
Passenger::Passenger()
{
	this->firstName = "";
	this->lastName = "";
	this->address = "";
	this->phoneNumber = "";
}

//Creates Passenger with only firstName and lastName, most often used to search for Passenger
Passenger::Passenger(std::string firstName, std::string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = "";
	this->phoneNumber = "";
}

//Creates Passenger with all the information
Passenger::Passenger(std::string firstName, std::string lastName, std::string address, std::string phoneNumber)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = address;
	this->phoneNumber = phoneNumber;
}

//Tells if there is a Number in the stringToCheck
bool Passenger::isNumberInString(std::string stringToCheck)
{
	int size = stringToCheck.size();
	for(int i = 0; i < size; i++)
	{
		char letter = stringToCheck[i];

		if(
			   letter == '1'
			|| letter == '2'
			|| letter == '3'
			|| letter == '4'
			|| letter == '5'
			|| letter == '6'
			|| letter == '7'
			|| letter == '8'
			|| letter == '9'
			|| letter == '0'
		)
		{
			return true;
		}
	}

	return false;
}

//Tells if the possibleFirstName is Valid (doesn't has a number in it)
bool Passenger::isValidFirstName(std::string possibleFirstName)
{
	return !isNumberInString(possibleFirstName);
}

//Tells if the possibleLastName is Valid (doesn't has a number in it)
bool Passenger::isValidLastName(std::string possibleLastName)
{
	return !isNumberInString(possibleLastName);
}

//Tells if the possibleAddres is Valid
bool Passenger::isValidAddress(std::string possibleAddress)
{
	//The instructions don't call for address to be checked
	return true;
}

//Tells if the possiblePhoneNumber is Valid
bool Passenger::isValidPhoneNumber(std::string possiblePhoneNumber)
{
	//The instructions don't call for phoneNumber to be checked
	return true;
}

//Sets the firstName
void Passenger::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

//Sets the lastName
void Passenger::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

//Sets the address
void Passenger::setAddress(std::string address)
{
	this->address = address;
}

//Sets the phoneNumber
void Passenger::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

//Gets the firstName
std::string Passenger::getFirstName()
{
	return this->firstName;
}

//Gets the lastName
std::string Passenger::getLastName()
{
	return this->lastName;
}

//Gets the address
std::string Passenger::getAddress()
{
	return this->address;
}

//Gets the phoneNumber
std::string Passenger::getPhoneNumber()
{
	return this->phoneNumber;
}

//Tells if stringToCheck is empty
bool Passenger::isStringEmpty(std::string stringToCheck)
{
	if(stringToCheck.empty())
	{
		return true;
	}
	else if(stringToCheck.size() <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Tells if firstName is empty
bool Passenger::isFirstNameEmpty()
{
	return isStringEmpty(this->firstName);
}

//Tells if lastName is empty
bool Passenger::isLastNameEmpty()
{
	return isStringEmpty(this->lastName);
}

//Tells if address is empty
bool Passenger::isAddressEmpty()
{
	return isStringEmpty(this->address);
}

//Tells if phoneNumber is empty
bool Passenger::isPhoneNumberEmpty()
{
	return isStringEmpty(this->phoneNumber);
}

//Prints the passenger's Data to the output
std::ostream& operator<<(std::ostream& output, Passenger& passenger)
{
	output << passenger.firstName << " " << passenger.lastName << " " << "[" << passenger.address << "]" << " "<< "[" << passenger.phoneNumber << "]";
	return output;
}

//Tells if two passengers match by their first and last name.
bool operator==(Passenger& firstPassenger, Passenger& secondPassenger)
{
	bool firstNameMatch = (firstPassenger.firstName == secondPassenger.firstName);
	bool lastNameMatch = (firstPassenger.lastName == secondPassenger.lastName);
	bool sameName = (firstNameMatch && lastNameMatch);
	return sameName;
}

//Tells if two passengers don't match by their first and last name.
bool operator!=(Passenger& firstPassenger, Passenger& secondPassenger)
{
	bool samePerson = (firstPassenger == secondPassenger);
	return (!samePerson);
}

//Tells if a passenger lastName is smaller (closer to a) than another passengers.
bool operator<(Passenger& firstPassenger, Passenger& secondPassenger)
{
	return (firstPassenger.lastName < secondPassenger.lastName);
}

//Tells if a passenger lastName is larger (closer to a) than another passengers.
bool operator>(Passenger& firstPassenger, Passenger& secondPassenger)
{
	return (firstPassenger.lastName > secondPassenger.lastName);
}

//Deletes Passenger
Passenger::~Passenger()
{
	firstName = "";
	lastName = "";
	address = "";
	phoneNumber = "";
}

