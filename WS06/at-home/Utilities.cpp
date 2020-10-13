// Name:                Janah Vitalicio
// Date of completion:  November 4, 2019

#include <sstream>

#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		std::string temp;
		char tag = '\0';
		char delimeter = '\0';
		std::getline(in, temp);
		std::stringstream ss(temp);
		ss >> tag >> delimeter;

		if (ss) {
			if (tag == 'c' || tag == 'C') {
				return new Car(ss);
			}
			else if (tag == 'r' || tag == 'R') {
				return new Racecar(ss);
			}
			else {
				throw tag;
				return nullptr;
			}
		}
		return nullptr;
	}

}