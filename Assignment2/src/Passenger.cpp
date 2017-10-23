/*
 * Passenger.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: Betcher
 */

#include "Passenger.h"
#include <iostream>

Passenger::Passenger()
{
	this->firstName = "";
	this->lastName = "";
	this->address = "";
	this->phoneNumber = "";
}

Passenger::Passenger(std::string firstName, std::string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = "";
	this->phoneNumber = "";
}

Passenger::Passenger(std::string firstName, std::string lastName, std::string address, std::string phoneNumber)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = address;
	this->phoneNumber = phoneNumber;
}

bool Passenger::isNumberInString(std::string subjectString)
{
	int size = subjectString.size();
	for(int i = 0; i < size; i++)
	{
		char letter = subjectString[i];

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

bool Passenger::isValidFirstName(std::string possibleFirstName)
{
	return !isNumberInString(possibleFirstName);
}

bool Passenger::isValidLastName(std::string possibleLastName)
{
	return !isNumberInString(possibleLastName);
}

bool Passenger::isValidAddress(std::string possibleAddress)
{
	//The instructions don't call for address to be checked
	return true;
}

bool Passenger::isValidPhoneNumber(std::string possiblePhoneNumber)
{
	//The instructions don't call for phoneNumber to be checked
	return true;
}

void Passenger::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Passenger::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Passenger::setAddress(std::string address)
{
	this->address = address;
}

void Passenger::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

std::string Passenger::getFirstName()
{
	return this->firstName;
}

std::string Passenger::getLastName()
{
	return this->lastName;
}

std::string Passenger::getAddress()
{
	return this->address;
}

std::string Passenger::getPhoneNumber()
{
	return this->phoneNumber;
}

bool Passenger::isStringEmpty(std::string subjectString)
{
	if(subjectString.empty())
	{
		return true;
	}
	else if(subjectString.size() <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Passenger::isFirstNameEmpty()
{
	return isStringEmpty(this->firstName);
}

bool Passenger::isLastNameEmpty()
{
	return isStringEmpty(this->lastName);
}

bool Passenger::isAddressEmpty()
{
	return isStringEmpty(this->address);
}

bool Passenger::isPhoneNumberEmpty()
{
	return isStringEmpty(this->phoneNumber);
}

std::ostream& operator<<(std::ostream& output, Passenger& passenger)
{
	output << passenger.firstName << " " << passenger.lastName << " " << "[" << passenger.address << "]" << " "<< "[" << passenger.phoneNumber << "]";
	return output;
}

bool operator==(Passenger& firstPassenger, Passenger& secondPassenger)
{
	bool firstNameMatch = (firstPassenger.firstName == secondPassenger.firstName);
	bool lastNameMatch = (firstPassenger.lastName == secondPassenger.lastName);
	bool sameName = (firstNameMatch && lastNameMatch);
	return sameName;
}

bool operator!=(Passenger& firstPassenger, Passenger& secondPassenger)
{
	bool samePerson = (firstPassenger == secondPassenger);
	return (!samePerson);
}

Passenger::~Passenger()
{
	firstName = "";
	lastName = "";
	address = "";
	phoneNumber = "";
}

