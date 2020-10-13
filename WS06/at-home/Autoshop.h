// Name:                Janah Vitalicio
// Date of completion:  November 4, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>

#include "Vehicle.h"

namespace sdds {

	class Autoshop {

		std::vector<Vehicle*> m_vehicles; // Stores all the vehicles available at this autoshop

	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
				if (test(*it)) {
					vehicles.push_back(*it);
				}
			}
		}
	};
}

#endif