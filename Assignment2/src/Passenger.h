/*
 * Passenger.h
 *
 *  Created on: Oct 18, 2017
 *      Author: Betcher
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <string>

class Passenger
{
	private:

		bool isStringEmpty(std::string stringToCheck);
	public:
		std::string firstName;
		std::string lastName;
		std::string address;
		std::string phoneNumber;

		Passenger();
		Passenger(std::string firstName, std::string lastName);
		Passenger(std::string firstName, std::string lastName, std::string address, std::string phoneNumber);

		static bool isNumberInString(std::string stringToCheck);
		static bool isValidFirstName(std::string possibleFirstName);
		static bool isValidLastName(std::string possibleLastName);
		static bool isValidAddress(std::string possibleAddress);
		static bool isValidPhoneNumber(std::string possiblePhoneNumber);

		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setAddress(std::string address);
		void setPhoneNumber(std::string phoneNumber);

		std::string getFirstName();
		std::string getLastName();
		std::string getAddress();
		std::string getPhoneNumber();

		bool isFirstNameEmpty();
		bool isLastNameEmpty();
		bool isAddressEmpty();
		bool isPhoneNumberEmpty();

		friend std::ostream& operator<<(std::ostream& output, Passenger& passenger);
		friend bool operator ==(Passenger& firstPassenger, Passenger& secondPassenger);
		friend bool operator !=(Passenger& firstPassenger, Passenger& secondPassenger);
		friend bool operator >(Passenger& firstPassenger, Passenger& secondPassenger);
		friend bool operator <(Passenger& firstPassenger, Passenger& secondPassenger);

		virtual ~Passenger();
};

#endif /* PASSENGER_H_ */
