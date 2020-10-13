// Name:                Janah Vitalicio
// Date of completion:  November 4, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds {

	class Car : public Vehicle {
		std::string mMaker;
		std::string mCondition;
		double mTopSpeed;

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