// Name:                Janah Vitalicio
// Date of completion:  November 4, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

namespace sdds {

	class Racecar : public Car {
		double m_booster = 0.0;

	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};

}

#endif
