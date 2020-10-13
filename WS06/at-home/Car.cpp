// Name:                Janah Vitalicio
// Date of completion:  November 4, 2019


#include <iostream>
#include <iomanip>
#include <regex>
#include <sstream>

#include "Car.h"

namespace sdds {

	Car::Car() {
		mMaker = "";
		mCondition = "";
		mTopSpeed = 0.0;
	}

	/* This constructor should be able to read a single record from the stream,
	 * extract all the information about a single car and store it in the attributes.
	 */
	Car::Car(std::istream& is) {
		std::getline(is, mMaker, ',');
		mMaker = std::regex_replace(mMaker, std::regex("^ +| +$|( ) +"), "");

		std::string tempCondition = "";
		std::getline(is, tempCondition, ',');
		mCondition = std::regex_replace(tempCondition, std::regex("^ +| +$|( ) +"), "");
		
		// Validate mCondition
		if (mCondition == "n" || mCondition == "") {
			mCondition = "new";
		}
		else if (mCondition == "u") {
			mCondition = "used";
		}
		else if (mCondition == "b") {
			mCondition = "broken";
		}
		else {
			mCondition = "";
			throw "Invalid record!";
		}

		std::string tempSpeed = "";
		std::getline(is, tempSpeed, ',');
		tempSpeed = std::regex_replace(tempSpeed, std::regex("^ +| +$|( ) +"), "");
		
		// Validate mTopSpeed
		if (!(isNumber(tempSpeed))) {
			mTopSpeed = 0;
			throw "Invalid record!";
		}
		else {
			mTopSpeed = std::stod(tempSpeed);
		}

	}

	bool Car::isNumber(std::string s)
	{
		for (size_t i = 0; i < s.length(); i++) {
			if (std::isdigit(s[i]) == false) {
				return false;
			}
		}

		return true;
	}

	std::string Car::condition() const {
		return mCondition;
	}

	double Car::topSpeed() const {
		return mTopSpeed;
	}

	void Car::display(std::ostream& out) const {
		out << "| " << std::setw(10) << std::right << mMaker
			<< " | " << std::setw(6) << std::left << this->condition()
			<< " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed()
			<< " |";
	}

	std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
		v.display(os);
		return os;
	}
}