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
		std::string firstName;
		std::string lastName;
		std::string address;
		std::string phoneNumber;

		bool isNumberInString(std::string);
		bool isStringEmpty(std::string);
	public:
		Passenger();

		bool isValidFirstName(std::string);
		bool isValidLastName(std::string);
		bool isValidAddress(std::string);
		bool isValidPhoneNumber(std::string);

		void setFirstName(std::string);
		void setLastName(std::string);
		void setAddress(std::string);
		void setPhoneNumber(std::string);

		std::string getFirstName();
		std::string getLastName();
		std::string getAddress();
		std::string getPhoneNumber();

		bool isFirstNameEmpty();
		bool isLastNameEmpty();
		bool isAddressEmpty();
		bool isPhoneNumberEmpty();

		friend std::ostream& operator<<(std::ostream& output, Passenger& point);

		virtual ~Passenger();
};

#endif /* PASSENGER_H_ */
