// Name:                Janah Vitalicio
// Date of completion:  October 31, 2019

#include <vector>

#include "Autoshop.h"
#include "Car.h"

namespace sdds {

	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl
			<< "| Cars in the autoshop!        |" << std::endl
			<< "--------------------------------" << std::endl;

		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
			(*it)->display(out);
			out << std::endl;
		}

		out << "--------------------------------" << std::endl;
	}
}