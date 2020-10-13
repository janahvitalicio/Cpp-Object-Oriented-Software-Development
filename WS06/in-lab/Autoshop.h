// Name:                Janah Vitalicio
// Date of completion:  October 31, 2019

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>

#include "Vehicle.h"

namespace sdds {

	class Autoshop {

		std::vector<Vehicle*> m_vehicles; // Stores all the vehicles available at this autoshop

	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
	};
}

#endif