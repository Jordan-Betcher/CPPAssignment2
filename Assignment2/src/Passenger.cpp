/*
 * Passenger.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: Betcher
 */

#include "Passenger.h"

Passenger::Passenger()
{
	// TODO Auto-generated constructor stub
	
}

bool Passenger::containsNumber(std::string subjectString)
{
	for(int i = 0; i < subjectString.size(); i++)
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
	return containsNumber(possibleFirstName);
}

bool Passenger::isValidLastName(std::string possibleLastName)
{
	return containsNumber(possibleLastName);
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

Passenger::~Passenger()
{
	firstName = "";
	lastName = "";
	address = "";
	phoneNumber = "";
}

