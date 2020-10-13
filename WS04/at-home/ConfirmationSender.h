// Name:                Janah Vitalicio
// Date of completion:  October 7, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

namespace sdds {

	class ConfirmationSender {

		Reservation** ppReservationCS;
		size_t mNumReservations;

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		~ConfirmationSender();

		bool isEmpty();
		void emptyMemory();

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);
	};


}

#endif // !SDDS_CONFIRMATIONSENDER_H