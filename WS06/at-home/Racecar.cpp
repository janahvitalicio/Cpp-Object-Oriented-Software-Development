// Name:                Janah Vitalicio
// Date of completion:  November 4, 2019

#include <iostream>
#include <regex>

#include "Racecar.h"

namespace sdds {

	Racecar::Racecar(std::istream& in) : Car(in) {
		std::string temp;
		std::getline(in, temp);
		std::string tempBooster = "";
		tempBooster = temp.substr(0);
		tempBooster = std::regex_replace(tempBooster, std::regex("^ +| +$|( ) +"), "");
		m_booster = std::stod(tempBooster);

	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (m_booster + 1);
	}
}