//============================================================================
// Name        : DeltaAirLines.h
// Author      : Jordan Betcher
// Date	       : 10/23/2017
// Description : DeltaAirLines header dealing with passengers
//============================================================================

#ifndef DELTAAIRLINES_H_
#define DELTAAIRLINES_H_

#include <iostream>
#include <map>
#include "OrderedLinkedList.h"
#include "Passenger.h"
#include <string>
#include <list>

class DeltaAirLines
{
	private:
		map<string, OrderedLinkedList<Passenger>> mFlights;
		std::list<std::string> mFlightNumbers;
		static Passenger msStaticPassenger;
	public:
		DeltaAirLines(std::list<std::string> flightNumbers);
		void addPassenger();
		void searchForPassenger();
		void deletePassenger();
		void listPassengers();
		std::string getValidInput(std::string prompt, bool isValid(std::string));
		virtual ~DeltaAirLines();
};

#endif /* DELTAAIRLINES_H_ */
