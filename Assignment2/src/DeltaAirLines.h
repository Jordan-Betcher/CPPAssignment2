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
		map<string, OrderedLinkedList<Passenger>> flights;
		std::list<std::string> flightNumbers;
		Passenger staticPassenger;
	public:
		DeltaAirLines(std::list<std::string>);
		void addAction();
		void searchAction();
		void deleteAction();
		void listAction();
		std::string getInput(std::string, bool isValid(std::string));
		virtual ~DeltaAirLines();
};

#endif /* DELTAAIRLINES_H_ */
