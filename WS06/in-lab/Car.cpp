// Name:                Janah Vitalicio
// Date of completion:  October 31, 2019

#include <iostream>
#include <iomanip>
#include <regex>

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
		std::string tempCar;
		std::getline(is, tempCar);

		std::size_t pos = tempCar.find(",");
		tempCar.erase(0, pos + 1);
		
		pos = tempCar.find(",");
		mMaker = tempCar.substr(0, pos);
		mMaker = std::regex_replace(mMaker, std::regex("^ +| +$|( ) +"), "");
		tempCar.erase(0, pos + 1);

		pos = tempCar.find(",");
		mCondition = tempCar.substr(0, pos);
		mCondition = std::regex_replace(mCondition, std::regex("^ +| +$|( ) +"), "");
		tempCar.erase(0, pos + 1);
		std::cout << "tempCar: " << tempCar << std::endl;
		// Validate mCondition
		if (mCondition != "n" && mCondition != "u" && mCondition != "b") {
			mCondition = "";
		}

		std::string tempSpeed = "";
		tempSpeed = tempCar.substr(0);
		tempSpeed = std::regex_replace(tempSpeed, std::regex("^ +| +$|( ) +"), "");
		
		// Validate mTopSpeed
		if (!(isNumber(tempSpeed))) {
			mTopSpeed = 0;
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
		if (mCondition == "n") {
			return "new";
		}
		else if (mCondition == "u") {
			return "used";
		}
		else {
			return "broken";
		}
	}

	double Car::topSpeed() const {
		return mTopSpeed;
	}

	void Car::display(std::ostream& out) const {
		out << "| " << std::setw(10) << std::right << mMaker
			<< " | " << std::setw(6) << std::left << this->condition()
			<< " | " << std::setw(6) << std::fixed << std::setprecision(2) << mTopSpeed
			<< " |";
	}

	std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
		v.display(os);
		return os;
	}
}