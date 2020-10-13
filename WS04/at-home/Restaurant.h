// Name:                Janah Vitalicio
// Date of completion:  October 7, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace sdds {

	class Restaurant {
		Reservation* pReservation;
		size_t mNumReservation;

	public:
		Restaurant();
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		Restaurant(Reservation* reservations[], size_t cnt);

		Restaurant(Restaurant&&);
		Restaurant& operator=(Restaurant&&);

		size_t size() const;

		~Restaurant();

		friend std::ostream& operator<<(std::ostream& os, Restaurant rs);
	};
}

#endif // !SDDS_RESTAURANT_H