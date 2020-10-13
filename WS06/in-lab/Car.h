// Name:                Janah Vitalicio
// Date of completion:  October 31, 2019

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>

#include "Vehicle.h"

namespace sdds {

	class Car : public Vehicle {
		std::string mMaker;
		std::string mCondition;
		double mTopSpeed;
		static int counter;
		static int position;

	public:
		Car();
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		bool isNumber(std::string s);
	};

	std::ostream& operator<<(std::ostream& os, const Vehicle& v);
}

#endif