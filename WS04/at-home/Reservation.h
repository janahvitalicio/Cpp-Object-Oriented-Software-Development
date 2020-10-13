// Name:                Janah Vitalicio
// Date of completion:  October 7, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>


namespace sdds {

	class Reservation {

		std::string mReservationID;
		std::string mName;
		std::string mEmail;
		int mNumPeople;
		int mDay;
		int mHour;

	public:
		Reservation();
		Reservation(const std::string& m_res);
		std::string getResID() const;
		bool operator==(const Reservation&);
		friend std::ostream& operator<<(std::ostream&, Reservation);
	};


}

#endif // !SDDS_RESERVATION_H
