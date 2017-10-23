/*
 * DeltaAirLines.h
 *
 *  Created on: Oct 23, 2017
 *      Author: Betcher
 */

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
		Passenger mStaticPassenger;
	public:
		DeltaAirLines(std::list<std::string>);
		void addPassenger();
		void searchForPassenger();
		void deletePassenger();
		void listPassengers();
		std::string getValidInput(std::string, bool isValid(std::string));
		virtual ~DeltaAirLines();
};

#endif /* DELTAAIRLINES_H_ */
