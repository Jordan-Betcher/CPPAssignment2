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

		bool isStringEmpty(std::string);
	public:
		std::string firstName;
		std::string lastName;
		std::string address;
		std::string phoneNumber;

		Passenger();
		Passenger(std::string, std::string);
		Passenger(std::string, std::string, std::string, std::string);

		static bool isNumberInString(std::string);
		static bool isValidFirstName(std::string);
		static bool isValidLastName(std::string);
		static bool isValidAddress(std::string);
		static bool isValidPhoneNumber(std::string);

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

		friend std::ostream& operator<<(std::ostream&, Passenger&);
		friend bool operator ==(Passenger&, Passenger&);
		friend bool operator !=(Passenger&, Passenger&);
		friend bool operator >(Passenger&, Passenger&);
		friend bool operator <(Passenger&, Passenger&);

		virtual ~Passenger();
};

#endif /* PASSENGER_H_ */
