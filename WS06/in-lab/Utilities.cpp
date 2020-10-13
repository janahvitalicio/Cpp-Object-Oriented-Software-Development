// Name:                Janah Vitalicio
// Date of completion:  October 31, 2019

#include <sstream>

#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		char tag;
		in >> tag;

		if (tag == 'c' || tag == 'C') {
			return new Car(in);
		}
		else {
			return nullptr;
		}
	}

}